#include "Laptop.h"
#include "iostream"

using namespace std;

Laptop::Laptop() : Diagonal(0.0), Ram(0) // конструктор за замовчуванням
{
}
Laptop::~Laptop() 
{
}
Laptop::Laptop(string name, float price, float diagonal, int ram) : Good(name, price)
{
	if (diagonal > 0 && ram > 0) {
		this->Ram = ram;
		this->Diagonal = diagonal;
	}
}

int Laptop::GetRam() { 
	return this->Ram;
}
double Laptop::GetDiagonal() {
	return this->Diagonal;
}
/*string Laptop::GetName() {
	return this->nameGood;
}
float Laptop::GetPrice() {
	return this->price;
}*/