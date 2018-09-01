#include "behavior_tree/task/ActionSetIntegerVariable.h"

namespace BehaviorTree
{
	ActionSetIntegerVariable::ActionSetIntegerVariable(const std::string& name, const int value)
		: m_name(name)
		, m_value(value)
	{
	}

	Task::StatusType ActionSetIntegerVariable::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		blackboard->set(m_name, m_value);
		return STATUS_SUCCESS;
	}
}
