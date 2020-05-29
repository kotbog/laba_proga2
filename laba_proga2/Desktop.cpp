/*#include "Desktop.h"
#include <iostream>

using namespace std;

template <typename T>
Desktop<T>::Desktop() {
	this->Power = 0;
	this->Weight = 0.0;
}
template <typename T>
Desktop<T>::Desktop(const Desktop& item) : Power(item.Power), Weight(item.Weight), Computer(item) 
{
}
template <typename T>
Desktop<T>::~Desktop() 
{
}
template <typename T>
Desktop<T>::Desktop(string name, string processor, string videocard, float price, float weight, T power) : Computer(processor, videocard, name, price) {
	if (weight > 0 && power > 0) {
		this->Power = power;
		this->Weight = weight;
	}
}

template <typename T>
T Desktop<T>::getPower() {
	return this->Power;
}
template <typename T>
float Desktop<T>::getWeight() {
	return this->Weight;
}
template <typename T>
void Desktop<T>::Print() {
	cout << "Name: " << this->nameGood << "\nPrice: " << this->price << "\nProcessor: " << this->Processor << "\nVideocard: " << this->Videocard << endl;
	cout << "Weight: " << this->Weight << "\nPower: " << this->Power << endl;
}
template <typename T>
Desktop<T>& Desktop<T>::operator = (Desktop<T>& str) {
	this->Weight = str.Weight;
	this->Videocard = str.Videocard;
	this->nameGood = str.nameGood;
	this->price = str.price;
	this->Processor = str.Processor;
	this->Power = str.Power;
	return *this;
}
template <typename T>
istream& operator>> (istream& in, Desktop<T>& item)
{
	in >> item.nameGood;
	in >> item.price;
	in >> item.Processor;
	in >> item.Videocard;
	in >> item.Power;
	in >> item.Weight;
///"Input with an ENTER( nameGood, price, Processor, Videocard, Power, Weight ): \n"

	return in;
}*/