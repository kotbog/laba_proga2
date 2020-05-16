#include "Computer.h"
#include <iostream>

using namespace std;

Computer::Computer() {
	this->Videocard = "";
	this->Processor = "";
}
Computer::Computer(string processor, string videocard, string name, float price) : Good(name, price) {
	if(!processor.empty() && !videocard.empty())
	this->Processor = processor;
	this->Videocard = videocard;
}
void Computer::Print() {
	cout << "Name: " << this->GetName() << "\nPrice: " << this->GetPrice() << "\nProcessor: " << this->Processor << "\nVideocard: " << this->Videocard <<endl;
}
string Computer::getProcessor() {
	return this->Processor;
}
string Computer::getVideocard() {
	return this->Videocard;
}