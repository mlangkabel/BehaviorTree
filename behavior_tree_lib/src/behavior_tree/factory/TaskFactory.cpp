#include "behavior_tree/factory/TaskFactory.h"

TaskFactoryBase::TaskFactoryBase(const std::string &taskName)
	: m_taskName(taskName)
{
}

std::string TaskFactoryBase::getTaskName() const
{
	return m_taskName;
}

std::vector<std::string> TaskFactoryBase::getParameterNames() const
{
	return m_parameterNames;
}

void TaskFactoryBase::addParameterName(const std::string &parameterName)
{
	m_parameterNames.push_back(parameterName);
}
