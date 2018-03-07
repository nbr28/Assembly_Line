#include <vector>
#include <stdexcept>
#include <iomanip>
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Utilities.h"
#include "Item.h"

size_t CustomerOrder::_field_width;

CustomerOrder::CustomerOrder(const std::string &str)
{
	bool more = true;
	size_t nextPos = 0u;
	std::vector<CustomerItem> ci;

	this->_nOrders = 0u;
	this->_order = nullptr;
	if (!str.size() == 0)
	{
		Utilities util(CustomerOrder::_field_width);
		this->_name = util.nextToken(str, nextPos, more);
		if (more)
			this->_product = util.nextToken(str, nextPos, more);

		while (more)
		{
			ci.push_back(CustomerItem(util.nextToken(str, nextPos, more)));
		}

		this->_order = new CustomerItem[ci.size()];
		this->_nOrders = (unsigned int)ci.size();

		for (std::vector<int>::size_type i = 0; i < this->_nOrders; i++) {
			this->_order[i] = CustomerItem(ci[i]);
		}
		CustomerOrder::_field_width = util.getFieldWidth();
	}
}

//CustomerOrder::CustomerOrder(const CustomerOrder & tmp)
//{
//	//WILL NOT WORK TALK TO ELIOT After talking to mutiple people with this error
//	
//	throw std::string("DO NOT COPY");
//}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& other) {
	if (this != &other) 
	{

		if (this->_order) //if not nullptr
		{
			delete[] this->_order;
		}

		this->_name = other._name;
		this->_product = other._product;
		this->_nOrders = other._nOrders;
		this->_order = other._order;

		other._name.clear();
		other._product.clear();
		other._nOrders = 0;
		other._order = nullptr;
	}

	return std::move(*this);
}


CustomerOrder::CustomerOrder(CustomerOrder && other)
{
	this->_order = nullptr;
	*this = std::move(other);
}

CustomerOrder::~CustomerOrder()
{
	if (this->_order)
	{
		delete[] this->_order;
	}
}

unsigned int CustomerOrder::noOrders() const
{
	return this->_nOrders;
}

const std::string & CustomerOrder::operator[](unsigned int i) const
{
	if (i <= this->_nOrders)
	{
		return this->_order[i].getName();
	}
	else
		throw std::out_of_range("Customer Order Out of bounds Error");
}

void CustomerOrder::fill(Item &item)
{
	CustomerItem* ptrTravler = this->_order;
	for (unsigned int i = 0; i < this->_nOrders; i++)
	{
		if (ptrTravler->asksFor(item))
		{
			ptrTravler->fill(item++);
		}
		ptrTravler++;
	}
}

void CustomerOrder::remove(Item &item)//this function might be compleatlty wrong...
{
	CustomerItem* ptrTravler = this->_order;
	for (unsigned int i = 0; i < this->_nOrders; i++)
	{
		if (ptrTravler->getName() == item.getName())
		{
			for (size_t m = i; m < this->_nOrders; m++)
			{

			}
		}
	}
}

bool CustomerOrder::empty() const
{
	return this->_name.empty();
}

void CustomerOrder::display(std::ostream &os) const
{
	os << std::left;
	os.fill(' ');
	os << std::setw(CustomerOrder::_field_width + 1)<< this->_name;
	os << " : ";
	os << this->_product << std::endl;

	for (unsigned int i = 0; i < this->_nOrders; i++) {
		this->_order[i].display(os);
	}
}

