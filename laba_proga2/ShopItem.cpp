#include "ShopItem.h"
#include "Shop.h"
#include <string>
#include <iostream>

using namespace std;

int ShopItem::allShopsCounter = 0;

ShopItem::ShopItem() : street(""), goodsCounter(0)
{
	this->first = NULL;
	this->allShopsCounter++;
}
ShopItem::~ShopItem() {

}
ShopItem::ShopItem(string streetName) { // конструктор з параметром
	this->street = streetName;
	this->goodsCounter = 0;
	this->first = NULL;
	this->allShopsCounter++;
}



Item* ShopItem::addGood(Good* item) {
	if (this->first == NULL)
	{
		this->first = new Item();
		this->first->item = item;
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
void ShopItem::showGoods()
{
	if (this->first == NULL) // якщо дерево пусте
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
	}
}
void ShopItem::DeleteItem(string data) {
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
}
void ShopItem::deleteList()
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
Item* ShopItem::operator[] (string name) {
	Item* tmp = this->first;
	while (tmp) {
		if (name == tmp->item->getName()) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return 0;
}
float ShopItem::totalPrice() {
	Item* tmp = this->first;
	float total = 0;
	while (tmp) {
		total += tmp->item->getPrice();
		tmp = tmp->next;
	}
	return total;
}
bool ShopItem::isExist(string name) {
	Item* tmp = this->first;
	while (tmp != NULL) {
		if (name == tmp->item->getName()) {
			return true;
		}
		tmp = tmp->next;
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
	// Если m_data уже имеет значение, то удаляем это значение
	if (this->first) {
		delete[] this->first;
 	}
	this->first = str.first;
	this->goodsCounter = str.goodsCounter;
	this->street = str.street;
	
	return *this;
}
bool ShopItem::operator==(const ShopItem& item) {
	if (this->street == item.street) {
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
/*Item* Shop::sort()
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