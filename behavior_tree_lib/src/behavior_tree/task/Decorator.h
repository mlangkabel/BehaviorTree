#ifndef DECORATOR_H
#define DECORATOR_H

#include <memory>

#include "behavior_tree/task/Task.h"

class Decorator : public Task
{
public:
	virtual ~Decorator();

	void setChild(std::shared_ptr<Task> child);

protected:
	std::shared_ptr<Task> m_child;
};

#endif // DECORATOR_H
