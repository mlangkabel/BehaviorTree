#include "behavior_tree/task/ActionIncrementIntegerVariable.h"

namespace BehaviorTree
{
	ActionIncrementIntegerVariable::ActionIncrementIntegerVariable(const std::string& name)
		: m_name(name)
	{
	}

	Task::StatusType ActionIncrementIntegerVariable::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		if (blackboard->exists(m_name))
		{
			int value = 0;
			if (blackboard->get(m_name, value))
			{
				value++;
				blackboard->set(m_name, value);
				return STATUS_SUCCESS;
			}
		}
		return STATUS_FAILURE;
	}
}
