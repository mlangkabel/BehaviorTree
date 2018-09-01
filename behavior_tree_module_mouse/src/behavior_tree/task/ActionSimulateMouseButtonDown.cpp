#include "behavior_tree/task/ActionSimulateMouseButtonDown.h"

#include <Windows.h>

ActionSimulateMouseButtonDown::ActionSimulateMouseButtonDown(const int buttonId)
	: m_buttonId(buttonId)
{
}

Task::StatusType ActionSimulateMouseButtonDown::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	switch (m_buttonId)
	{
	case 0:
		input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		break;
	case 1:
		input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		break;
	case 2:
		input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
		break;
	default:
		input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		break;
	}
	SendInput(1, &input, sizeof(INPUT));

	return STATUS_SUCCESS;
}
