#include "behavior_tree/task/ActionDecrementIntegerVariable.h"

ActionDecrementIntegerVariable::ActionDecrementIntegerVariable(const std::string& name)
	: m_name(name)
{
}

Task::StatusType ActionDecrementIntegerVariable::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	if (blackboard->exists(m_name))
	{
		int value = 0;
		if (blackboard->get(m_name, value))
		{
			value--;
			blackboard->set(m_name, value);
			return STATUS_SUCCESS;
		}
	}
	return STATUS_FAILURE;
}
