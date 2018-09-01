#include "behavior_tree/task/ActionSetMouseCursorPosition.h"

#include <Windows.h>

namespace BehaviorTree
{
	ActionSetMouseCursorPosition::ActionSetMouseCursorPosition(const int x, const int y)
		: m_x(x)
		, m_y(y)
	{
	}

	Task::StatusType ActionSetMouseCursorPosition::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		SetCursorPos(m_x, m_y);
		return STATUS_SUCCESS;
	}
}
