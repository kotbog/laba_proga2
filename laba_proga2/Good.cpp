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
string Good::GetName() {
	return this->nameGood;
}
float Good::GetPrice() {
	return this->price;
}
void Good::Print() {
	cout << "Name: " << this->nameGood << "\nPrice: " << this->price << endl;
}


