#include "behavior_tree/task/ActionLogWarning.h"

#include "Utility/Logging/logging.h"

ActionLogWarning::ActionLogWarning(const std::string &message)
	: m_message(message)
{
}

ActionLogWarning::~ActionLogWarning()
{
}

Task::StatusType ActionLogWarning::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	LOG_WARNING(m_message);
	return STATUS_SUCCESS;
}
