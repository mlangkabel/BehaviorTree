#include "behavior_tree/factory/TreeFactoryModuleLogging.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/ActionLogError.h"
#include "behavior_tree/task/ActionLogInfo.h"
#include "behavior_tree/task/ActionLogWarning.h"

extern "C" void registerModule(std::shared_ptr<TreeFactory> factory)
{
	factory->addModule(std::make_shared<TreeFactoryModuleLogging>());
}

TreeFactoryModuleLogging::TreeFactoryModuleLogging()
{
	addFactory(std::make_shared<ActionFactoryLogError>());
	addFactory(std::make_shared<ActionFactoryLogInfo>());
	addFactory(std::make_shared<ActionFactoryLogWarning>());
}
