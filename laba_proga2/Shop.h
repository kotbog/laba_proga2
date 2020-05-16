#pragma once
#include <string>
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
	void Print();
	Item* addGood(Laptop* item); // додати товар
	void showGoods(); // показати список
	void DeleteItem(string data);
	void deleteList(); // видалити весь список
private:
	string nameShop;
	int goodsCounter; // кількість товарів
	Item* first;
};

