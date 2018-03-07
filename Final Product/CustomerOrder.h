#pragma once
// CustomerOrder Milestone - CustomerOrder Interface
// CustomerOrder.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>
#ifndef _MSC_VER
#define NOEXCEPT noexcept
#else
#define NOEXCEPT
#endif

class Item;
class CustomerItem;

class CustomerOrder {
	std::string _name;          // name of the customer
	std::string _product;       // name of the product
	CustomerItem* _order;       // address of the customer requests 
	unsigned int _nOrders;      // number of requests
	static size_t _field_width; // current maximum field width
public:
	CustomerOrder(const std::string&);
	CustomerOrder(const CustomerOrder&)=delete;//TODO Check this 
	CustomerOrder(CustomerOrder&&other)NOEXCEPT;
	~CustomerOrder();
	CustomerOrder& operator=(const CustomerOrder&) = delete;
	CustomerOrder&& operator=(CustomerOrder&&other)NOEXCEPT;
	//returns the number of customer items in the current object
	unsigned int noOrders() const;
	//returns a reference to the name of customer item i; reports an exception if the index is out of bounds
	const std::string& operator[](unsigned int) const;
	// searches through the customer items and fills those order for the customer items identified by item if any have not been filled.  This function increments item's code for each customer item filled.  This keeps the item code unique for each order.
	void fill(Item&);
	void remove(Item&);
	//returns true if the current object is in a safe empty state
	bool empty() const;
	void display(std::ostream&) const;
};