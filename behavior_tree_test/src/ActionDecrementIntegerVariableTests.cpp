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

	TEST_CLASS(ActionDecrementIntegerVariableTests)
	{
	public:
		TEST_METHOD(TestActionDecrementIntegerVariableFailsOnEmptyBlackboard)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<DECREMENT_INTEGER_VARIABLE name=\"integer\" />"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_FAILURE, status);
		}

		TEST_METHOD(TestActionDecrementIntegerVariableFailsStringVariable)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<DECREMENT_INTEGER_VARIABLE name=\"var\" />"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			blackboard->set<std::string>("var", "foo");
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_FAILURE, status);
		}

		TEST_METHOD(TestActionDecrementIntegerVariableDecrementsMatchingInteger)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<DECREMENT_INTEGER_VARIABLE name=\"integer\" />"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			blackboard->set("integer", 42);
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_SUCCESS, status);

			int value = 0;
			blackboard->get<int>("integer", value);
			Assert::AreEqual(41, value, false);
		}
	};
}
