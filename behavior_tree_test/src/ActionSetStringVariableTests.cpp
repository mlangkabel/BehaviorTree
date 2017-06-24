#include "CppUnitTest.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/Task.h"
#include "utility/TextAccess.h"
#include "UtilityTest.h"

namespace behavior_tree_test
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ActionSetStringVariableTests)
	{
	public:
		TEST_METHOD(TestActionSetStringVariableWritesValueToEmptyBlackboard)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<SET_STRING_VARIABLE name=\"string\" value=\"foo\" />"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_SUCCESS, status);
			Assert::IsTrue(blackboard->exists("string"));

			std::string value = "";
			blackboard->get("string", value);
			Assert::AreEqual("foo", value.c_str(), false);
		}

		TEST_METHOD(TestActionSetStringVariableUpdatesExistingValueOnBlackboard)
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
				"				<SET_STRING_VARIABLE name=\"string\" value=\"foo\" />"
				"				<SET_STRING_VARIABLE name=\"string\" value=\"bar\" />"
				"			</SEQUENCE>"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_SUCCESS, status);
			Assert::IsTrue(blackboard->exists("string"));

			std::string value = "";
			blackboard->get("string", value);
			Assert::AreEqual("bar", value.c_str(), false);
		}
	};
}
