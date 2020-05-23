#pragma once
#include "Good.h"
class Printer : public Good
{
public:
	Printer();
	~Printer();
	Printer(bool, float, float, string);
	bool getFax();
	float getWeight();
	void virtual Print() = 0;
private:
	bool Fax;
	float Weight;
	Item* first;
};

