#include "behavior_tree/task/Decorator.h"

Decorator::Decorator()
	: Task(1)
{
}

Decorator::~Decorator()
{
}
		
void Decorator::setChild(std::shared_ptr<Task> child)
{
	m_child = child;
}
