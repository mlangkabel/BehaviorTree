#ifndef ACTION_LOG_BLACKBOARD_CONTENT_H
#define ACTION_LOG_BLACKBOARD_CONTENT_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionLogBlackboardContent;

class ActionFactoryLogBlackboardContent : public TaskFactory<ActionLogBlackboardContent>
{
public:
	ActionFactoryLogBlackboardContent()
		: TaskFactory<ActionLogBlackboardContent>("LOG_BLACKBOARD_CONTENT")
	{}
};

class ActionLogBlackboardContent : public Action
{
public:
	ActionLogBlackboardContent();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);
};

#endif // ACTION_LOG_BLACKBOARD_CONTENT_H
