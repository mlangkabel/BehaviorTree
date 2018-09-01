#ifndef DECORATOR_ROOT_H
#define DECORATOR_ROOT_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Decorator.h"

namespace BehaviorTree
{
	class DecoratorRoot;

	class DecoratorFactoryRoot : public TaskFactory<DecoratorRoot, std::string>
	{
	public:
		DecoratorFactoryRoot()
			: TaskFactory<DecoratorRoot, std::string>("ROOT", "name")
		{}
	};

	class DecoratorRoot : public Decorator
	{
	public:
		DecoratorRoot(const std::string &name);

		virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

		std::string getName() const;

	private:
		const std::string m_name;
	};
}

#endif // DECORATOR_ROOT_H
