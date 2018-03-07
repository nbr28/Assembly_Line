#pragma once
// Milestone 1 - Utilities Interface
// Utilities.h
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016

#include <string>
#include <fstream>


class Utilities {
	size_t _field_width;           // maximum field width needed 
	static char _delimiter;        // field delimiter character
	static std::ofstream _logFile; // log file
public:
	Utilities(size_t minimum_field_width = 1u);
	size_t getFieldWidth() const;
	const std::string nextToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char);
	static void setLogFile(const char*);
	static std::ofstream& getLogFile();
	void setFieldWidth(size_t fw);
};
