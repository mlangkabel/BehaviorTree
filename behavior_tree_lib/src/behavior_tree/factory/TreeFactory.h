#ifndef TREE_FACTORY_H
#define TREE_FACTORY_H

#include <map>
#include <memory>
#include <string>

class TiXmlDocument;
class TiXmlElement;

class Task;
class TaskFactoryBase;
class TextAccess;
class TreeFactoryModule;

class TreeFactory
{
public:
	TreeFactory(std::shared_ptr<TextAccess> specificationAccess);
	~TreeFactory();

	void addModule(std::shared_ptr<TreeFactoryModule> module);

	std::shared_ptr<Task> createBehaviorTree(const std::string& rootName) const;

private:
	std::shared_ptr<Task> createTreeForElement(TiXmlElement* element) const;
	std::shared_ptr<Task> createTaskForElement(TiXmlElement* element) const;

	std::shared_ptr<TiXmlDocument> document;
	std::map<std::string, TiXmlElement*> m_rootMap;
	std::map<std::string, std::shared_ptr<TaskFactoryBase>> m_taskFactories;
};

#endif // TREE_FACTORY_H
