#ifndef ACTION_SET_INTEGER_VARIABLE_H
#define ACTION_SET_INTEGER_VARIABLE_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionSetIntegerVariable;

class ActionFactorySetIntegerVariable : public TaskFactory<ActionSetIntegerVariable, std::string, int>
{
public:
	ActionFactorySetIntegerVariable()
		: TaskFactory<ActionSetIntegerVariable, std::string, int>("SET_INTEGER_VARIABLE", "name", "value")
	{}
};

class ActionSetIntegerVariable : public Action
{
public:
	ActionSetIntegerVariable(const std::string& name, const int value);

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const std::string m_name;
	const int m_value;
};

#endif // ACTION_SET_INTEGER_VARIABLE_H
