#ifndef ACTION_SET_MOUSE_CURSOR_POSITION_H
#define ACTION_SET_MOUSE_CURSOR_POSITION_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionSetMouseCursorPosition;

class ActionFactorySetMouseCursorPosition : public TaskFactory<ActionSetMouseCursorPosition, int, int>
{
public:
	ActionFactorySetMouseCursorPosition()
		: TaskFactory<ActionSetMouseCursorPosition, int, int>("SET_MOUSE_CURSOR_POSITION", "x", "y")
	{}
};

class ActionSetMouseCursorPosition : public Action
{
public:
	ActionSetMouseCursorPosition(const int x, const int y);

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const int m_x;
	const int m_y;
};

#endif // ACTION_SET_MOUSE_CURSOR_POSITION_H
