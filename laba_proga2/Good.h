#pragma once

#include <string>

using namespace std;

class Good 
{
public:
	Good(); // ����������� �� �������������
	~Good();
	Good(string, float);
	string GetName();
	float GetPrice();
	virtual void Print();
protected:
	string nameGood; 
	float price;
};

