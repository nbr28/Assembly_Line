#include <iomanip>
#include "Task.h"
#include "Utilities.h"


size_t Task::_field_width = 0;
std::ofstream Utilities::_logFile;

Task::Task(const std::string & str)
{
	bool more = true;
	size_t nextPos = 0;

	Utilities util(Task::_field_width);


	this->_pNextTask[passed] = nullptr;
	this->_pNextTask[redirect] = nullptr;
	this->_slots = "1";


	this->_name = util.nextToken(str, nextPos, more);
	if (more)
		this->_slots = util.nextToken(str, nextPos, more);
	if (more)
		this->_nextTask[passed] = util.nextToken(str, nextPos, more);
	if (more)
		this->_nextTask[redirect] = util.nextToken(str, nextPos, more);

	this->Task::_field_width = util.getFieldWidth();


}

bool Task::validate(const Task & task)
{

	if (task._name == _nextTask[passed])
		_pNextTask[passed] = &task;
	else if (task._name == _nextTask[redirect])
		_pNextTask[redirect] = &task;

	return (_nextTask[passed].empty() || _pNextTask[passed]) && (_nextTask[redirect].empty() || _pNextTask[redirect]);
}

const std::string & Task::getName() const
{
	return this->_name;
}

unsigned int Task::getSlots() const
{
	return atoi(this->_slots.c_str());
}

const Task * Task::getNextTask(Quality quality) const
{

	if (this->_pNextTask[quality] != nullptr)
	{
		return this->_pNextTask[quality];
	}
	else
	{
		throw "*** Validate[" + this->_name + "] @[" + this->_nextTask[quality] + "] * **";
	}
}

void Task::display(std::ostream & os) const
{
	os << "Task Name    : " << std::left << std::setw(this->_field_width + 3) <<
		"[" + this->_name + "]" << "[" << this->_slots << "]" << std::endl;

	if (this->_nextTask[passed].empty() != true)
	{
		os << " Continue to : " << std::left << std::setw(this->_field_width + 2) << "[" + this->_nextTask[passed] + "]";
		if (this->_pNextTask[passed] == nullptr)
			os << " *** to be validated ***";
		os << std::endl;
	}

	if (this->_nextTask[redirect].empty() != true)
	{
		os << " Redirect to : " << std::left << std::setw(this->_field_width + 2) << "[" + this->_nextTask[redirect] + "]";
		if (this->_pNextTask[redirect] == nullptr)
			os << " *** to be validated ***";
		os << std::endl;
	}
}

size_t Task::getFieldWidth()
{
	return _field_width;
}


bool operator==(const Task & task, const Task & otherTask)
{
	return task.getName() == otherTask.getName();
}
