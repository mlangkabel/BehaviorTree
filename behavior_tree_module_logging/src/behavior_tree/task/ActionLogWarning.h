#ifndef ACTION_LOG_WARNING_H
#define ACTION_LOG_WARNING_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionLogWarning;

class ActionFactoryLogWarning : public TaskFactory<ActionLogWarning, std::string>
{
public:
	ActionFactoryLogWarning()
		: TaskFactory<ActionLogWarning, std::string>("LOG_WARNING", "message")
	{}
};

class ActionLogWarning : public Action
{
public:
	ActionLogWarning(const std::string &message);
	virtual ~ActionLogWarning();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const std::string m_message;
};

#endif // ACTION_LOG_WARNING_H
