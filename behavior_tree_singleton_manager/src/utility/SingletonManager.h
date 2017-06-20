#ifndef SINGLETON_MANAGER_H
#define SINGLETON_MANAGER_H

#ifdef SINGLETON_MANAGER_EXPORTS
#define SINGLETON_MANAGER_API __declspec(dllexport)
#else
#define SINGLETON_MANAGER_API __declspec(dllimport)
#endif

#include <map>
#include <memory>
#include <string>

class Singleton;

class SINGLETON_MANAGER_API SingletonManager
{
public:
	static std::shared_ptr<SingletonManager> getInstance();

	void addSingleton(std::shared_ptr<Singleton> singleton);
	std::shared_ptr<Singleton> getSingleton(const std::string& name);
	void removeSingleton(const std::string& name);

private:
	SingletonManager();
	SingletonManager(const SingletonManager&);
	void operator=(const SingletonManager&);

	static std::shared_ptr<SingletonManager> s_instance;
	std::map<std::string, std::shared_ptr<Singleton>> m_singletons;
};

#endif // SINGLETON_MANAGER_H
