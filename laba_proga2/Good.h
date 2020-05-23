#pragma once

#include <string>

using namespace std;

class Good 
{
public:
	Good(); // конструктор за замовчуванням
	~Good();
	Good(string, float);
	string getName();
	float getPrice();
	virtual void Print() = 0;
protected:
	string nameGood; 
	float price;
};

