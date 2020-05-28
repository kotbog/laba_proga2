#include "ShopItem.h"
#include "Shop.h"
#include <string>
#include <iostream>

using namespace std;

int ShopItem::allShopsCounter = 0;
ShopItem::ShopItem() : street(""), goodsCounter(0)
{
	this->pLst = this->lst.begin();
	//ShopItem::allShopsCounter++;
}
ShopItem::~ShopItem() {

}
ShopItem::ShopItem(string streetName) { // конструктор з параметром
	this->street = streetName;
	this->goodsCounter = 0;
	this->pLst = this->lst.begin();
	//ShopItem::allShopsCounter++;
}



void ShopItem::addGood(Good* item) {
	this->lst.push_back(item);
}

void ShopItem::showGoods()
{/*
	if (this->pLst == NULL) // якщо дерево пусте
	{
		cout << "Empty list" << endl;

	}
	else {
		Item* temp = this->first;
		cout << "-------------------" << endl;
		while (temp->next != NULL) {
			temp->item->Print();
			cout << "********************" << endl;
			temp = temp->next;
		}
		temp->item->Print();
		cout << "********************" << endl;
		cout << "Number of goods: " << this->goodsCounter << endl;
	}*/
	this->pLst = this->lst.begin();
	while (this->pLst != this->lst.end()) {
		(*(this->pLst))->Print();
		this->pLst++;
	}
}
void ShopItem::DeleteItem(string data) {
	/*
	Item* temp = this->first, * prev = NULL;

	if (temp != NULL && temp->item->getName() == data)
	{
		
		this->first = temp->next;
		free(temp);
		this->goodsCounter -= 1;
		return;
	}


	while (temp != NULL && temp->item->getName() != data)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) return;

	prev->next = temp->next;
	this->goodsCounter -= 1;
	free(temp);
	*/
	this->pLst = this->lst.begin();
	while (this->pLst != this->lst.end()) {
		if ((*(this->pLst))->getName() == data) {
			this->lst.erase(this->pLst);
			return;
		}
		this->pLst++;
	}
}
void ShopItem::deleteList()
{
	this->lst.clear();
}
/*Item* ShopItem::operator[] (string name) {
	Item* tmp = this->first;
	while (tmp) {
		if (name == tmp->item->getName()) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return 0;
}*/
float ShopItem::totalPrice() {
	float total = 0;
	this->pLst = this->lst.begin();
	while (this->pLst != this->lst.end()) {
		total += (*(this->pLst))->getPrice();
		this->pLst++;
	}
	return total;
}
bool ShopItem::isExist(string name) {
	this->pLst = this->lst.begin();
	while (this->pLst != this->lst.end()) {
		if ((*(this->pLst))->getName() == name)
			return true;
		this->pLst++;
	}
	return false;
}
string ShopItem::getStreet() {
	return this->street;
}
ostream& operator << (ostream& out, ShopItem& item) {
	return out << item.street << "\t" << item.goodsCounter << " goods" << endl;
}
ShopItem& ShopItem::operator= (const ShopItem& str)
{
/*	// Если m_data уже имеет значение, то удаляем это значение
	if (this->first) {
		delete[] this->first;
 	}
	this->first = str.first;
	this->goodsCounter = str.goodsCounter;
	this->street = str.street;
	*/
	return *this;
}
bool ShopItem::operator==(const ShopItem& item) {
	if (this->street == item.street && this->goodsCounter == item.goodsCounter) {
		return 1;
	}
	return 0;
}
ShopItem& ShopItem::operator - (string name) {
	DeleteItem(name);
	return *this;
}
int ShopItem::getShopsCounter() {
	return allShopsCounter;
}
void ShopItem::decrCounter() {
	allShopsCounter -= 1;
}
void ShopItem::incrCounter() {
	allShopsCounter += 1;
}
/*
Item* Shop::sort()
{
	Item* new_root = NULL;

	while (this->first != NULL)
	{
		Item* node = this->first;
		this->first = this->first->next;

		if (new_root == NULL || node->item->getRam() < new_root->item->getRam())
		{
			node->next = new_root;
			new_root = node;
		}
		else
		{
			Item* current = new_root;
			while (current->next != NULL && !(node->item->getRam() < current->next->item->getRam()))
			{
				current = current->next;
			}

			node->next = current->next;
			current->next = node;
		}
	}

	return new_root;
}
*/