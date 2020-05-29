#pragma once

#include <string>

using namespace std;

class Good 
{
public:
	Good(); // ����������� �� �������������
	virtual ~Good();
	Good(string, float);
	Good(const Good&);
	string getName();
	float getPrice();
	virtual void Print() = 0;
protected:
	string nameGood; 
	float price;
};

