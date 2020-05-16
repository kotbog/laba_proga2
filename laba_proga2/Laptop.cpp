#include "Laptop.h"
#include "iostream"

using namespace std;

Laptop::Laptop() : Diagonal(0.0), Ram(0) // конструктор за замовчуванням
{
}
Laptop::~Laptop() 
{
}
Laptop::Laptop(string name, string processor, string videocard, float price, float diagonal, bool webcam) : Computer()
{
	if (diagonal > 0) {
		this->Webcam = webcam;
		this->Diagonal = diagonal;
	}
}

bool Laptop::GetWebcam() { 
	return this->Webcam;
}
double Laptop::GetDiagonal() {
	return this->Diagonal;
}