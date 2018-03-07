#include "Utilities.h"

char Utilities::_delimiter;

Utilities::Utilities(size_t min_width)
{
	this->_field_width = min_width;
}

size_t Utilities::getFieldWidth() const
{
	return this->_field_width;
}

const std::string Utilities::nextToken(const std::string & str, size_t & next_pos, bool & more)
{
	
	std::string ret = str.substr(next_pos);//trim down 
	size_t delimiter_pos = ret.find(_delimiter);

	if (str.size() == 0)
	{
		throw std::string("No Size");
	}

	if (delimiter_pos == std::string::npos)
	{
		ret = ret.substr(0, ret.find_first_of("\r\n"));
	}
	else
	{
		ret = ret.substr(0, delimiter_pos);
	}
	
	next_pos += ret.size() + 1;
	more = (next_pos < str.size());

	//Remove all white Spaces
	size_t ret_pos;
	while ((ret_pos = ret.size() - 1) != std::string::npos) {
		if (isspace(ret.at(ret_pos)))
			ret.erase(ret_pos);
		else break;
	}

	while (ret.size() > 0) {
		if (isspace(ret.at(0)))
			ret.erase(0, 1);
		else break;
	}

	if (_field_width < ret.size())
	{
		_field_width = ret.size();//resize to larger one
	}
	
	if (ret.size() == 0 && more)
	{
		throw str + "<-- *** no token found before the delimiter ***";
	}

	return ret;
}



void Utilities::setDelimiter(const char newDim)
{
	_delimiter = newDim;
}

void Utilities::setLogFile(const char * fileName)
{
	_logFile.open(fileName, std::ios_base::out | std::ios_base::trunc);
}

std::ofstream & Utilities::getLogFile()
{
	return _logFile;
}



void Utilities::setFieldWidth(size_t fw)
{
	this->_field_width = fw;
}


