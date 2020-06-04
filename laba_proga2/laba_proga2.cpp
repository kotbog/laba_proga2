// laba_proga2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Shop.h"
#include "Laptop.h"
#include "Desktop.h"
#include "InkPrinter.h"
#include "LaserPrinter.h"
#include "ShopItem.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

ShopItem* searchByAddress(Shop& store) {
	string str;
	cout << "Address: ";
	cin.ignore();
	getline(cin, str);
	ShopItem* item = store.searchObj(str);
	return item;
}
/*
void addDesktop(Shop& store, ifstream &fin) {
	string name, processor, videocard;
	float weight, price;
	int power;
	//string name, string processor, string videocard, float price, float weight, int power
	ShopItem* item = searchByAddressFile(store, fin);
	if (item){ 
		getline(fin, name);
		getline(fin, processor);
		getline(fin, videocard);
		fin >> price;
		fin >> weight;
		fin >> power;
		Desktop* good = new Desktop(name, processor, videocard, price, weight, power);
		item->addGood(good);
	}
	else {
		cout << "Error!" << endl;
	}
}

void addLaptop(Shop& store, ifstream& fin) {
	string name, processor, videocard;
	float diagonal, price;
	bool webcam;
	ShopItem* item = searchByAddressFile(store, fin);
	if (item) {
		getline(fin, name);
		getline(fin, processor);
		getline(fin, videocard);
		fin >> price;
		fin >> diagonal;
		fin >> webcam;
		Laptop* good = new Laptop(name, processor, videocard, price, diagonal, webcam);
		item->addGood(good);
	}
	else {
		cout << "Error!" << endl;
	}
}
void addLaserPrinter(Shop& store, ifstream& fin) {
	string name;
	int speed;
	float weight, price;
	bool fax;
	bool duplex;
	ShopItem* item = searchByAddressFile(store, fin);
	//bool duplex, int speed, bool fax, float weight, float price, string name
	if (item) {
		getline(fin, name);
		fin >> price;
		fin >> weight;
		fin >> fax;
		fin >> duplex;
		fin >> speed;
		LaserPrinter* good = new LaserPrinter(duplex, speed, fax, weight, price, name);
		item->addGood(good);
	}
	else {
		cout << "Error!" << endl;
	}
}

void addInkPrinter(Shop& store, ifstream& fin) {
	string name;
	int colors;
	float weight, price;
	bool fax, photoprint;
	ShopItem* item = searchByAddressFile(store, fin);
	//bool duplex, int speed, bool fax, float weight, float price, string name
	if (item) {
		getline(fin, name);
		fin >> price;
		fin >> weight;
		fin >> fax;
		fin >> colors;
		fin >> photoprint;
		InkPrinter* good = new InkPrinter(photoprint, colors, fax, weight, price, name);
		item->addGood(good);
	}
	else {
		cout << "Error!" << endl;
	}
}

void addGoodFromFile(Shop& store) {
	string way;
	ifstream fin("goods.txt");

	if (!fin) {
		cout << "File Error!" << endl;
		return;
	}
	while (!fin.eof()) {
		fin >> way;
		ShopItem* item = searchByAddressFile(store, fin);
		if (item) {
			if (way == "laptop") {
				addLaptop(store, fin);
			}
			else if (way == "desktop") {
				addDesktop(store, fin);
			}
			else if (way == "inkprinter") {
				addInkPrinter(store, fin);
			}
			else if (way == "laserprinter") {
				addLaserPrinter(store, fin);
			}
		}
		else {
			cout << "Error!\n";
		}
	}
}*/




