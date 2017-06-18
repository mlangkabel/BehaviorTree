#include "behavior_tree/factory/TaskFactory.h"

TaskFactoryBase::TaskFactoryBase(const std::string &taskName)
	: m_taskName(taskName)
{
}

TaskFactoryBase::~TaskFactoryBase()
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

void TaskFactoryBase::addParameterName(const std::string &patameterName)
{
	m_parameterNames.push_back(patameterName);
}
