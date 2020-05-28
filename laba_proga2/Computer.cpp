#include "Computer.h"
#include <iostream>

using namespace std;

Computer::Computer() {
	this->Videocard = "";
	this->Processor = "";
}
Computer::~Computer() {}
Computer::Computer(string processor, string videocard, string name, float price) : Good(name, price) {
	if(!processor.empty() && !videocard.empty())
	this->Processor = processor;
	this->Videocard = videocard;
}
string Computer::getProcessor() {
	return this->Processor;
}
string Computer::getVideocard() {
	return this->Videocard;
}
Computer::Computer(const Computer& item) : Processor(item.Processor), Videocard(item.Videocard), Good(item)
{
}