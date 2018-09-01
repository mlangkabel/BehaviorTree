#ifndef TASK_H
#define TASK_H

#include "behavior_tree/data/Blackboard.h"

class Task
{
public:
	enum StatusType
	{
		STATUS_FAILURE,
		STATUS_SUCCESS
	};

	virtual ~Task() = default;

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard) = 0;
};

#endif // TASK_H
