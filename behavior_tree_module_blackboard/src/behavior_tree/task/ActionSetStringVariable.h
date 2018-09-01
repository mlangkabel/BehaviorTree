#ifndef ACTION_SET_STRING_VARIABLE_H
#define ACTION_SET_STRING_VARIABLE_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

namespace BehaviorTree
{
	class ActionSetStringVariable;

	class ActionFactorySetStringVariable : public TaskFactory<ActionSetStringVariable, std::string, std::string>
	{
	public:
		ActionFactorySetStringVariable()
			: TaskFactory<ActionSetStringVariable, std::string, std::string>("SET_STRING_VARIABLE", "name", "value")
		{}
	};

	class ActionSetStringVariable : public Action
	{
	public:
		ActionSetStringVariable(const std::string& name, const std::string& value);

		virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

	private:
		const std::string m_name;
		const std::string m_value;
	};
}

#endif // ACTION_SET_STRING_VARIABLE_H
