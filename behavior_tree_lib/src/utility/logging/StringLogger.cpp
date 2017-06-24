#include "utility/logging/StringLogger.h"

StringLogger::StringLogger()
	: Logger("StringLogger")
	, m_logString("")
{
}

StringLogger::~StringLogger()
{
}

void StringLogger::clearLogString()
{
	m_logString = "";
}

std::string StringLogger::getLogString() const
{
	return m_logString;
}

void StringLogger::logInfo(const LogMessage& message)
{
	logMessage("INFO", message);
}

void StringLogger::logWarning(const LogMessage& message)
{
	logMessage("WARNING", message);
}

void StringLogger::logError(const LogMessage& message)
{
	logMessage("ERROR", message);
}

void StringLogger::logMessage(const std::string& type, const LogMessage& message)
{
	m_logString += type + ": " + message.message + "\n";
}
