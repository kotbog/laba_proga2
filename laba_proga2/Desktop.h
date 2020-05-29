#pragma once
#include "Computer.h"


template <typename T1, typename T2>
class Desktop : public Computer
{
public:
	Desktop();
	~Desktop();
	Desktop(const Desktop&);
	Desktop(string name, string processor, string videocard, float price, T2 weight, T1 power);
	T1 getPower();
	T2 getWeight();
	virtual void Print() override;
	Desktop& operator = (Desktop&);
	template <typename T1, typename T2>
	friend istream& operator>> (istream& in, Desktop<T1, T2>& item);
private:
	T2 Weight;
	T1 Power;
};

template <typename T1, typename T2>
Desktop<T1, T2>::Desktop() {
	this->Power = 0;
	this->Weight = 0.0;
}
template <typename T1, typename T2>
Desktop<T1, T2>::Desktop(const Desktop& item) : Power(item.Power), Weight(item.Weight), Computer(item)
{
}
template <typename T1, typename T2>
Desktop<T1, T2>::~Desktop()
{
}
template <typename T1, typename T2>
Desktop<T1, T2>::Desktop(string name, string processor, string videocard, float price, T2 weight, T1 power) : Computer(processor, videocard, name, price) {
	if (weight > 0 && power > 0) {
		this->Power = power;
		this->Weight = weight;
	}
}

template <typename T1, typename T2>
T1 Desktop<T1, T2>::getPower() {
	return this->Power;
}
template <typename T1, typename T2>
T2 Desktop<T1, T2>::getWeight() {
	return this->Weight;
}
template <typename T1, typename T2>
void Desktop<T1, T2>::Print() {
	cout << "Name: " << this->nameGood << "\nPrice: " << this->price << "\nProcessor: " << this->Processor << "\nVideocard: " << this->Videocard << endl;
	cout << "Weight: " << this->Weight << "\nPower: " << this->Power << endl;
}
template <typename T1, typename T2>
Desktop<T1, T2>& Desktop<T1, T2>::operator = (Desktop<T1, T2>& str) {
	this->Weight = str.Weight;
	this->Videocard = str.Videocard;
	this->nameGood = str.nameGood;
	this->price = str.price;
	this->Processor = str.Processor;
	this->Power = str.Power;
	return *this;
}
template <typename T1, typename T2>
istream& operator>> (istream& in, Desktop<T1, T2>& item)
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





