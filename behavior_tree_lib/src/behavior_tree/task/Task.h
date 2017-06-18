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

	Task(int allowedChildCount);
	virtual ~Task();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard) = 0;

	int getAllowedChildCount() const;

private:
	const int m_allowedChildCount;
};

#endif // TASK_H
