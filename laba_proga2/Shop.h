#pragma once
#include <string>
#include <vector>
#include "ShopItem.h"
#include "Laptop.h"

using namespace std;

struct Item
{
	Good* item; 
	Item* next; // вказівник на наступний елемент
};

class Shop 
{
public:
	Shop();
	Shop(string);
	~Shop(); // деструктор
	void addShop(ShopItem&);
private:
	string Name;
	vector <ShopItem> shops;
};

