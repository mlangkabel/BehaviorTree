#include "behavior_tree/task/ActionLogBlackboardContent.h"

#include "utility/logging/logging.h"

ActionLogBlackboardContent::ActionLogBlackboardContent()
{
}

Task::StatusType ActionLogBlackboardContent::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	LOG_INFO("Blackboard entries:");
	for (const std::string& key : blackboard->getKeys())
	{
		std::string value;
		if (blackboard->getAsString(key, value))
		{
			LOG_INFO("\t" + key + ": \"" + value + "\"");
		}
	}
	return STATUS_SUCCESS;
}
