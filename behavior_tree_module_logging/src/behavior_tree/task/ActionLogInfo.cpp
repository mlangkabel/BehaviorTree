#include "behavior_tree/task/ActionLogInfo.h"

#include "Utility/Logging/logging.h"

ActionLogInfo::ActionLogInfo(const std::string &message)
	: m_message(message)
{
}

ActionLogInfo::~ActionLogInfo()
{
}

Task::StatusType ActionLogInfo::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	LOG_INFO(m_message);
	return STATUS_SUCCESS;
}