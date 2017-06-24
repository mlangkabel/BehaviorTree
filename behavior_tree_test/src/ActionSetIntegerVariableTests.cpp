#include "CppUnitTest.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/Task.h"
#include "utility/logging/LogManager.h"
#include "utility/logging/StringLogger.h"
#include "utility/TextAccess.h"
#include "UtilityTest.h"

namespace behavior_tree_test
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ActionSetIntegerVariableTests)
	{
	public:
		TEST_METHOD(TestActionSetIntegerVariableWritesValueToEmptyBlackboard)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<SET_INTEGER_VARIABLE name=\"integer\" value=\"42\" />"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_SUCCESS, status);
			Assert::IsTrue(blackboard->exists("integer"));

			int value = 0;
			blackboard->get<int>("integer", value);
			Assert::AreEqual(42, value, false);
		}

		TEST_METHOD(TestActionSetIntegerVariableUpdatesExistingValueOnBlackboard)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<SEQUENCE>"
				"				<SET_INTEGER_VARIABLE name=\"integer\" value=\"42\" />"
				"				<SET_INTEGER_VARIABLE name=\"integer\" value=\"23\" />"
				"			</SEQUENCE>"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_SUCCESS, status);
			Assert::IsTrue(blackboard->exists("integer"));

			int value = 0;
			blackboard->get<int>("integer", value);
			Assert::AreEqual(23, value, false);
		}
	};
}
