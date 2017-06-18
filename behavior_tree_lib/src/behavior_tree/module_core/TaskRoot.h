#ifndef TASK_ROOT_H
#define TASK_ROOT_H

#include "behavior_tree/task/Decorator.h"
#include "behavior_tree/factory/TaskFactory.h"

class TaskRoot;

class TaskFactoryRoot: public TaskFactory<TaskRoot, std::string>
{
public:
	TaskFactoryRoot()
		: TaskFactory<TaskRoot, std::string>("ROOT", "name")
	{}
};

class TaskRoot : public Decorator
{
public:
	TaskRoot(const std::string &name);
	virtual ~TaskRoot();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

	std::string getName() const;

private:
	const std::string m_name;
};

#endif // TASK_ROOT_H
