#include "behavior_tree/module_core/TreeFactoryModuleCore.h"

#include "behavior_tree/module_core/TaskRoot.h"
#include "behavior_tree/module_core/TaskSelector.h"
#include "behavior_tree/module_core/TaskSequence.h"

TreeFactoryModuleCore::TreeFactoryModuleCore()
{
	addFactory(std::make_shared<TaskFactoryRoot>());
	addFactory(std::make_shared<TaskFactorySelector>());
	addFactory(std::make_shared<TaskFactorySequence>());
}

TreeFactoryModuleCore::~TreeFactoryModuleCore()
{
}
