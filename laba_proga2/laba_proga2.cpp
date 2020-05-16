// laba_proga2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Shop.h"
#include "Laptop.h"

#include <iostream>

int main()
{
	Shop store("Citrus");
	Laptop lptp1("HP Pavilion", 1000, 13, 8);
	Laptop lptp2("Macbook Pro", 1300, 16, 16);
	Laptop lptp3("Acer Nitro 5", 1300, 16, 16);
	Laptop lptp4("Lenovo Legion", 1000, 13, 8);
	Laptop lptp5("Samsung", 400.5, 13, 4);
	Laptop lptp6("LG", 600, 13, 6);
	store.addGood(&lptp1);
	store.addGood(&lptp2);
	store.addGood(&lptp3);
	store.addGood(&lptp4);
	store.addGood(&lptp5);
	store.addGood(&lptp6);
	store.showGoods();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
