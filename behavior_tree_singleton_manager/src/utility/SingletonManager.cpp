#include "utility/SingletonManager.h"

#include "utility/Singleton.h"

std::shared_ptr<SingletonManager> SingletonManager::getInstance()
{
	if (!s_instance)
	{
		s_instance = std::shared_ptr<SingletonManager>(new SingletonManager());
	}
	return s_instance;
}

void SingletonManager::addSingleton(std::shared_ptr<Singleton> singleton)
{
	m_singletons.insert(std::make_pair(singleton->getSingletonName(), singleton));
}

std::shared_ptr<Singleton> SingletonManager::getSingleton(const std::string& name)
{
	auto it = m_singletons.find(name);
	if (it != m_singletons.end())
	{
		return it->second;
	}
	return std::shared_ptr<Singleton>();
}

void SingletonManager::removeSingleton(const std::string& name)
{
	m_singletons.erase(name);
}

SingletonManager::SingletonManager()
{
}

std::shared_ptr<SingletonManager> SingletonManager::s_instance;
