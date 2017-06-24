#ifndef ACTION_SIMULATE_MOUSE_BUTTON_DOWN_H
#define ACTION_SIMULATE_MOUSE_BUTTON_DOWN_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionSimulateMouseButtonDown;

class ActionFactorySimulateMouseButtonDown : public TaskFactory<ActionSimulateMouseButtonDown, int>
{
public:
	ActionFactorySimulateMouseButtonDown()
		: TaskFactory<ActionSimulateMouseButtonDown, int>("SIMULATE_MOUSE_BUTTON_DOWN", "button_id")
	{}
};

class ActionSimulateMouseButtonDown : public Action
{
public:
	ActionSimulateMouseButtonDown(const int buttonId);
	virtual ~ActionSimulateMouseButtonDown();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const int m_buttonId;
};

#endif // ACTION_SIMULATE_MOUSE_BUTTON_DOWN_H
