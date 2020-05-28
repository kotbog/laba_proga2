#pragma once

#include <string>

using namespace std;

class Good 
{
public:
	Good(); // конструктор за замовчуванням
	virtual ~Good();
	Good(string, float);
	Good(const Good&);
	string getName();
	float getPrice();
	virtual void Print() = 0;
	void setName(string name);
	void setPrice(float price);
protected:
	string nameGood; 
	float price;
};

