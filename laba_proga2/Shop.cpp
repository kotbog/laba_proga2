#include "Shop.h"
#include <string>
#include <iostream>

using namespace std;  
void Shop::Print() { 
	cout << "Shop name: " << this->nameShop << endl;
}
Shop::Shop() : nameShop(""), goodsCounter(0) 
{	
	this->first = NULL;
}
Shop::~Shop() {
	deleteList();
}
Shop::Shop(string nameShop) { // конструктор з параметром
	this->nameShop = nameShop;
	this->goodsCounter = 0;
	this->first = NULL;
}
Item* Shop::addGood(Good* item) {
	if (this->first == NULL)
	{
		this->first = new Item();
		this->first->item =	item;
		this->first->next = NULL;
		this->goodsCounter += 1;
		return this->first;
	}
	else {
		Item* newItem, * temp;
		newItem = new Item();
		newItem->item = item;
		newItem->next = NULL;
		temp = this->first;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newItem;
		this->goodsCounter += 1;
		return temp;
	}
}
void Shop::showGoods()
{
	if (this->first == NULL) // якщо дерево пусте
	{
		cout << "Empty list" << endl;
		
	}
	else {
		Item* temp = this->first;
		Print();
		cout << "-------------------" << endl;
		while (temp->next != NULL) {
			temp->item->Print();
			cout << "********************" << endl;
			temp = temp->next;
		}
		temp->item->Print();
		cout << "********************" << endl;
		cout << "Number of goods: " << this->goodsCounter << endl;
	}
}
void Shop::DeleteItem(string data) {
	Item* temp = this->first, *prev = NULL;

	if (temp != NULL && temp->item->GetName() == data)
	{
		this->first = temp->next;   
		free(temp);  
		this->goodsCounter -= 1;
		return;
	}


	while (temp != NULL && temp->item->GetName() != data)
	{
		prev = temp;
		temp = temp->next;
	}
 
	if (temp == NULL) return;
 
	prev->next = temp->next;
	this->goodsCounter -= 1;
	free(temp);
}
void Shop::deleteList()
{
	Item* p = this->first;
	while (p->next != NULL)
	{
		Item* tmp;
		tmp = p;
		p = p->next;
		delete tmp;
	}
	p = p->next;
	delete p;
	this->first = NULL;
}