//YUNPENG LING
//CS 20A Section 4098
//In class project 7 
//This program create a HashTable that stores peoples names and their 
//favorite drinks


// HashTable[Assign7B DataStructureWtih C++].cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "hash.h"


int main()
{


	//create a hash table 
	hashTable losangeles;

	//Add items in it
	losangeles.addItem("Ling", "Whiskey");
	losangeles.addItem("Marco", "TEQUILA");
	losangeles.addItem("Kupper", "WeizenbierNWeisbier");
	losangeles.addItem("Samarito", "Miller");
	

	//print out the table
	losangeles.PrintTable();

	//Print out the another object in the index # if there's more than one
	//losangeles.PrintItemsInIndex( );
	


	return 0;

}