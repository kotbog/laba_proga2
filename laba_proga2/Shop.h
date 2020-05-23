#pragma once
#include <string>
#include <vector>
#include "ShopItem.h"
#include "Laptop.h"

using namespace std;

struct Item
{
	Good* item; 
	Item* next; // �������� �� ��������� �������
};

class Shop 
{
public:
	Shop();
	Shop(string);
	~Shop(); // ����������
	void addShop(ShopItem&);
private:
	string Name;
	vector <ShopItem> shops;
};

