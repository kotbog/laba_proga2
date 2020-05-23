#include "Desktop.h"
#include <iostream>

using namespace std;

Desktop::Desktop() {
	this->Power = 0;
	this->Weight = 0.0;
}
Desktop::~Desktop() {
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
	cout << "Name: " << this->getName() << "\nPrice: " << this->getPrice() << "\nProcessor: " << this->getProcessor() << "\nVideocard: " << this->getVideocard() << endl;
	cout << "Weight: " << this->Weight << "\nPower: " << this->Power << endl;
}