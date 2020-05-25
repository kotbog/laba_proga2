#pragma once
#include <string>
#include <vector>
#include "ShopItem.h"
#include "Laptop.h"

using namespace std;

class Shop 
{
public:
	Shop();
	Shop(string);
	~Shop(); // деструктор
	void addShop(ShopItem&);
	void checkGood(string name);
	void showAll();
	ShopItem& searchObj(const ShopItem& item);
private:
	string Name;
	vector <ShopItem> shops;
};

