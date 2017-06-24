#include "behavior_tree/task/ActionCheckVariableEquals.h"

ActionCheckVariableEquals::ActionCheckVariableEquals(const std::string& name, const std::string& value)
	: m_name(name)
	, m_value(value)
{
}

ActionCheckVariableEquals::~ActionCheckVariableEquals()
{
}

Task::StatusType ActionCheckVariableEquals::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	if (blackboard->exists(m_name))
	{
		std::string value = "";
		blackboard->getAsString(m_name, value);
		if (value == m_value)
		{
			return STATUS_SUCCESS;
		}
	}
	return STATUS_FAILURE;
}
