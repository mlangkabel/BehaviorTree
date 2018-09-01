#include "CppUnitTest.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/Task.h"
#include "utility/logging/LogManager.h"
#include "utility/logging/StringLogger.h"
#include "utility/TextAccess.h"

namespace BehaviorTree
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(ActionLogErrorTests)
	{
	public:
		TEST_METHOD(TestActionLogErrorWritesMessageToLogger)
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
				"			<LOG_ERROR message=\"test error\" />"
				"		</ROOT>"
				"	</TREES>"
				"</BEHAVIOR_SPECIFICATION>"
			));

			treeFactory->createBehaviorTree("main")->evaluate(std::make_shared<Blackboard>());

			LogManager::destroyInstance();

			Assert::AreEqual("ERROR: test error\n", stringLogger->getLogString().c_str(), false);
		}
	};
}
