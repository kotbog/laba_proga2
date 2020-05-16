#pragma once
#include "Printer.h"
class InkPrinter : public Printer
{
public:
	InkPrinter();
	~InkPrinter();
	InkPrinter(bool, int, bool, float, float, string);
	int getColors();
	bool getPhotoPrint();
	virtual void Print() override;
private:
	bool PhotoPrint;
	int Colors;
};

