#ifndef TASK_SELECTOR_H
#define TASK_SELECTOR_H

#include <memory>
#include <vector>

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Composite.h"

class TaskSelector;

class TaskFactorySelector: public TaskFactory<TaskSelector>
{
public:
	TaskFactorySelector()
		: TaskFactory<TaskSelector>("SELECTOR")
	{}
};

class TaskSelector: public Composite
{
public:
	TaskSelector();
	virtual ~TaskSelector();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);
};

#endif // TASK_SELECTOR_H
