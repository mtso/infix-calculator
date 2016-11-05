// Logger.h
// Logging utility functions.
// CIS 22C F2016: Adrian Marroquin, Matthew Tso

#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <chrono>

#define LOG_FILENAME "stackadt_log.txt"

namespace util
{
	/**
	 * Creates a log entry in "stackadt_log.txt"
	 */
	inline void log(const std::string& message);

	/**
	 * Clears the log history
	 */
	inline void clearLog();

	/**
	 * Removes the seconds timestamp from the log entry
	 */
	inline std::string removeTimestamp(const std::string& str);
}

#include "Logger.cpp"
#endif