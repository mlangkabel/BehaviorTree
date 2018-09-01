#include "CppUnitTest.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/Task.h"
#include "utility/TextAccess.h"
#include "UtilityTest.h"

namespace BehaviorTree
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ActionCheckVariableEqualsTests)
	{
	public:
		TEST_METHOD(TestActionCheckVariableEqualsFailsOnEmptyBlackboard)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<CHECK_VARIABLE_EQUALS name=\"variable\" value=\"42\"/>"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_FAILURE, status);
		}

		TEST_METHOD(TestActionCheckVariableEqualsFailsOnBlackboardWithDifferentVariable)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<CHECK_VARIABLE_EQUALS name=\"variable\" value=\"42\"/>"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			blackboard->set("different_variable", 42);
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_FAILURE, status);
		}

		TEST_METHOD(TestActionCheckVariableEqualsFailsOnBlackboardWithDifferentValue)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<CHECK_VARIABLE_EQUALS name=\"variable\" value=\"23\"/>"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			blackboard->set("variable", 42);
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_FAILURE, status);
		}

		TEST_METHOD(TestActionCheckVariableEqualsSucceedsOnBlackboardWithMatchingVariable)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<CHECK_VARIABLE_EQUALS name=\"variable\" value=\"42\"/>"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			blackboard->set("variable", 42);
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_SUCCESS, status);
		}
	};
}
