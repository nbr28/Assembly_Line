#include "ItemManager.h"

void ItemManager::display(std::ostream & os , bool full) const
{
	for (auto& item : *this)
	{
		item.display(os, full);
	}
}
