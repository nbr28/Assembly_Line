#pragma once
// CustomerOrder Milestone - CustomerItem Interface
// CustomerItem.h
// Chris Szalwinski
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

class Item;

class CustomerItem {
	std::string _name;  // name of the requested component 
	bool _filled;       // status of the request
	unsigned int _code; // unique shipping label
public:
	CustomerItem(const std::string& str = std::string());
	//returns true if the current object asks for item; false otherwise
	bool asksFor(const Item&) const;
	//returns true if the current object's request has been filled
	bool isFilled() const;
	//sets the item code for the current object to the value received and switches the status of the current object to filled
	void fill(const unsigned int);
	//resets the item code for the current object to 0 and resets the status of the current object to not filled
	void clear();
	//Gets the name
	const std::string& getName() const;
	//inserts into os a description of the customer item
	void display(std::ostream&) const;
};