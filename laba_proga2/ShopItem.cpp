#include "ShopItem.h"
#include "Shop.h"
#include <string>
#include <iostream>

using namespace std;

int ShopItem::allShopsCounter = 0;
ShopItem::ShopItem() : street(""), goodsCounter(0)
{
	this->pLst = this->lst.begin();
}
ShopItem::~ShopItem() {

}
ShopItem::ShopItem(string streetName) { // конструктор з параметром
	this->street = streetName;
	this->goodsCounter = 0;
	this->pLst = this->lst.begin();
}



void ShopItem::addGood(Good* item) {
	this->goodsCounter++;
	this->lst.push_back(item);
}

void ShopItem::showGoods()
{
	this->pLst = this->lst.begin();
	while (this->pLst != this->lst.end()) {
		cout << "********************" << endl;
		(*(this->pLst))->Print();
		this->pLst++;
	}
	cout << "********************" << endl;
}
void ShopItem::DeleteItem(string data) {
	this->pLst = this->lst.begin();
	while (this->pLst != this->lst.end()) {
		if ((*(this->pLst))->getName() == data) {
			this->lst.erase(this->pLst);
			this->goodsCounter--;
			return;
		}
		this->pLst++;
	}
}
void ShopItem::deleteList()
{
	this->lst.clear();
}

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
void ShopItem::decrCounter() {
	allShopsCounter -= 1;
}
void ShopItem::incrCounter() {
	allShopsCounter += 1;
}
