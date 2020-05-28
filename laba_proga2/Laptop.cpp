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
	// Поскольку operator>> является другом класса Point, то мы имеем прямой доступ к членам Point
	// Обратите внимание, параметр point (объект класса Point) должен быть не константным, чтобы мы имели возможность изменить члены класса
	in >> item.nameGood;
	in >> item.price;
	in >> item.Processor;
	in >> item.Videocard;
	in >> item.Diagonal;
	in >> item.Webcam;

	return in;
}