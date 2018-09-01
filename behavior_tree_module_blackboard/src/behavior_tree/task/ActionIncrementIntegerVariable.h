#ifndef ACTION_INCREMENT_INTEGER_VARIABLE_H
#define ACTION_INCREMENT_INTEGER_VARIABLE_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionIncrementIntegerVariable;

class ActionFactoryIncrementIntegerVariable : public TaskFactory<ActionIncrementIntegerVariable, std::string>
{
public:
	ActionFactoryIncrementIntegerVariable()
		: TaskFactory<ActionIncrementIntegerVariable, std::string>("INCREMENT_INTEGER_VARIABLE", "name")
	{}
};

class ActionIncrementIntegerVariable : public Action
{
public:
	ActionIncrementIntegerVariable(const std::string& name);

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const std::string m_name;
};

#endif // ACTION_INCREMENT_INTEGER_VARIABLE_H
