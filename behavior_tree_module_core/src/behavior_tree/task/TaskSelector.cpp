#include "behavior_tree/task/TaskSelector.h"

TaskSelector::TaskSelector()
{
}

TaskSelector::~TaskSelector()
{
}
		
Task::StatusType TaskSelector::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	StatusType status = STATUS_FAILURE;
	for (int i = 0; i < m_children.size(); i++)
	{
		status = m_children[i]->evaluate(blackboard);
		if (status == STATUS_SUCCESS)
			break;
	}
	return status;
}
