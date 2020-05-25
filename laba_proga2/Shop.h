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
private:
	string Name;
	vector <ShopItem> shops;
};

