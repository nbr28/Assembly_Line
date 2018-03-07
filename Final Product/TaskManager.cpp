#include <algorithm>
#include "TaskManager.h"
#include "Task.h"
#include "ItemManager.h"


void TaskManager::validate(std::ostream & os)
{
	bool valid = true;
	for (auto i = this->begin(); i != this->end() && valid; i++) //valid stops loop if  validation fails 
	{
		bool invalid = true;
		for (auto j = this->begin(); j != this->end() && invalid; j++)  //when found invalid is false breaking loop
		{
			if (i->validate(*j))
				invalid = false;
		}

		if (invalid)
		{
			os << "********Not Valid Task**********" << std::endl;
			i->display(os);
			invalid = false;
		}

		valid = !invalid;
	}
}

void TaskManager::validate(const ItemManager & itMag, std::ostream & os)
{
	for (auto i = itMag.begin(); i != itMag.end(); i++)
	{
		auto posistion = std::find_if(this->begin(), this->end(), [i](Task t)->bool {return t.getName() == i->getFiller();});
		if (posistion == this->end())
		{
			os<<i->getFiller() + " is unavailable"<<std::endl;
		}
		posistion = std::find_if(this->begin(), this->end(), [i](Task t)->bool{	return t.getName() == i->getRemover();});
		if (posistion == this->end())
		{
			os<<i->getRemover() + " is unavailable"<<std::endl;
		}
	}
}

void TaskManager::display(std::ostream & os) const
{
	for (auto& t : *this)
		t.display(os);
}

