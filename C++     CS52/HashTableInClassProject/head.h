#pragma once
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

class hashTable {

private:
	static const int tableSize=10;
	
	//create a struct contains name drink and a pointer
	struct item {

		string  name;
		string drink;
		item* next;
	};

	item* Hash1[tableSize];


public:

	hashTable();
	int Hash(string key);
	void addItem(string name, string drink);
	int NumberOfItems(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);



};