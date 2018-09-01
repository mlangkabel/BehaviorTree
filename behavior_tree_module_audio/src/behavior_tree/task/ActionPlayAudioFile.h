#ifndef ACTION_PLAY_AUDIO_FILE_H
#define ACTION_PLAY_AUDIO_FILE_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

namespace BehaviorTree
{
	class ActionPlayAudioFile;

	class ActionFactoryPlayAudioFile : public TaskFactory<ActionPlayAudioFile, std::string>
	{
	public:
		ActionFactoryPlayAudioFile()
			: TaskFactory<ActionPlayAudioFile, std::string>("PLAY_AUDIO_FILE", "file_path")
		{}
	};

	class ActionPlayAudioFile : public Action
	{
	public:
		ActionPlayAudioFile(const std::string& filePath);

		virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

	private:
		const std::string m_filePath;
	};
}

#endif // ACTION_PLAY_AUDIO_FILE_H
