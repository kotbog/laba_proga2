#pragma once
#include "Good.h"
class Printer : public Good
{
public:
	Printer();
	virtual ~Printer();
	Printer(const Printer&);
	Printer(bool, float, float, string);
	bool getFax();
	float getWeight();
	void virtual Print() = 0;
protected:
	bool Fax;
	float Weight;
};

