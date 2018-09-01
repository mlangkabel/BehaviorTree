#ifndef COMPOSITE_SELECTOR_H
#define COMPOSITE_SELECTOR_H

#include <memory>
#include <vector>

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Composite.h"

class CompositeSelector;

class CompositeFactorySelector : public TaskFactory<CompositeSelector>
{
public:
	CompositeFactorySelector()
		: TaskFactory<CompositeSelector>("SELECTOR")
	{}
};

class CompositeSelector : public Composite
{
public:
	CompositeSelector();

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);
};

#endif // COMPOSITE_SELECTOR_H
