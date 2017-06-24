#include "behavior_tree/task/ActionLogError.h"

#include "Utility/Logging/logging.h"

ActionLogError::ActionLogError(const std::string &message)
	: m_message(message)
{
}

ActionLogError::~ActionLogError()
{
}

Task::StatusType ActionLogError::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	LOG_ERROR(m_message);
	return STATUS_SUCCESS;
}
