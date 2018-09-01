#ifndef ACTION_CHECK_VARIABLE_EXISTS_H
#define ACTION_CHECK_VARIABLE_EXISTS_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionCheckVariableExists;

class ActionFactoryCheckVariableExists : public TaskFactory<ActionCheckVariableExists, std::string>
{
public:
	ActionFactoryCheckVariableExists()
		: TaskFactory<ActionCheckVariableExists, std::string>("CHECK_VARIABLE_EXISTS", "name")
	{}
};

class ActionCheckVariableExists : public Action
{
public:
	ActionCheckVariableExists(const std::string& name);

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const std::string m_name;
};

#endif // ACTION_CHECK_VARIABLE_EXISTS_H
