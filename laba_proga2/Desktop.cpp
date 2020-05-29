#include "Desktop.h"
#include <iostream>

using namespace std;

Desktop::Desktop() {
	this->Power = 0;
	this->Weight = 0.0;
}
Desktop::Desktop(const Desktop& item) : Power(item.Power), Weight(item.Weight), Computer(item) 
{
}
Desktop::~Desktop() 
{
}

Desktop::Desktop(string name, string processor, string videocard, float price, float weight, int power) : Computer(processor, videocard, name, price) {
	if (weight > 0 && power > 0) {
		this->Power = power;
		this->Weight = weight;
	}
}


int Desktop::getPower() {
	return this->Power;
}

float Desktop::getWeight() {
	return this->Weight;
}

void Desktop::Print() {
	cout << "Name: " << this->nameGood << "\nPrice: " << this->price << "\nProcessor: " << this->Processor << "\nVideocard: " << this->Videocard << endl;
	cout << "Weight: " << this->Weight << "\nPower: " << this->Power << endl;
}

Desktop& Desktop::operator = (Desktop& str) {
	this->Weight = str.Weight;
	this->Videocard = str.Videocard;
	this->nameGood = str.nameGood;
	this->price = str.price;
	this->Processor = str.Processor;
	this->Power = str.Power;
	return *this;
}

istream& operator>> (istream& in, Desktop& item)
{
	in >> item.nameGood;
	in >> item.price;
	in >> item.Processor;
	in >> item.Videocard;
	in >> item.Power;
	in >> item.Weight;
///"Input with an ENTER( nameGood, price, Processor, Videocard, Power, Weight ): \n"

	return in;
}