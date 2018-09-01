#include "behavior_tree/task/ActionLogInfo.h"

#include "Utility/Logging/logging.h"

namespace BehaviorTree
{
	ActionLogInfo::ActionLogInfo(const std::string &message)
		: m_message(message)
	{
	}

	Task::StatusType ActionLogInfo::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		LOG_INFO(m_message);
		return STATUS_SUCCESS;
	}
}
