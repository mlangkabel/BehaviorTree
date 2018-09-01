#include "behavior_tree/task/ActionSimulateKeyDown.h"

#include "utility/UtilityKeyboard.h"

ActionSimulateKeyDown::ActionSimulateKeyDown(const int keycode)
	: m_keycode(keycode)
{
}

Task::StatusType ActionSimulateKeyDown::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	utility::setKeyDown(m_keycode);
	return STATUS_SUCCESS;
}
