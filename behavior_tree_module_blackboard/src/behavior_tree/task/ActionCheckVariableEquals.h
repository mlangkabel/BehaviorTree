#ifndef ACTION_CHECK_VARIABLE_EQUALS_H
#define ACTION_CHECK_VARIABLE_EQUALS_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionCheckVariableEquals;

class ActionFactoryCheckVariableEquals : public TaskFactory<ActionCheckVariableEquals, std::string, std::string>
{
public:
	ActionFactoryCheckVariableEquals()
		: TaskFactory<ActionCheckVariableEquals, std::string, std::string>("CHECK_VARIABLE_EQUALS", "name", "value")
	{}
};

class ActionCheckVariableEquals : public Action
{
public:
	ActionCheckVariableEquals(const std::string& name, const std::string& value);
	virtual ~ActionCheckVariableEquals();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const std::string m_name;
	const std::string m_value;
};

#endif // ACTION_CHECK_VARIABLE_EXISTS_H
