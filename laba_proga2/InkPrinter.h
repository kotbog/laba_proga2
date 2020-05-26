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
	void Print() override;
	InkPrinter& operator= (const InkPrinter& str);
	friend istream& operator>> (istream& in, InkPrinter& item);
private:
	bool PhotoPrint;
	int Colors;
};

