#ifndef STRING_LOGGER_H
#define STRING_LOGGER_H

#include "utility/logging/Logger.h"
#include "utility/logging/LogMessage.h"

class StringLogger : public Logger
{
public:
	StringLogger();
	virtual ~StringLogger();

	void clearLogString();
	std::string getLogString() const;

	virtual void logInfo(const LogMessage& message);
	virtual void logWarning(const LogMessage& message);
	virtual void logError(const LogMessage& message);

private:
	void logMessage(const std::string& type, const LogMessage& message);

	std::string m_logString;
};

#endif // STRING_LOGGER_H
