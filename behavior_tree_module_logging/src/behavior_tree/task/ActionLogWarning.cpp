#include "behavior_tree/task/ActionLogWarning.h"

#include "Utility/Logging/logging.h"

namespace BehaviorTree
{
	ActionLogWarning::ActionLogWarning(const std::string &message)
		: m_message(message)
	{
	}

	Task::StatusType ActionLogWarning::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		LOG_WARNING(m_message);
		return STATUS_SUCCESS;
	}
}
