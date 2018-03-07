#include <iomanip>
#include "Item.h"
#include "Utilities.h"

size_t Item::_field_width;

Item::Item(const std::string & str)
{
	Utilities util(Item::_field_width);
	bool more = true;
	size_t nextPos = 0u;

	if (str.empty())
	{
		this->_description = "no detailed description";
		this->_code = 1;
	}
	else
	{
		this->_name = util.nextToken(str, nextPos, more);
		if (more)
			this->_filler = util.nextToken(str, nextPos, more);
		if (more)
			this->_remover = util.nextToken(str, nextPos, more);
		if (more)
			this->_code = stoul(util.nextToken(str, nextPos, more));
		if (more)
		{
			std::string out= util.nextToken(str, nextPos, more);
			if (out.empty())
				this->_description = "no detailed description";
			else
				this->_description = out;
		}
		else
			this->_description= "no detailed description";
	}
	Item::_field_width=util.getFieldWidth();
}

bool Item::empty() const
{
	if (this->_description == "no detailed description"&&this->_code == 1)
		return true;
	return false;
}

int Item::operator++(int)
{
	return (this->_code)++;
}


unsigned int Item::getCode() const
{
	return this->_code;
}

const std::string & Item::getName() const
{
	return this->_name;
}

const std::string & Item::getFiller() const
{
	return this->_filler;
}

const std::string & Item::getRemover() const
{
	return this->_remover;
}

void Item::display(std::ostream &os , bool full) const
{
	os.fill(' ');
	os << std::setw((Item::_field_width - CODE_WIDTH) - 1)<<std::left<<this->_name;
	os << "[";
	os.fill('0');
	os.width(CODE_WIDTH);
	os<< std::right;
	os<< this->_code << "] ";
	os.fill(' ');
	if (full)
	{
		os << "From ";
		os.width(Item::_field_width - this->_filler.size());
		os <<std::left <<this->_filler<< std::right << " To " << this->_remover << std::endl;
		os.width(Item::_field_width+2);
		os << ": " << this->_description;
		os << "\n";
	}
	os << std::endl;
}


