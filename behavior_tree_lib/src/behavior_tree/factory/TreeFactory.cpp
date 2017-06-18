#include "behavior_tree/factory/TreeFactory.h"

#include "tinyxml/tinyxml.h"

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/factory/TreeFactoryModule.h"
#include "behavior_tree/task/Task.h"
#include "behavior_tree/task/Composite.h"
#include "behavior_tree/task/Decorator.h"
#include "utility/logging/logging.h"
#include "utility/TextAccess.h"

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

TreeFactory::TreeFactory(std::shared_ptr<TextAccess> specificationAccess)
{
	document = std::make_shared<TiXmlDocument>();
	document->Parse(specificationAccess->getText().c_str(), 0, TIXML_ENCODING_UTF8);
	if (document->Error())
	{
		std::string desc = document->ErrorDesc();
		LOG_ERROR("Error occurred while parsing XML: " + desc);
	}
	TiXmlHandle docHandle(document.get());
	for (
		TiXmlElement* element = docHandle.FirstChild("TREES").FirstChild("ROOT").ToElement();
		element;
		element = element->NextSiblingElement("ROOT")
	) 
	{
		m_rootMap[getAttributeValue(element, "name")] = element->ToElement();
	}
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