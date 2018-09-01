#include "behavior_tree/task/ActionClearBlackboard.h"

namespace BehaviorTree
{
	ActionClearBlackboard::ActionClearBlackboard()
	{
	}

	Task::StatusType ActionClearBlackboard::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		blackboard->clear(false);
		return STATUS_SUCCESS;
	}
}
