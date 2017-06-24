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

	std::shared_ptr<TreeFactory> treeFactory = TreeFactory::create(TextAccess::createFromString(
		"<BEHAVIOR_SPECIFICATION>"
		"	<MODULES>"
		"		<MODULE name=\"core\" />"
		"		<MODULE name=\"mouse\" />"
		"	</MODULES>"
		"	<TREES>"
		"		<ROOT name=\"main\">"
		"			<SEQUENCE>"
		"				<EVALUATE_TREE name=\"log\" />"
		"			</SEQUENCE>"
		"		</ROOT>"
		"		<ROOT name = \"log\">"
		"			<SEQUENCE>"
		"				<SET_MOUSE_CURSOR_POSITION x=\"68\" y=\"68\" />"
		"				<SIMULATE_MOUSE_BUTTON_DOWN button_id=\"0\" />"
		"				<SIMULATE_MOUSE_BUTTON_UP button_id=\"0\" />"
		"			</SEQUENCE>"
		"		</ROOT>"
		"	</TREES>"
		"</BEHAVIOR_SPECIFICATION>"
	));

	std::shared_ptr<Task> tree = treeFactory->createBehaviorTree("main");

	std::shared_ptr<Blackboard> blackboard = std::make_shared<Blackboard>();

	bool success = (tree->evaluate(blackboard) == Task::STATUS_SUCCESS);

	LOG_INFO(std::string("Behavior tree evaluation has been ") + (success ? "" : "un") + "successful.");

	LOG_INFO("Shutting down application.");

	return EXIT_SUCCESS;
}
