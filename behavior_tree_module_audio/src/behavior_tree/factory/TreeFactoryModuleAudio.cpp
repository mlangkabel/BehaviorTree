#include "behavior_tree/factory/TreeFactoryModuleAudio.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "behavior_tree/task/ActionPlayAudioFile.h"

namespace BehaviorTree
{
	extern "C" void registerModule(std::shared_ptr<TreeFactory> factory)
	{
		factory->addModule(std::make_shared<TreeFactoryModuleAudio>());
	}

	TreeFactoryModuleAudio::TreeFactoryModuleAudio()
	{
		addFactory(std::make_shared<ActionFactoryPlayAudioFile>());
	}
}
