#include "behavior_tree/task/Decorator.h"

namespace BehaviorTree
{
	void Decorator::setChild(std::shared_ptr<Task> child)
	{
		m_child = child;
	}
}
