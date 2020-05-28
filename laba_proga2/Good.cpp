#include "Good.h"
#include <string>
#include <iostream>

using namespace std;

Good::Good() : nameGood(""), price(0.0) 
{
}
Good::~Good() 
{
}
Good::Good(string name, float price) 
{
	if (price > 0 && !name.empty()) {
		this->price = price;
		this->nameGood = name;
	}
}
string Good::getName() {
	return this->nameGood;
}
float Good::getPrice() {
	return this->price;
}
void Good::setName(string name) {
	this->nameGood = name;
}
void Good::setPrice(float price) {
	this->price = price;
}

Good::Good(const Good& item) : nameGood(item.nameGood), price(item.price)
{
}