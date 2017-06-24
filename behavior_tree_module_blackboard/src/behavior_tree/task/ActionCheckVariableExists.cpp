#include "behavior_tree/task/ActionCheckVariableExists.h"

ActionCheckVariableExists::ActionCheckVariableExists(const std::string& name)
	: m_name(name)
{
}

ActionCheckVariableExists::~ActionCheckVariableExists()
{
}

Task::StatusType ActionCheckVariableExists::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	return blackboard->exists(m_name) ? STATUS_SUCCESS : STATUS_FAILURE;
}
