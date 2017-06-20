#ifndef ACTION_LOG_INFO_H
#define ACTION_LOG_INFO_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionLogInfo;

class TaskFactoryLogInfo: public TaskFactory<ActionLogInfo, std::string>
{
public:
	TaskFactoryLogInfo()
		: TaskFactory<ActionLogInfo, std::string>("LOG_INFO", "message")
	{}
};

class ActionLogInfo: public Action
{
public:
	ActionLogInfo(const std::string &message);
	virtual ~ActionLogInfo();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const std::string m_message;
};

#endif // ACTION_LOG_INFO_H
