#include "Laptop.h"
#include "iostream"

using namespace std;

Laptop::Laptop() : Diagonal(0.0), Webcam(false) // конструктор за замовчуванням
{
}
Laptop::~Laptop() 
{
}
Laptop::Laptop(string name, string processor, string videocard, float price, float diagonal, bool webcam) : Computer(processor, videocard, name, price)
{
	if (diagonal > 0) {
		this->Webcam = webcam;
		this->Diagonal = diagonal;
	}
}
Laptop::Laptop(const Laptop& item) : Diagonal(item.Diagonal), Webcam(item.Webcam), Computer(item)
{
}
bool Laptop::GetWebcam() { 
	return this->Webcam;
}
double Laptop::GetDiagonal() {
	return this->Diagonal;
}
void Laptop::Print() {
	cout << "Name: " << this->nameGood << "\nPrice: " << this->price << "\nProcessor: " << this->Processor << "\nVideocard: " << this->Videocard << endl;
	cout << "Webcam: " << this->Webcam << "\nDiagonal: " << this->Diagonal << endl;
}

Laptop& Laptop::operator= (Laptop& str) {
	this->Diagonal = str.Diagonal;
	this->Videocard = str.Videocard;
	this->nameGood = str.nameGood;
	this->price = str.price;
	this->Processor = str.Processor;
	this->Webcam = str.Webcam;
	return *this;
}
istream& operator>> (istream& in, Laptop& item)
{
	cout << "Name: ";
	in >> item.nameGood;
	cout << "Price: ";
	in >> item.price;
	cout << "Processor: ";
	in >> item.Processor;
	cout << "Videocard: ";
	in >> item.Videocard;
	cout << "Diagonal: ";
	in >> item.Diagonal;
	cout << "Webcam(bool): ";
	in >> item.Webcam;

	return in;
}