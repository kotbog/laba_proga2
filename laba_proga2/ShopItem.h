#pragma once
#include <iostream>
#include "Good.h"

using namespace std;

struct Item
{
	Good* item;
	Item* next; // �������� �� ��������� �������
};


class ShopItem
{
public:
	ShopItem();
	~ShopItem();
	ShopItem(string);
	void Print();
	Item* addGood(Good* item); // ������ �����
	void showGoods(); // �������� ������
	void DeleteItem(string data);
	void deleteList(); // �������� ���� ������
	Item* operator[] (string name);
	float totalPrice();
private:
	string street;
	Item* first;
	int goodsCounter;
};

