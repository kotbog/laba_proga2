#pragma once
#include "Good.h"

class Laptop : public Good 
{
public:
	Laptop();
	~Laptop();
	Laptop(string, float, float, int);
	int GetRam(); // ������� �������� ���������� ���'��
	double GetDiagonal(); // ������� �������� ���������� ��������
	//float GetPrice(); // ������� �������� ���������� ����
	//string GetName(); // ������� �������� ���������� ��'�
private:
	int Ram;
	double Diagonal;
};

