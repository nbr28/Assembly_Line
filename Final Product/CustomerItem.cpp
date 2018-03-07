#include "CustomerItem.h"
#include "Item.h"

CustomerItem::CustomerItem(const std::string & str )
{
	if (str.empty())
	{
		this->_filled = false;
		this->_code = 0;
	}
	else
	{
		this->_name = str;
		this->_code = 0;
		this->_filled = false;
	}
}

bool CustomerItem::asksFor(const Item &item) const
{

	if (this->_name == item.getName())
		return true;
	return false;
}

bool CustomerItem::isFilled() const
{
	return this->_filled;
}

void CustomerItem::fill(const unsigned int code)
{
	this->_code=code;
	this->_filled = true;
}

void CustomerItem::clear()
{
	this->_code = 0;
	this->_filled = false;
}

const std::string & CustomerItem::getName() const
{
	return this->_name;
}

void CustomerItem::display(std::ostream &os ) const
{
	if (!this->_name.empty())
	{
		os << " " << (this->_filled ? '+' : '-');

		os << '[';
		os.width(CODE_WIDTH);
		os.fill('0');
		os << std::right << this->_code << "] " << this->_name << "\n";
	}
}
