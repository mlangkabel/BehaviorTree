#ifndef TREE_FACTORY_MODULE_CORE_H
#define TREE_FACTORY_MODULE_CORE_H

#include <memory>

#include "behavior_tree/factory/TreeFactoryModule.h"

class TreeFactory;

extern "C" __declspec(dllexport) void registerModule(std::shared_ptr<TreeFactory>);

class TreeFactoryModuleCore : public TreeFactoryModule
{
public:
	TreeFactoryModuleCore();
};

#endif // TREE_FACTORY_MODULE_CORE_H
