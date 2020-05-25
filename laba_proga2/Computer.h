#pragma once
#include "Good.h"
class Computer : public Good
{
public:
	Computer();
	~Computer();
	Computer(string, string, string, float);
	Computer(const Computer&);
	virtual void Print() = 0;
	string getProcessor();
	string getVideocard();
protected:
	string Processor;
	string Videocard;
};