void addGoodFromConsole(Shop& store, int way) {
	ShopItem* item = searchByAddress(store);
	if (item) {

		if (way == 1) {
			Laptop* good = new Laptop();
			cout << "Input with an ENTER( nameGood, price, Processor, Videocard, Diagonal, Webcam ): \n";
			cin >> *(good);
			item->addGood(good);
		}
		else if (way == 2) {
			Desktop* good = new Desktop();
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
void add_laptop(ifstream &file, Shop &store) {
	string line;//Строчка текста
	while (getline(file, line, '\n'))
	{
		//cout << line << endl;//Можно посмотреть, что в строчке считалось

		//Теперь в line хранится содержимое строчки из файла.
		//Будем её разбирать на составные части.

		//В нашем файле идут две строчки, а потом два числа
		
		string name, processor, videocard, street;
		float diagonal, price;
		bool webcam;

		//Создадим поток для считывания данных из строчки
		istringstream iss(line);

		string token;
		int i = 0;
		while (getline(iss, token, ',')) {
			if (i == 0) street = token;
			if (i == 1) name = token;
			if (i == 2) processor = token;
			if (i == 3) videocard = token;//перевод string в int
			if (i == 4) price = atof(token.c_str());//перевод string в float
			if (i == 5) diagonal = atof(token.c_str());//перевод string в int
			if (i == 6) webcam = atoi(token.c_str());//перевод string в int
			i++;
		}
		Laptop* good = new Laptop(name, processor, videocard, price, diagonal, webcam);
		ShopItem* item = store.searchObj(street);
		if (item) {
			item->addGood(good);
		}
		else {
			ShopItem* item2 = new ShopItem(street);
			item2->addGood(good);
			store.addShop(*item2);
		}
		break;
	}
}
void add_desktop(ifstream& file, Shop& store) {
	string line;//Строчка текста
	while (getline(file, line, '\n'))
	{
		//cout << line << endl;//Можно посмотреть, что в строчке считалось

		//Теперь в line хранится содержимое строчки из файла.
		//Будем её разбирать на составные части.

		//В нашем файле идут две строчки, а потом два числа
		string name, processor, videocard, street;
		float weight, price;
		int power;

		//Создадим поток для считывания данных из строчки
		istringstream iss(line);

		string token;
		int i = 0;
		while (getline(iss, token, ',')) {
			if (i == 0) street = token;
			if (i == 1) name = token;
			if (i == 2) processor = token;
			if (i == 3) videocard = token;//перевод string в int
			if (i == 4) price = atof(token.c_str());//перевод string в float
			if (i == 5) weight = atof(token.c_str());//перевод string в int
			if (i == 6) power = atoi(token.c_str());//перевод string в int
			i++;
		}
		Desktop* good = new Desktop(name, processor, videocard, price, weight, power);
		ShopItem* item = store.searchObj(street);
		if (item) {
			item->addGood(good);
		}
		else {
			ShopItem* item2 = new ShopItem(street);
			item2->addGood(good);
			store.addShop(*item2);
		}
		break;
	}
}
void add_inkPrinter(ifstream& file, Shop& store) {
	string line;//Строчка текста
	while (getline(file, line, '\n'))
	{
		//cout << line << endl;//Можно посмотреть, что в строчке считалось

		//Теперь в line хранится содержимое строчки из файла.
		//Будем её разбирать на составные части.

		//В нашем файле идут две строчки, а потом два числа

		string name, street;
		int colors;
		float weight, price;
		bool fax, photoprint;

		//Создадим поток для считывания данных из строчки
		istringstream iss(line);

		string token;
		int i = 0;
		while (getline(iss, token, ',')) {
			if (i == 0) street = token;
			if (i == 1) name = token;
			if (i == 2) fax = atoi(token.c_str());
			if (i == 3) weight = atof(token.c_str());
			if (i == 4) price = atof(token.c_str());
			if (i == 5) photoprint = atoi(token.c_str());
			if (i == 6) colors = atoi(token.c_str());//перевод string в int
			i++;
		}
		InkPrinter* good = new InkPrinter(photoprint, colors, fax, weight, price, name);
		ShopItem* item = store.searchObj(street);
		if (item) {
			item->addGood(good);
		}
		else {
			ShopItem* item2 = new ShopItem(street);
			item2->addGood(good);
			store.addShop(*item2);
		}
		break;
	}
}
void add_laserPrinter(ifstream& file, Shop& store) {
	string line;//Строчка текста
	while (getline(file, line, '\n'))
	{
		//cout << line << endl;//Можно посмотреть, что в строчке считалось

		//Теперь в line хранится содержимое строчки из файла.
		//Будем её разбирать на составные части.

		//В нашем файле идут две строчки, а потом два числа

		string name, street;
		int speed;
		float weight, price;
		bool fax;
		bool duplex;

		//Создадим поток для считывания данных из строчки
		istringstream iss(line);

		string token;
		int i = 0;
		while (getline(iss, token, ',')) {
			if (i == 0) street = token;
			if (i == 1) name = token;
			if (i == 2) fax = atoi(token.c_str());
			if (i == 3) weight = atof(token.c_str());
			if (i == 4) price = atof(token.c_str());
			if (i == 5) duplex = atoi(token.c_str());
			if (i == 6) speed = atoi(token.c_str());//перевод string в int
			i++;
		}
		LaserPrinter* good = new LaserPrinter(duplex, speed, fax, weight, price, name);
		ShopItem* item = store.searchObj(street);
		if (item) {
			item->addGood(good);
		}
		else {
			ShopItem* item2 = new ShopItem(street);
			item2->addGood(good);
			store.addShop(*item2);
		}
		break;
	}
}
void addGoodFromFile(Shop &store) {

	ifstream file("goods.txt");

	if (file.is_open())//Если открытие файла прошло успешно
	{
		cout << "Read from file." << endl;

		string line;//Строчка текста
		while (!file.eof()) {
			getline(file, line, ',');
			if (line == "laptop") {
				add_laptop(file, store);
			}
			else if (line == "desktop") {
				add_desktop(file, store);
			}else if(line == "ink-printer") {
				add_inkPrinter(file, store);
			}
			else if(line == "laser-printer"){
				add_laserPrinter(file, store);
			}
		}
	}
	else
	{
		cout << "File error." << endl;
	}
}
/*int addGoodFromFile() {
	int num;
	ifstream fin("goods.txt");
	if (!fin.is_open()) {
		cout << "ERROR!!!" << endl;
		return -1;
	}
	else {
		//fin >> name;
		while (!fin.eof()) {
			fin >> num;
			cout << num << endl;
		}
		fin.close();
	}
}*/








/*---------------------------------*/
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
	switch (way)
	{
	case 1:
	{
		cout << "Address: ";
		cin.ignore();
		getline(cin, str);
		ShopItem* item = new ShopItem(str);
		if (store.searchObj(str) == NULL) {
			store.addShop(*item);
		}
		addGoodFromFile(store);
		showMenu(store);
		break;
	}
	case 2:
	{
		cout << "What would you want to add?" << endl;
		cout << "1. Laptop\n";
		cout << "2. Desktop\n";
		cout << "3. Laser Printer\n";
		cout << "4. Ink Printer\n";
		cin >> way;
		addGoodFromConsole(store, way);
		showMenu(store);
		break;
	}
	case 3: 
	{
		store.showAll();
		showMenu(store);
		break;
	}
	case 4: 
	{
		ShopItem* item = searchByAddress(store);
		if (item) {
			item->showGoods();
		}
		showMenu(store);
		break;
	}
	case 5: 
	{
		ShopItem* item = searchByAddress(store);
		if (item) {
			cout << "Name: ";
			cin >> str;
			item->DeleteItem(str);
		}
		//*item - str;
		showMenu(store);
		break;
	}
	case 6: 
	{
		cout << "Name: ";
		cin >> str;
		store.checkGood(str);
		showMenu(store);
		break;
	}
	case 7:
	{
		ShopItem* item = searchByAddress(store);
		store.deleteShop(item);
		showMenu(store);
		break;
	}
	case 0: 
	{
		return;
	}
	default:
		cout << "Enter error! TRY AGAIN!!!" << endl;
		showMenu(store);
		break;
	}
	/*
	if (way == 1) {
		cout << "Address: ";
		cin.ignore();
		getline(cin, str);
		ShopItem* item = new ShopItem(str);
		if (store.searchObj(str) == NULL) {
			store.addShop(*item);
			addGoodFromFile(store);
		}
		else {
			cout << "Error! There is already " << str << endl;
		}
	}
	else if(way == 2){
		cout << "What would you want to add?" << endl;
		cout << "1. Laptop\n";
		cout << "2. Desktop\n";
		cout << "3. Laser Printer\n";
		cout << "4. Ink Printer\n";
		cin >> way;
		addGoodFromConsole(store, way);
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
	*/
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

