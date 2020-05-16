#pragma once
#include "Computer.h"
class Desktop : public Computer
{
public:
	Desktop();
	~Desktop();
	Desktop(string name, string processor, string videocard, float price, float weight, int power);
	int getPower();
	float getWeight();
	virtual void Print() override;
private:
	float Weight;
	int Power;
};
