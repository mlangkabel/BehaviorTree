#include "behavior_tree/task/CompositeSelector.h"

CompositeSelector::CompositeSelector()
{
}

Task::StatusType CompositeSelector::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	StatusType status = STATUS_FAILURE;
	for (std::shared_ptr<Task> child : m_children)
	{
		status = child->evaluate(blackboard);
		if (status == STATUS_SUCCESS)
		{
			break;
		}
	}
	return status;
}
