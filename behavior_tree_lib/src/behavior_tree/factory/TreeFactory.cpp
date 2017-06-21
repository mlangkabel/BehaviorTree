#include "behavior_tree/factory/TreeFactory.h"

#include <functional>

#include "tinyxml/tinyxml.h"

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/factory/TreeFactoryModule.h"
#include "behavior_tree/task/Task.h"
#include "behavior_tree/task/Composite.h"
#include "behavior_tree/task/Decorator.h"
#include "utility/logging/logging.h"
#include "utility/TextAccess.h"
#include "utility/UtilityLibrary.h"

namespace
{
	std::string getAttributeValue(TiXmlElement* element, const std::string& attributeName)
	{
		const char* attributeValue = element->Attribute(attributeName.c_str());
		if (!attributeValue)
		{
			const std::string taskType = element->Value();
			throw std::exception((
				"Node \"" + taskType + "\" is missing the \"" + attributeName + "\" attribute. Line " + std::to_string(element->Row()
			)).c_str());
		}
		return attributeValue;
	}
}

std::shared_ptr<TreeFactory> TreeFactory::create(std::shared_ptr<TextAccess> specificationAccess)
{
	std::shared_ptr<TreeFactory> factory = std::shared_ptr<TreeFactory>(new TreeFactory());

	factory->m_document = std::make_shared<TiXmlDocument>();
	factory->m_document->Parse(specificationAccess->getText().c_str(), 0, TIXML_ENCODING_UTF8);
	if (factory->m_document->Error())
	{
		LOG_ERROR(std::string("Error occurred while parsing XML: ") + factory->m_document->ErrorDesc());
		return std::shared_ptr<TreeFactory>();
	}

	initializeRootMap(factory);
	initializeModules(factory);

	return factory;
}

TreeFactory::~TreeFactory()
{
}

void TreeFactory::addModule(std::shared_ptr<TreeFactoryModule> module)
{
	for (std::shared_ptr<TaskFactoryBase> factory : module->getFactories())
	{
		m_taskFactories[factory->getTaskName()] = factory;
	}
}

std::shared_ptr<Task> TreeFactory::createBehaviorTree(const std::string& rootName) const
{
	std::shared_ptr<Task> task;

	auto it = m_rootMap.find(rootName);
	if (it != m_rootMap.end())
	{
		try
		{
			task = createTreeForElement(it->second);
		}
		catch (std::exception e)
		{
			LOG_ERROR("The TreeFactory encountered an exception while creating ROOT task named \"" + rootName + "\": " + e.what());
		}
	}
	else
	{
		LOG_ERROR("The TreeFactory does not contain any ROOT task named \"" + rootName + "\".");
	}

	return task;
}

std::shared_ptr<Task> TreeFactory::createTreeForElement(TiXmlElement* element) const
{
	std::shared_ptr<Task> task = createTaskForElement(element);

	if (!task)
	{
		throw std::exception(("Creating behavior tree at line " + std::to_string(element->Row()) + "failed.").c_str());
	}

	if (std::shared_ptr<Composite> composite = std::dynamic_pointer_cast<Composite>(task))
	{
		for (TiXmlElement* child = element->FirstChildElement(); child; child = child->NextSiblingElement())
		{
			composite->addChild(createTreeForElement(child));
		}
	}
	else if (std::shared_ptr<Decorator> decorator = std::dynamic_pointer_cast<Decorator>(task))
	{
		decorator->setChild(createTreeForElement(element->FirstChildElement()));
	}

	return task;
}

std::shared_ptr<Task> TreeFactory::createTaskForElement(TiXmlElement* element) const
{
	std::shared_ptr<Task> node;

	const std::string taskType = element->Value();
	std::map<std::string, std::shared_ptr<TaskFactoryBase>>::const_iterator it = m_taskFactories.find(taskType);
	if (it != m_taskFactories.end())
	{
		std::vector<std::string> parameterNames = it->second->getParameterNames();
		std::map<std::string, std::string> parameters;
		for (std::string parameterName : parameterNames)
		{
			parameters[parameterName] = getAttributeValue(element, parameterName);
		}
		node = it->second->create(parameters);
	}
	else
	{
		LOG_ERROR("The TreeFactory does not contain any module that has a TaskFactory for a \"" + taskType + "\" Task.");
	}
	return node;
}

void TreeFactory::initializeRootMap(std::shared_ptr<TreeFactory> factory)
{
	if (factory->m_document)
	{
		TiXmlHandle docHandle(factory->m_document.get());
		for (
			TiXmlElement* element = docHandle.FirstChild("BEHAVIOR_SPECIFICATION").FirstChild("TREES").FirstChild("ROOT").ToElement();
			element;
			element = element->NextSiblingElement("ROOT")
		)
		{
			factory->m_rootMap[getAttributeValue(element, "name")] = element->ToElement();
		}
	}
}

void TreeFactory::initializeModules(std::shared_ptr<TreeFactory> factory)
{
	if (factory->m_document)
	{
		TiXmlHandle docHandle(factory->m_document.get());
		for (
			TiXmlElement* element = docHandle.FirstChild("BEHAVIOR_SPECIFICATION").FirstChild("MODULES").FirstChild("MODULE").ToElement();
			element;
			element = element->NextSiblingElement("MODULE")
			)
		{
			const std::string moduleName = getAttributeValue(element, "name");
			const std::string libraryFilePath = "behavior_tree_module_" + moduleName + ".dll";

			std::function<void(std::shared_ptr<TreeFactory>)> registerModule = Utility::loadFunctionFromDynamicLibrary<void, std::shared_ptr<TreeFactory>>(
				libraryFilePath,
				"registerModule"
			);

			registerModule(factory);
		}
	}
}

TreeFactory::TreeFactory()
{
}
