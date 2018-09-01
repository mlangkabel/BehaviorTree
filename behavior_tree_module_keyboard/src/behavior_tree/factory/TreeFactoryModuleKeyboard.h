#ifndef TREE_FACTORY_MODULE_KEYBOARD_H
#define TREE_FACTORY_MODULE_KEYBOARD_H

#include <memory>

#include "behavior_tree/factory/TreeFactoryModule.h"

class TreeFactory;

extern "C" __declspec(dllexport) void registerModule(std::shared_ptr<TreeFactory>);

class TreeFactoryModuleKeyboard : public TreeFactoryModule
{
public:
	TreeFactoryModuleKeyboard();
};

#endif // TREE_FACTORY_MODULE_KEYBOARD_H
