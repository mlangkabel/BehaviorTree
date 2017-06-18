#include "behavior_tree/task/TaskSequence.h"

TaskSequence::TaskSequence()
{
}

TaskSequence::~TaskSequence()
{
}
		
Task::StatusType TaskSequence::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	StatusType status = STATUS_SUCCESS;
	for (int i = 0; i < m_children.size(); i++)
	{
		status = m_children[i]->evaluate(blackboard);
		if (status == STATUS_FAILURE)
			break;
	}
	return status;
}
