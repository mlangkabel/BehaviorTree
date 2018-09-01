#ifndef TREE_FACTORY_MODULE_MOUSE_H
#define TREE_FACTORY_MODULE_MOUSE_H

#include <memory>

#include "behavior_tree/factory/TreeFactoryModule.h"

class TreeFactory;

extern "C" __declspec(dllexport) void registerModule(std::shared_ptr<TreeFactory>);

class TreeFactoryModuleMouse : public TreeFactoryModule
{
public:
	TreeFactoryModuleMouse();
};

#endif // TREE_FACTORY_MODULE_MOUSE_H
