#include "Printer.h"
#include <iostream>

using namespace std;

Printer::Printer() {
	this->Fax = false;
	this->Weight = 0.0;
}
Printer::~Printer() {
}
Printer::Printer(bool fax, float weight, float price, string name) : Good(name, price) {
	if (weight > 0) {
		this->Fax = fax;
		this->Weight = weight;
	}
}
bool Printer::getFax() {
	return this->Fax;
}
float Printer::getWeight() {
	return this->Weight;
}
