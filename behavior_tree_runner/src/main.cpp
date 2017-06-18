#include <windows.h>

#include "behavior_tree/data/Blackboard.h"
#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/Task.h"
#include "utility/logging/ConsoleLogger.h"
#include "utility/logging/logging.h"
#include "utility/logging/LogManager.h"
#include "utility/TextAccess.h"

int main()
{
	LogManager::getInstance()->addLogger(std::make_shared<ConsoleLogger>());

	LOG_INFO("Starting up application.");

	std::shared_ptr<TreeFactory> treeFactory = std::make_shared<TreeFactory>(TextAccess::createFromString(
		"<TREES>"
		"	<ROOT name = \"main\">"
		"		<SEQUENCE>"
		"		</SEQUENCE>"
		"	</ROOT>"
		"</TREES>"
	));

	{
		HINSTANCE hGetProcIDDLL = LoadLibrary("behavior_tree_module_core.dll");

		if (!hGetProcIDDLL) {
			LOG_WARNING("could not load the dynamic library");
			return EXIT_FAILURE;
		}

		typedef void(*functionType)(std::shared_ptr<TreeFactory>);

		functionType function = (functionType)GetProcAddress(hGetProcIDDLL, "registerModule");
		if (!function) {
			LOG_WARNING("could not locate the function");
			return EXIT_FAILURE;
		}

		function(treeFactory);
	}

	std::shared_ptr<Task> tree = treeFactory->createBehaviorTree("main");

	std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();

	bool success = tree->evaluate(blackboard);

	LOG_INFO(std::string("Behavior tree evaluation has been ") + (success ? "" : "un") + "successful.");

	LOG_INFO("Shutting down application.");

	return EXIT_SUCCESS;
}

