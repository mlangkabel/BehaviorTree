#include "behavior_tree/task/Composite.h"

Composite::~Composite()
{
}

void Composite::addChild(std::shared_ptr<Task> child)
{
	m_children.push_back(child);
}
