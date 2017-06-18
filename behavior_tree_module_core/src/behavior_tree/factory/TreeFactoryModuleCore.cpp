#include "behavior_tree/factory/TreeFactoryModuleCore.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/TaskRoot.h"
#include "behavior_tree/task/TaskSelector.h"
#include "behavior_tree/task/TaskSequence.h"

extern "C" void registerModule(std::shared_ptr<TreeFactory> factory)
{
	factory->addModule(std::make_shared<TreeFactoryModuleCore>());
}

TreeFactoryModuleCore::TreeFactoryModuleCore()
{
	addFactory(std::make_shared<TaskFactoryRoot>());
	addFactory(std::make_shared<TaskFactorySelector>());
	addFactory(std::make_shared<TaskFactorySequence>());
}

TreeFactoryModuleCore::~TreeFactoryModuleCore()
{
}
