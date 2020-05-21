#pragma once
#include "Printer.h"
class LaserPrinter : public Printer
{
public:
	LaserPrinter();
	~LaserPrinter();
	LaserPrinter(bool duplex, int speed, bool fax, float weight, float price, string name);
	bool getDublex();
	int getSpeed();
	void Print() override;
private: 
	int Speed;
	bool Duplex;
};

