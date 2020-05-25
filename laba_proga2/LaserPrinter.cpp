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
	cout << "Name: " << this->getName() << "\nPrice: " << this->getPrice() << endl;
	cout << "Fax: " << this->getFax() << "\nWeight: " << this->getWeight() << endl;
	cout << "Duplex: " << this->Duplex << "\nSpeed: " << this->Speed << " p/m\n" << endl;
}

bool LaserPrinter::operator == (LaserPrinter& item) {
	if (this->getName() == item.getName()) {
		return 1;
	}
	return 0;
}
LaserPrinter& LaserPrinter::operator= (const LaserPrinter& str)
{
	// ���� m_data ��� ����� ��������, �� ������� ��� ��������
	this->Duplex = str.Duplex;
	this->Speed = str.Speed;



	return *this;
}