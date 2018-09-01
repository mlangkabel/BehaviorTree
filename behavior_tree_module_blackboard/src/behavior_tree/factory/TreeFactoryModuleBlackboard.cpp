#include "behavior_tree/factory/TreeFactoryModuleBlackboard.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/ActionCheckVariableEquals.h"
#include "behavior_tree/task/ActionCheckVariableExists.h"
#include "behavior_tree/task/ActionClearBlackboard.h"
#include "behavior_tree/task/ActionDecrementIntegerVariable.h"
#include "behavior_tree/task/ActionIncrementIntegerVariable.h"
#include "behavior_tree/task/ActionLogBlackboardContent.h"
#include "behavior_tree/task/ActionSetIntegerVariable.h"
#include "behavior_tree/task/ActionSetStringVariable.h"

extern "C" void registerModule(std::shared_ptr<TreeFactory> factory)
{
	factory->addModule(std::make_shared<TreeFactoryModuleBlackboard>());
}

TreeFactoryModuleBlackboard::TreeFactoryModuleBlackboard()
{
	addFactory(std::make_shared<ActionFactoryCheckVariableEquals>());
	addFactory(std::make_shared<ActionFactoryCheckVariableExists>());
	addFactory(std::make_shared<ActionFactoryClearBlackboard>());
	addFactory(std::make_shared<ActionFactoryDecrementIntegerVariable>());
	addFactory(std::make_shared<ActionFactoryIncrementIntegerVariable>());
	addFactory(std::make_shared<ActionFactoryLogBlackboardContent>());
	addFactory(std::make_shared<ActionFactorySetIntegerVariable>());
	addFactory(std::make_shared<ActionFactorySetStringVariable>());
}
