#pragma once
#include "Good.h"
class Computer : public Good
{
public:
	Computer();
	~Computer();
	Computer(string, string, string, float);
	virtual void Print() override;
	string getProcessor();
	string getVideocard();
private:
	string Processor;
	string Videocard;
};

