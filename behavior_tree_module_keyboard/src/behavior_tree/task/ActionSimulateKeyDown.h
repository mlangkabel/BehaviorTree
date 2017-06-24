#ifndef ACTION_SIMULATE_KEY_DOWN_H
#define ACTION_SIMULATE_KEY_DOWN_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionSimulateKeyDown;

class ActionFactorySimulateKeyDown : public TaskFactory<ActionSimulateKeyDown, int>
{
public:
	ActionFactorySimulateKeyDown()
		: TaskFactory<ActionSimulateKeyDown, int>("SIMULATE_KEY_DOWN", "keycode")
	{}
};

/*
keycodes map according to this table: https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
*/
class ActionSimulateKeyDown : public Action
{
public:
	ActionSimulateKeyDown(const int keycode);
	virtual ~ActionSimulateKeyDown();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const int m_keycode;
};

#endif // ACTION_SIMULATE_KEY_DOWN_H
