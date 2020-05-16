#pragma once

#include <string>

using namespace std;

class Good 
{
public:
	Good(); // конструктор за замовчуванням
	~Good();
	Good(string, float);
	string GetName();
	float GetPrice();
protected:
	string nameGood; 
	float price;
};

