#pragma once
#include <string>
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
	void Print();
	Item* addGood(Laptop* item); // ������ �����
	void showGoods(); // �������� ������
	void DeleteItem(string data);
	void deleteList(); // �������� ���� ������
private:
	string nameShop;
	int goodsCounter; // ������� ������
	Item* first;
};

