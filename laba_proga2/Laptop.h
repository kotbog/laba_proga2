#pragma once
#include "Good.h"

class Laptop : public Good 
{
public:
	Laptop();
	~Laptop();
	Laptop(string, float, float, int);
	int GetRam(); // повертає значення оперативної пам'яті
	double GetDiagonal(); // повертає значення оперативної діагональ
	//float GetPrice(); // повертає значення оперативної ціну
	//string GetName(); // повертає значення оперативної ім'я
private:
	int Ram;
	double Diagonal;
};

