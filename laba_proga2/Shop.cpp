#include "Shop.h"

Shop::Shop() 
{
	this->Name = "";
}

Shop::~Shop() 
{
}

Shop::Shop(string name) {
	if(!name.empty())
		this->Name = name;
}

void Shop::addShop(ShopItem& item) {
	this->shops.push_back(item);
}