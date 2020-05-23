#pragma once
#include <iostream>
#include "Good.h"

using namespace std;

struct Item
{
	Good* item;
	Item* next; // вказівник на наступний елемент
};


class ShopItem
{
public:
	ShopItem();
	~ShopItem();
	ShopItem(string);
	void Print();
	Item* addGood(Good* item); // додати товар
	void showGoods(); // показати список
	void DeleteItem(string data);
	void deleteList(); // видалити весь список
	Item* operator[] (string name);
	float totalPrice();
private:
	string street;
	Item* first;
	int goodsCounter;
};

