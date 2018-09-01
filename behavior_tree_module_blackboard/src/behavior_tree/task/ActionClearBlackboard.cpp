#include "behavior_tree/task/ActionClearBlackboard.h"

ActionClearBlackboard::ActionClearBlackboard()
{
}

Task::StatusType ActionClearBlackboard::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	blackboard->clear(false);
	return STATUS_SUCCESS;
}
