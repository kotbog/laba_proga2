#include "LaserPrinter.h"
#include <iostream>

using namespace std;

LaserPrinter::LaserPrinter() {
	this->Duplex = false;
	this->Speed = 0;
}
LaserPrinter::~LaserPrinter() {}
LaserPrinter::LaserPrinter(bool duplex, int speed, bool fax, float weight, float price, string name) : Printer(fax, weight, price, name){
	if (speed > 0) {
		this->Duplex = duplex;
		this->Speed = speed;
	}
}
bool LaserPrinter::getDublex() {
	return this->Duplex;
}
int LaserPrinter::getSpeed() {
	return this->Speed;
}
void LaserPrinter::Print() {
	cout << "Name: " << this->GetName() << "\nPrice: " << this->GetPrice() << endl;
	cout << "Fax: " << this->getFax() << "\nWeight: " << this->getWeight() << endl;
	cout << "Duplex: " << this->Duplex << "\Speed: " << this->Speed << "p/m\n" << endl;
}

