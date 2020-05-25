// laba_proga2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Shop.h"
#include "Laptop.h"
#include "Desktop.h"
#include "InkPrinter.h"
#include "LaserPrinter.h"
#include "ShopItem.h"
#include <iostream>
#include <string>


void showMenu(Shop& store) {
	int way = 0;
	string str;
	cout << "1. Add store\n";
	cout << "2. Add good\n";
	cout << "3. Show all stores\n";
	cout << "Choose: ";
	cin >> way;
	if (way == 1) {
		cout << "Address: ";
		cin.ignore();
		getline(cin, str);
		ShopItem* item = new ShopItem(str);
		store.addShop(*item);
	}
	else if(way == 2){
		cout << "Address: ";
		cin.ignore();
		getline(cin, str);
		ShopItem* item = &(store.searchObj(str));
		if (item) {
			cout << "What would you want to add?" << endl;
			cout << "1. Laptop\n";
			cout << "2. Desktop\n";
			cout << "3. Laser Printer\n";
			cout << "4. Ink Printer\n";
			cin >> way;
			if (way == 1) {
				Good* good = new Laptop();
				item->addGood(good);
			}

		}
	}
	else if(way == 3){
		store.showAll();
		cout << 1;
	}else {
		cout << "Error!!! Try again!\n";
		return;
	}
	showMenu(store);
}


int main()
{
	string text;
	cout << "Name of store: ";
	cin >> text;
	Shop store(text);
	showMenu(store);
	/*ShopItem new_store("Pushkina 5");
	store.addShop(new_store);
	ShopItem new_store2("Polytechnichna 1");
	store.addShop(new_store2);
	Laptop lptp1("HP Pavilion", "Intel Core-M", "AMD", 1000, 13, true);
	Desktop desk1("HyperPc", "Intel", "AMD", 1400, 2, 700);
	InkPrinter iprint(true, 4, true, 1.5, 500, "Canon");
	LaserPrinter lprint(false, 24, true, 1.2, 700, "Epson");
	LaserPrinter a = lprint;
	new_store2.addGood(&iprint);
	new_store.addGood(&lptp1);
	new_store.addGood(&iprint);
	new_store.addGood(&a);
	new_store.addGood(&desk1);
	new_store.showGoods();
	if (new_store.isExist("Canon")) {
		cout << 1 << endl;
	}
	store.checkGood("Canon");
	cout << "Total: " << new_store.totalPrice();*/
	return 0;
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
