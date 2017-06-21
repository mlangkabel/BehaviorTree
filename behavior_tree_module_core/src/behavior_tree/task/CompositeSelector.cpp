#include "behavior_tree/task/CompositeSelector.h"

CompositeSelector::CompositeSelector()
{
}

CompositeSelector::~CompositeSelector()
{
}
		
Task::StatusType CompositeSelector::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	StatusType status = STATUS_FAILURE;
	for (size_t i = 0; i < m_children.size(); i++)
	{
		status = m_children[i]->evaluate(blackboard);
		if (status == STATUS_SUCCESS)
		{
			break;
		}
	}
	return status;
}
