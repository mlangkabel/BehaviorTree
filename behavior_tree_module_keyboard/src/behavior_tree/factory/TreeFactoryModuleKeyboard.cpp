#include "behavior_tree/factory/TreeFactoryModuleKeyboard.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/ActionSimulateKeyDown.h"
#include "behavior_tree/task/ActionSimulateKeyUp.h"

namespace BehaviorTree
{
	extern "C" void registerModule(std::shared_ptr<TreeFactory> factory)
	{
		factory->addModule(std::make_shared<TreeFactoryModuleKeyboard>());
	}

	TreeFactoryModuleKeyboard::TreeFactoryModuleKeyboard()
	{
		addFactory(std::make_shared<ActionFactorySimulateKeyDown>());
		addFactory(std::make_shared<ActionFactorySimulateKeyUp>());
	}
}
