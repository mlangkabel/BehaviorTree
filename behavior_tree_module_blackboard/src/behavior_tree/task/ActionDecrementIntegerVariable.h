#ifndef ACTION_DECREMENT_INTEGER_VARIABLE_H
#define ACTION_DECREMENT_INTEGER_VARIABLE_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

class ActionDecrementIntegerVariable;

class ActionFactoryDecrementIntegerVariable : public TaskFactory<ActionDecrementIntegerVariable, std::string>
{
public:
	ActionFactoryDecrementIntegerVariable()
		: TaskFactory<ActionDecrementIntegerVariable, std::string>("DECREMENT_INTEGER_VARIABLE", "name")
	{}
};

class ActionDecrementIntegerVariable : public Action
{
public:
	ActionDecrementIntegerVariable(const std::string& name);

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	const std::string m_name;
};

#endif // ACTION_DECREMENT_INTEGER_VARIABLE_H
