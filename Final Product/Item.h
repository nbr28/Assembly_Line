#pragma once
// CustomerOrder Milestone - Item Interface
// Item.h
// v1.0 - 9/11/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

const unsigned int CODE_WIDTH = 5;

class Item {
	std::string _name;          // name of the component
	std::string _filler;        // name of the filler task
	std::string _remover;       // name of the remover task 
	std::string _description;   // detailed description
	unsigned int _code;         // next shipping label
	static size_t _field_width; // current maximum field width
public:
	Item(const std::string& = std::string());
	//returns true if the current object is in a safe empty state
	bool empty() const;
	// increments the code to be printed on the next insertion and returns the value before incrementation.
	int operator++(int);
	//returns a copy of the code to be printed on the next insertion into a product
	unsigned int getCode() const;
	//returns an unmodifiable reference to the string that contains the name of the item
	const std::string& getName() const;
	//returns an unmodifiable reference to the string that contains the name of the task that inserts the item into a product
	const std::string& getFiller() const;
	//returns an unmodifiable reference to the string that contains the name of the task that extracts the item from a product
	const std::string& getRemover() const;
	//inserts into os the name of the item and its current code 
	void display(std::ostream&, bool = false) const;
};