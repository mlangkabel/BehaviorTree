#ifndef TREE_FACTORY_MODULE_H
#define TREE_FACTORY_MODULE_H

#include <memory>
#include <vector>

#include "behavior_tree/factory/TaskFactory.h"

class TreeFactoryModule
{
public:
	TreeFactoryModule();
	virtual ~TreeFactoryModule();

	std::vector<std::shared_ptr<TaskFactoryBase>> getFactories() const;

protected:
	void addFactory(std::shared_ptr<TaskFactoryBase> taskFactory);

private:
	std::vector<std::shared_ptr<TaskFactoryBase>> m_taskFactories;
};

#endif // TREE_FACTORY_MODULE_H
