#pragma once
#include "Computer.h"

class Laptop : public Computer 
{
public:
	Laptop();
	~Laptop();
	Laptop(string, string, string, float, float, bool);
	bool GetWebcam(); // ������� �������� ���������� ���'��
	double GetDiagonal(); // ������� �������� ���������� ��������
private:
	bool Webcam;
	double Diagonal;
};

