#include "behavior_tree/task/ActionSetStringVariable.h"

ActionSetStringVariable::ActionSetStringVariable(const std::string& name, const std::string& value)
	: m_name(name)
	, m_value(value)
{
}

Task::StatusType ActionSetStringVariable::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	blackboard->set(m_name, m_value);
	return STATUS_SUCCESS;
}
