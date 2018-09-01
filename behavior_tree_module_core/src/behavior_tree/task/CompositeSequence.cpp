#include "behavior_tree/task/CompositeSequence.h"

namespace BehaviorTree
{
	CompositeSequence::CompositeSequence()
	{
	}

	Task::StatusType CompositeSequence::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		StatusType status = STATUS_SUCCESS;
		for (std::shared_ptr<Task> child : m_children)
		{
			status = child->evaluate(blackboard);
			if (status == STATUS_FAILURE)
			{
				break;
			}
		}
		return status;
	}
}
