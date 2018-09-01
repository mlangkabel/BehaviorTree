#ifndef TREE_FACTORY_MODULE_AUDIO_H
#define TREE_FACTORY_MODULE_AUDIO_H

#include <memory>

#include "behavior_tree/factory/TreeFactoryModule.h"

class TreeFactory;

extern "C" __declspec(dllexport) void registerModule(std::shared_ptr<TreeFactory>);

class TreeFactoryModuleAudio : public TreeFactoryModule
{
public:
	TreeFactoryModuleAudio();
};

#endif // TREE_FACTORY_MODULE_AUDIO_H
