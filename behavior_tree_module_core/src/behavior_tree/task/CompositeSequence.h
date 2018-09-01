#ifndef COMPOSITE_SEQUENCE_H
#define COMPOSITE_SEQUENCE_H

#include <memory>
#include <vector>

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Composite.h"

namespace BehaviorTree
{
	class CompositeSequence;

	class CompositeFactorySequence : public TaskFactory<CompositeSequence>
	{
	public:
		CompositeFactorySequence()
			: TaskFactory<CompositeSequence>("SEQUENCE")
		{}
	};

	class CompositeSequence : public Composite
	{
	public:
		CompositeSequence();

		virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);
	};
}

#endif // COMPOSITE_SEQUENCE_H
