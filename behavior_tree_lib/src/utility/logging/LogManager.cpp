#include "utility/logging/LogManager.h"

#include <algorithm>

#include "utility/logging/LogMessage.h"
#include "utility/SingletonManager.h"

std::shared_ptr<LogManager> LogManager::getInstance()
{
	std::shared_ptr<LogManager> instance = std::dynamic_pointer_cast<LogManager>(SingletonManager::getInstance()->getSingleton(getSingletonNameStatic()));
	if (!instance)
	{
		instance = std::shared_ptr<LogManager>(new LogManager());
		SingletonManager::getInstance()->addSingleton(instance);
	}
	return instance;
}

void LogManager::destroyInstance()
{
	SingletonManager::getInstance()->removeSingleton(getSingletonNameStatic());
}

LogManager::~LogManager()
{
}

std::string LogManager::getSingletonName()
{
	return getSingletonNameStatic();
}

void LogManager::addLogger(std::shared_ptr<Logger> logger)
{
	m_logManagerImplementation.addLogger(logger);
}

void LogManager::removeLogger(std::shared_ptr<Logger> logger)
{
	m_logManagerImplementation.removeLogger(logger);
}

void LogManager::removeLoggersByType(const std::string& type)
{
	m_logManagerImplementation.removeLoggersByType(type);
}

int LogManager::getLoggerCount() const
{
	return m_logManagerImplementation.getLoggerCount();
}

void LogManager::logInfo(
	const std::string& message,
	const std::string& file,
	const std::string& function,
	const unsigned int line
)
{
	m_logManagerImplementation.logInfo(message, file, function, line);
}

void LogManager::logWarning(
	const std::string& message,
	const std::string& file,
	const std::string& function,
	const unsigned int line
)
{
	m_logManagerImplementation.logWarning(message, file, function, line);
}

void LogManager::logError(
	const std::string& message,
	const std::string& file,
	const std::string& function,
	const unsigned int line
)
{
	m_logManagerImplementation.logError(message, file, function, line);
}

std::string LogManager::getSingletonNameStatic()
{
	return "LogManager";
}

LogManager::LogManager()
{
}
