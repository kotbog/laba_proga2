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
void Shop::showAll() {
	cout << "Number of shops: " << ShopItem::getShopsCounter() << endl;
	for (int i = 0; i < shops.size(); i++) {
		cout << shops[i];
	}
}
ShopItem* Shop::searchObj(const ShopItem& item) {
	for (int i = 0; i < this->shops.size(); i++) {
		if (this->shops[i] == item) {
			return &(this->shops[i]);
		}
	}
	return NULL;
}
void Shop::checkGood(string name) {
	cout << name;
	for (int i = 0; i < this->shops.size(); i++) {
		if (this->shops[i].isExist(name)) {
			cout << this->shops[i];
		}
	}
}