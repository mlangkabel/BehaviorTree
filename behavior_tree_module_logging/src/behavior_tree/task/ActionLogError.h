#ifndef ACTION_LOG_ERROR_H
#define ACTION_LOG_ERROR_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionLogError;

class ActionFactoryLogError : public TaskFactory<ActionLogError, std::string>
{
public:
	ActionFactoryLogError()
		: TaskFactory<ActionLogError, std::string>("LOG_ERROR", "message")
	{}
};

class ActionLogError : public Action
{
public:
	ActionLogError(const std::string &message);

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const std::string m_message;
};

#endif // ACTION_LOG_ERROR_H
