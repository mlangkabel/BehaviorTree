#ifndef TREE_FACTORY_MODULE_BLACKBOARD_H
#define TREE_FACTORY_MODULE_BLACKBOARD_H

#include <memory>

#include "behavior_tree/factory/TreeFactoryModule.h"

namespace BehaviorTree
{
	class TreeFactory;

	extern "C" __declspec(dllexport) void registerModule(std::shared_ptr<TreeFactory>);

	class TreeFactoryModuleBlackboard : public TreeFactoryModule
	{
	public:
		TreeFactoryModuleBlackboard();
	};
}

#endif // TREE_FACTORY_MODULE_BLACKBOARD_H
