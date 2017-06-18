#include "behavior_tree/factory/TreeFactoryModule.h"

TreeFactoryModule::TreeFactoryModule()
{
}

TreeFactoryModule::~TreeFactoryModule()
{
}

std::vector<std::shared_ptr<TaskFactoryBase>> TreeFactoryModule::getFactories() const
{
	return m_taskFactories;
}

void TreeFactoryModule::addFactory(std::shared_ptr<TaskFactoryBase> taskFactory)
{
	m_taskFactories.push_back(taskFactory);
}
