#include "behavior_tree/task/DecoratorRoot.h"

namespace BehaviorTree
{
	DecoratorRoot::DecoratorRoot(const std::string &name)
		: m_name(name)
	{
	}

	Task::StatusType DecoratorRoot::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		return m_child->evaluate(blackboard);
	}

	std::string DecoratorRoot::getName() const
	{
		return m_name;
	}
}
