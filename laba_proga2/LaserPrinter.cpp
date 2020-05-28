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
LaserPrinter::LaserPrinter(const LaserPrinter& item) : Speed(item.Speed), Duplex(item.Duplex), Printer(item)
{
}
bool LaserPrinter::getDublex() {
	return this->Duplex;
}
int LaserPrinter::getSpeed() {
	return this->Speed;
}
void LaserPrinter::Print() {
	cout << "Name: " << this->nameGood << "\tPrice: " << this->price << endl;
	cout << "Fax: " << this->Fax << "\tWeight: " << this->Weight << endl;
	cout << "Duplex: " << this->Duplex << "\tSpeed: " << this->Speed << " p/m\n" << endl;
}

bool LaserPrinter::operator == (LaserPrinter& item) {
	if (this->getName() == item.getName()) {
		return 1;
	}
	return 0;
}
LaserPrinter& LaserPrinter::operator= (const LaserPrinter& str)
{
	this->Duplex = str.Duplex;
	this->Speed = str.Speed;
	this->nameGood = str.nameGood;
	this->price = str.price;
	this->Fax = str.Fax;
	this->Weight = str.Weight;
	return *this;
}
istream& operator>> (istream& in, LaserPrinter& item)
{
	// Поскольку operator>> является другом класса Point, то мы имеем прямой доступ к членам Point
	// Обратите внимание, параметр point (объект класса Point) должен быть не константным, чтобы мы имели возможность изменить члены класса
	in >> item.nameGood;
	in >> item.price;
	in >> item.Fax;
	in >> item.Speed;
	in >> item.Duplex;
	in >> item.Weight;

	return in;
}