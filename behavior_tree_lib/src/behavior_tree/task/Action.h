#ifndef ACTION_H
#define ACTION_H

#include "behavior_tree/task/Task.h"

namespace BehaviorTree
{
	class Action : public Task
	{
	public:
		virtual ~Action() = default;
	};
}

#endif // ACTION_H
