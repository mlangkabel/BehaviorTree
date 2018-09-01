#include "behavior_tree/factory/TreeFactoryModuleMouse.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/ActionSetMouseCursorPosition.h"
#include "behavior_tree/task/ActionSimulateMouseButtonDown.h"
#include "behavior_tree/task/ActionSimulateMouseButtonUp.h"

namespace BehaviorTree
{
	extern "C" void registerModule(std::shared_ptr<TreeFactory> factory)
	{
		factory->addModule(std::make_shared<TreeFactoryModuleMouse>());
	}

	TreeFactoryModuleMouse::TreeFactoryModuleMouse()
	{
		addFactory(std::make_shared<ActionFactorySetMouseCursorPosition>());
		addFactory(std::make_shared<ActionFactorySimulateMouseButtonDown>());
		addFactory(std::make_shared<ActionFactorySimulateMouseButtonUp>());
	}
}
