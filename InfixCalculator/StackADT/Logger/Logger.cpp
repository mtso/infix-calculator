// Logger.cpp
// Logging utility functions.
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef LOGGER_CPP
#define LOGGER_CPP

#include "Logger.h"

void util::log(const std::string& message)
{
	static bool isFirstTime = true;
	static std::ofstream logFile;

	using namespace std::chrono;

	system_clock::duration now = system_clock::now().time_since_epoch();
	__int64 nowInMs = duration_cast<milliseconds>(now).count();

	if (isFirstTime)
	{
		isFirstTime = false;
		logFile.open(LOG_FILENAME, std::ios::app);

		logFile << "==================================" << std::endl;
		logFile << nowInMs << ": New logging session" << std::endl;
	}
	
	logFile << nowInMs << ": " << message << std::endl;
}

void util::clearLog()
{
	std::ofstream log(LOG_FILENAME);
	log.close();
}

std::string util::removeTimestamp(const std::string& str)
{
	bool reachedColon = false;
	int colonIndex = 0;
	std::string stringWithoutTimestamp;

	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (str[i] == ':')
		{
			reachedColon = true;
			colonIndex = i;
		}

		if (reachedColon && i > colonIndex + 1)
		{
			stringWithoutTimestamp += str[i];
		}
	}

	return stringWithoutTimestamp;
}

#endif