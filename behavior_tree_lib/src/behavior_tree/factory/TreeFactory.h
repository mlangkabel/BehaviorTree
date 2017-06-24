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

class TreeFactory : public std::enable_shared_from_this<TreeFactory>
{
public:
	static std::shared_ptr<TreeFactory> create(std::shared_ptr<TextAccess> specificationAccess);
	~TreeFactory();

	void addModule(std::shared_ptr<TreeFactoryModule> module);

	std::shared_ptr<Task> createBehaviorTree(const std::string& rootName) const;

private:
	static void initializeRootMap(std::shared_ptr<TreeFactory> factory);
	static void initializeModules(std::shared_ptr<TreeFactory> factory);

	TreeFactory();

	std::shared_ptr<Task> createTreeForElement(TiXmlElement* element) const;
	std::shared_ptr<Task> createTaskForElement(TiXmlElement* element) const;

	std::shared_ptr<TiXmlDocument> m_document;
	std::map<std::string, TiXmlElement*> m_rootMap;
	std::map<std::string, std::shared_ptr<TaskFactoryBase>> m_taskFactories;
};

#endif // TREE_FACTORY_H
