#include "CppUnitTest.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/Task.h"
#include "utility/logging/LogManager.h"
#include "utility/logging/StringLogger.h"
#include "utility/TextAccess.h"

namespace behavior_tree_test
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ActionLogWarningTests)
	{
	public:
		TEST_METHOD(TestActionLogWarningWritesMessageToLogger)
		{
			std::shared_ptr<StringLogger> stringLogger = std::make_shared<StringLogger>();
			LogManager::getInstance()->addLogger(stringLogger);

			std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
				"<BEHAVIOR_SPECIFICATION>"
				"	<MODULES>"
				"		<MODULE name=\"core\" />"
				"		<MODULE name=\"logging\" />"
				"	</MODULES>"
				"	<TREES>"
				"		<ROOT name=\"main\">"
				"			<LOG_WARNING message=\"test warning\" />"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			treeFactory->createBehaviorTree("main")->evaluate(std::make_shared<Blackboard>());

			LogManager::destroyInstance();

			Assert::AreEqual("WARNING: test warning\n", stringLogger->getLogString().c_str(), false, L"cool", LINE_INFO());
		}
	};
}
