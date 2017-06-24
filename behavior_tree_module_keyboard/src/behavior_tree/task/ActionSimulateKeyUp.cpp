#include "behavior_tree/task/ActionSimulateKeyUp.h"

#include "utility/UtilityKeyboard.h"

ActionSimulateKeyUp::ActionSimulateKeyUp(const int keycode)
	: m_keycode(keycode)
{
}

ActionSimulateKeyUp::~ActionSimulateKeyUp()
{
}

Task::StatusType ActionSimulateKeyUp::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	utility::setKeyUp(m_keycode);
	return STATUS_SUCCESS;
}
