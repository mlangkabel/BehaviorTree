#ifndef TASK_SEQUENCE_H
#define TASK_SEQUENCE_H

#include <memory>
#include <vector>

#include "behavior_tree/task/Composite.h"
#include "behavior_tree/factory/TaskFactory.h"

class TaskSequence;

class TaskFactorySequence: public TaskFactory<TaskSequence>
{
public:
	TaskFactorySequence()
		: TaskFactory<TaskSequence>("SEQUENCE")
	{}
};
	
class TaskSequence : public Composite
{
public:
	TaskSequence();
	virtual ~TaskSequence();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);
};

#endif // TASK_SEQUENCE_H
