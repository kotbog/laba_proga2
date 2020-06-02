#pragma once
#include <iostream>
#include "Good.h"
#include <list>

using namespace std;

class ShopItem
{
public:
	ShopItem();
	~ShopItem();
	ShopItem(string);
	void addGood(Good* item); // додати товар
	void showGoods(); // показати список
	void DeleteItem(string data);
	void deleteList(); // видалити весь список
	//Item* operator[] (string name);
	float totalPrice();
	bool isExist(string name);
	string getStreet();
	friend ostream& operator << (ostream&, ShopItem&);
	ShopItem& operator= (const ShopItem& str);
	bool operator == (const ShopItem& item);
	ShopItem& operator - (string name);
	static int getShopsCounter();
	static void decrCounter(); // збільшити allShopsCounter
	static void incrCounter(); // зменшити allShopsCounter
private:
	string street;
	// Item* first;
	list<Good*> lst;
	list<Good*>::iterator pLst;
	int goodsCounter;
	static int allShopsCounter;
};

