#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <memory>
#include <vector>

#include "behavior_tree/task/Task.h"

class Composite: public Task
{
public:
	Composite();
	virtual ~Composite();

	void addChild(std::shared_ptr<Task> child);
	
protected:
	std::vector<std::shared_ptr<Task>> m_children;
};

#endif // COMPOSITE_H
