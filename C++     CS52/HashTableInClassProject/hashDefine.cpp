#include "hash.h"



//Constructor of hashTable class
hashTable::hashTable(){

	for (int i = 0; i < tableSize;i++)
	{
		Hash1[i] = new item;
		Hash1[i]->name = "NULL";
		Hash1[i]->drink = "NULL";
		Hash1[i]->next = NULL;

	}
}

int hashTable::Hash(string key)
{
	int hash = 0;
	int index;

	key.length();

	index = key.length();
	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
	}

	index = hash % tableSize;
	return index;

}

void hashTable::addItem(string name, string drink)
{
	int index = Hash(name);

	//overwrite the item if it is in default status
	if (Hash1[index]->name == "NULL")
	{
		Hash1[index]->name = name;
		Hash1[index]->drink = drink;
	}
	else
	{
		//If the index is not empty
		//create a pointer point to the new item
		item* ptr = Hash1[index];
		item* n = new item;
		n->name = name;
		n->drink = drink;
		n->next = NULL;

		//use while function to let the point travel to
		//the end of the list
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}

		//link the item point to the newly created item
		ptr->next = n;


	}



}

int hashTable::NumberOfItems(int index)
{
	int count = 0;

	//base case
	//Return 0 if the index is empty
	if (Hash1[index]->name == "NULL")
	{
		return count;
	}
	else
	{
		count++;
		item* ptr = Hash1[index];
		while (ptr->next != NULL)
		{
			count++;
		    ptr = ptr->next;
		}
	}

	return count;
	
}

void hashTable::PrintTable()
{
	int number;

	//use for loop to go through the hash table
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItems(i);
		cout << "------------------------\n";
		cout << "index # " << i << endl;
		cout <<"name: "<< Hash1[i]->name << endl;
		cout <<"Favorite drink: "<< Hash1[i]->drink << endl;
		cout << "# of records: " << number << endl;
		cout << "----------------------------\n";
	}
}

//This function print out all the items in one index in case if there's more than one
void hashTable::PrintItemsInIndex(int index)
{

	item* ptr = Hash1[index];

	if (ptr->name == "NULL")
	{
		cout << "index= " << index << " is empty";

	}
	else
	{
		cout << "index" << index << " contains the following item\n";

		while (ptr != NULL)
		{
			cout << "-------------------\n";
			cout << ptr->name << endl;
			cout << ptr->drink << endl;
			cout << "----------------------\n";
			ptr = ptr->next;
		}
	}


}