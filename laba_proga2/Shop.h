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
	void deleteShop(ShopItem*);
	void showAll();
	ShopItem* searchObj(string);
private:
	//T phoneNumber;
	string Name;
	vector <ShopItem> shops;
};

