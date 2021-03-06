#include "behavior_tree/task/ActionSimulateMouseButtonUp.h"

#include <Windows.h>

namespace BehaviorTree
{
	ActionSimulateMouseButtonUp::ActionSimulateMouseButtonUp(const int buttonId)
		: m_buttonId(buttonId)
	{
	}

	Task::StatusType ActionSimulateMouseButtonUp::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		INPUT input = { 0 };
		input.type = INPUT_MOUSE;
		switch (m_buttonId)
		{
		case 0:
			input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			break;
		case 1:
			input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
			break;
		case 2:
			input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
			break;
		default:
			input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			break;
		}
		SendInput(1, &input, sizeof(INPUT));

		return STATUS_SUCCESS;
	}
}
