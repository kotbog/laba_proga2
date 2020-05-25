#include "InkPrinter.h"
#include <iostream>

using namespace std;

InkPrinter::InkPrinter() {
	this->Colors = 0;
	this->PhotoPrint = false;
}
InkPrinter::~InkPrinter() {
}
InkPrinter::InkPrinter(bool photoprint, int colors, bool fax, float weight, float price, string name) : Printer(fax, weight, price, name) {
	if (colors > 0) {
		this->Colors = colors;
		this->PhotoPrint = photoprint;
	}
}
bool InkPrinter::getPhotoPrint() {
	return this->PhotoPrint;
}
int InkPrinter::getColors() {
	return this->Colors;
}
void InkPrinter::Print() {
	cout << "Name: " << this->nameGood << "\nPrice: " << this->price << endl;
	cout << "Fax: " << this->Fax << "\nWeight: " << this->Weight << endl;
	cout << "Photo-Print: " << this->PhotoPrint << "\nColors: " << this->Colors << endl;
}
InkPrinter& InkPrinter::operator= (const InkPrinter& str)
{
	this->Colors = str.Colors;
	this->PhotoPrint = str.PhotoPrint;
	this->nameGood = str.nameGood;
	this->price = str.price;
	this->Fax = str.Fax;
	this->Weight = str.Weight;
	return *this;
}