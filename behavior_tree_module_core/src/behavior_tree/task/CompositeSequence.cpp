#include "behavior_tree/task/CompositeSequence.h"

CompositeSequence::CompositeSequence()
{
}

CompositeSequence::~CompositeSequence()
{
}

Task::StatusType CompositeSequence::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	StatusType status = STATUS_SUCCESS;
	for (size_t i = 0; i < m_children.size(); i++)
	{
		status = m_children[i]->evaluate(blackboard);
		if (status == STATUS_FAILURE)
		{
			break;
		}
	}
	return status;
}
