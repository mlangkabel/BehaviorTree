#include "behavior_tree/module_core/TaskRoot.h"

TaskRoot::TaskRoot(const std::string &name)
	: m_name(name)
{
}

TaskRoot::~TaskRoot()
{
}
		
Task::StatusType TaskRoot::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	return m_child->evaluate(blackboard);
}
		
std::string TaskRoot::getName() const
{
	return m_name;
}
