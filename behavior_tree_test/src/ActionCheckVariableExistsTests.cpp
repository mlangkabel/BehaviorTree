#include "CppUnitTest.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/Task.h"
#include "utility/TextAccess.h"
#include "UtilityTest.h"

namespace BehaviorTree
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ActionCheckVariableExistsTests)
	{
	public:
		TEST_METHOD(TestActionCheckVariableExistsFailsOnEmptyBlackboard)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<CHECK_VARIABLE_EXISTS name=\"variable\"/>"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_FAILURE, status);
		}

		TEST_METHOD(TestActionCheckVariableExistsFailsOnBlackboardWithDifferentVariable)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<CHECK_VARIABLE_EXISTS name=\"variable\"/>"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();
			blackboard->set("different_variable", 42);
			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(blackboard);

			Assert::AreEqual(Task::STATUS_FAILURE, status);
		}

		TEST_METHOD(TestActionCheckVariableExistsSucceedsOnBlackboardWithMatchingVariable)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"blackboard\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<CHECK_VARIABLE_EXISTS name=\"variable\"/>"
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
