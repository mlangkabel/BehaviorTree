#include "behavior_tree/task/DecoratorRoot.h"

DecoratorRoot::DecoratorRoot(const std::string &name)
	: m_name(name)
{
}

DecoratorRoot::~DecoratorRoot()
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
