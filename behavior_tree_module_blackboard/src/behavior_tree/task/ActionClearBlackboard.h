#ifndef ACTION_CLEAR_BLACKBOARD_H
#define ACTION_CLEAR_BLACKBOARD_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionClearBlackboard;

class ActionFactoryClearBlackboard : public TaskFactory<ActionClearBlackboard>
{
public:
	ActionFactoryClearBlackboard()
		: TaskFactory<ActionClearBlackboard>("CLEAR_BLACKBOARD")
	{}
};

class ActionClearBlackboard : public Action
{
public:
	ActionClearBlackboard();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);
};

#endif // ACTION_CLEAR_BLACKBOARD_H
