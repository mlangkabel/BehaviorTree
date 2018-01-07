#include "behavior_tree/task/ActionPlayAudioFile.h"

#include <windows.h>
#pragma comment(lib, "winmm.lib")

ActionPlayAudioFile::ActionPlayAudioFile(const std::string& filePath)
	: m_filePath(filePath)
{
}

ActionPlayAudioFile::~ActionPlayAudioFile()
{
}

Task::StatusType ActionPlayAudioFile::evaluate(std::shared_ptr<Blackboard> blackboard)
{
	int ret = PlaySound(m_filePath.c_str(), NULL, SND_FILENAME);
	return STATUS_SUCCESS;
}
