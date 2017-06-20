#ifndef LOG_MANAGER_H
#define LOG_MANAGER_H

#include <memory>
#include <mutex>

#include "utility/logging/Logger.h"
#include "utility/logging/LogManagerImplementation.h"
#include "utility/Singleton.h"

class LogManager: public Singleton
{
public:
	static std::shared_ptr<LogManager> getInstance();
	static void destroyInstance();

	virtual ~LogManager();

	virtual std::string getSingletonName();

	void addLogger(std::shared_ptr<Logger> logger);
	void removeLogger(std::shared_ptr<Logger> logger);
	void removeLoggersByType(const std::string& type);
	int getLoggerCount() const;

	void logInfo(
		const std::string& message,
		const std::string& file,
		const std::string& function,
		const unsigned int line
	);
	void logWarning(
		const std::string& message,
		const std::string& file,
		const std::string& function,
		const unsigned int line
	);
	void logError(
		const std::string& message,
		const std::string& file,
		const std::string& function,
		const unsigned int line
	);

private:
	static std::string getSingletonNameStatic();

	LogManager();
	LogManager(const LogManager&);
	void operator=(const LogManager&);

	LogManagerImplementation m_logManagerImplementation;
};

#endif // LOG_MANAGER_H
