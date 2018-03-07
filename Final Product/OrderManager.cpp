#include<algorithm>
#include "OrderManager.h"
#include "CustomerOrder.h"
#include "ItemManager.h"


CustomerOrder && OrderManager::extract()
{
	CustomerOrder p = std::move(this->back());
	return std::move(p);
}

void OrderManager::validate(const ItemManager &itemManager, std::ostream & os)
{
	for (auto i =this->begin(); i != this->end(); ++i) 
	{
		for (unsigned int j = 0; j<i->noOrders(); ++j) 
		{
			if (std::find_if(itemManager.begin(), itemManager.end(), [&](Item item) 
			{
				return (*i)[j] == item.getName();
			}) == itemManager.end() )//if the found item matches the end then display output
			{
				os << (*i)[j] << " is unavailable" << std::endl;
			}
		}
	}
}

void OrderManager::display(std::ostream &os) const
{
	for (auto& i : *this) 
		i.display(os);
}
