#pragma once
// Task Milestone - Task Interface
// Task.h
#include <iostream>
#include <string>


class Task {
	std::string _name;          // name of the task
	std::string _slots;         // number of slots
	std::string _nextTask[2];   // names of the next tasks
	const Task* _pNextTask[2];  // addresses of the next tasks
	static size_t _field_width; // current maximum field width 
public:
	enum Quality {
		passed,
		redirect
	};
	Task(const std::string&);
	bool validate(const Task& task);
	const std::string& getName() const;
	unsigned int getSlots() const;
	const Task* getNextTask(Quality quality) const;
	void display(std::ostream& os) const;
	static size_t getFieldWidth();
};

bool operator==(const Task& task, const Task& otherTask);