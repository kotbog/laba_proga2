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

ShopItem* searchByAddress(Shop& store) {
	string str;
	cout << "Address: ";
	cin.ignore();
	getline(cin, str);
	ShopItem* item = store.searchObj(str);
	return item;
}
void showMenu(Shop& store) {
	int way = 0;
	string str;
	cout << "0. Exit\n";
	cout << "1. Add store\n";
	cout << "2. Add good\n";
	cout << "3. Show all stores\n";
	cout << "4. Show all goods\n";
	cout << "5. Delete good\n";
	cout << "6. Check availability\n";
	cout << "7. Delete Shop\n";
	cout << "Choose: ";
	cin >> way;
	if (way == 1) {
		cout << "Address: ";
		cin.ignore();
		getline(cin, str);
		ShopItem* item = new ShopItem(str);
		if (store.searchObj(*item) == NULL) {
			store.addShop(*item);
		}
		else {
			store.deleteShop(item);
			cout << "Error! There is already " << str << endl;
		}
	}
	else if(way == 2){
		ShopItem* item = searchByAddress(store);
		if (item) {
			cout << "What would you want to add?" << endl;
			cout << "1. Laptop\n";
			cout << "2. Desktop\n";
			cout << "3. Laser Printer\n";
			cout << "4. Ink Printer\n";
			cin >> way;
			if (way == 1) {
				Laptop* good = new Laptop();
				cout << "Input with an ENTER( nameGood, price, Processor, Videocard, Diagonal, Webcam ): \n";
				cin >> *(good);
				item->addGood(good);
			}
			else if (way == 2) {
				Desktop<int, float>* good = new Desktop<int, float>();
				cout << "Input with an ENTER( nameGood, price, Processor, Videocard, Power, Weight ): \n";
				cin >> *(good);
				item->addGood(good);
			}
			else if (way == 3) {
				LaserPrinter* good = new LaserPrinter();
				cout << "Input with an ENTER( nameGood, price, Fax(bool), Speed, Duplex, Weight ): \n";
				cin >> *(good);
				item->addGood(good);
			}
			else if (way == 4) {
				InkPrinter* good = new InkPrinter();
				cout << "Input with an ENTER( nameGood, price, Fax(bool), PhotoPrint(bool), Colors, Weight ): \n";
				cin >> *(good);
				item->addGood(good);
			}

		}
		else {
			cout << "Error!\n";
		}
	}
	else if(way == 3){
		store.showAll();
	}
	else if (way == 4) {
		ShopItem* item = searchByAddress(store);
		item->showGoods();
	}
	else if (way == 5) {
		ShopItem* item = searchByAddress(store);
		cout << "Name: ";
		cin >> str;
		item->DeleteItem(str);
		//*item - str;
	}
	else if (way == 6) {
		cout << "Name: ";
		cin >> str;
		store.checkGood(str);
	}
	else if (way == 7) {
		ShopItem* item = searchByAddress(store);
		store.deleteShop(item);
	}
	else if (way == 0) {
		exit(0);
	}
	else{
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
	return 0;
}

