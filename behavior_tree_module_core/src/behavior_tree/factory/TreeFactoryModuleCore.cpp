#include "behavior_tree/factory/TreeFactoryModuleCore.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/DecoratorRoot.h"
#include "behavior_tree/task/CompositeSelector.h"
#include "behavior_tree/task/CompositeSequence.h"

namespace BehaviorTree
{
	extern "C" void registerModule(std::shared_ptr<TreeFactory> factory)
	{
		factory->addModule(std::make_shared<TreeFactoryModuleCore>());
	}

	TreeFactoryModuleCore::TreeFactoryModuleCore()
	{
		addFactory(std::make_shared<DecoratorFactoryRoot>());
		addFactory(std::make_shared<CompositeFactorySelector>());
		addFactory(std::make_shared<CompositeFactorySequence>());
	}
}
