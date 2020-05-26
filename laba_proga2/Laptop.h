#pragma once
#include "Computer.h"

class Laptop : public Computer 
{
public:
	Laptop();
	~Laptop();
	Laptop(string, string, string, float, float, bool);
	bool GetWebcam(); // повертає значення оперативної пам'яті
	double GetDiagonal(); // повертає значення оперативної діагональ
	virtual void Print() override;
	Laptop& operator = (Laptop&);
	friend istream& operator>> (istream& in, Laptop& item);
private:
	bool Webcam;
	double Diagonal;
};

