#ifndef TREE_FACTORY_MODULE_LOGGING_H
#define TREE_FACTORY_MODULE_LOGGING_H

#include <memory>

#include "behavior_tree/factory/TreeFactoryModule.h"

class TreeFactory;

extern "C" __declspec(dllexport) void registerModule(std::shared_ptr<TreeFactory>);

class TreeFactoryModuleLogging : public TreeFactoryModule
{
public:
	TreeFactoryModuleLogging();
	virtual ~TreeFactoryModuleLogging();
};

#endif // TREE_FACTORY_MODULE_LOGGING_H
