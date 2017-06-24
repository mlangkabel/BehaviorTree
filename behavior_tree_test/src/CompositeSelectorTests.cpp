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

	TEST_CLASS(CompositeSelectorTests)
	{
	public:
		TEST_METHOD(TestCompositeSelectorReturnsFailureWhenEmpty)
		{
			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<SELECTOR />"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			Task::StatusType status = treeFactory->createBehaviorTree("main")->evaluate(std::make_shared<Blackboard>());
			Assert::AreEqual(Task::STATUS_FAILURE, status);
		}
	};
}
