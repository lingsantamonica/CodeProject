//YUNPENG LING
//CS 52, Section 4118
//Assignment #4, Problem #B

//This program simulates a soft drink vending machine

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
struct Drink {

	//Member variables of the structure
	string bevName;
	double bevCost;
	int bevSto;


};




//Main function let user to select their drinks
int main() {

	double gold=0.0;
	double budget;
	int i;
	bool gentleman = true;

	Drink item[6];

	item[0] = { "NukeCola", 70,1 };

	item[1] = { "Cola", 0.65,20 };
	item[2] = { "Root Beer", 0.70,20 };
	item[3] = { "Grape Soda", 0.75,20 };
	item[4] = { "Lemon-Lime", 0.85, 10 };
	item[5] = { "Water", 0.90, 20 };


	//Prompt user to make their choice of drinks
	while(gentleman){

		cout << "                             " << endl;
		cout << "1> Cola         0.65  Qty:" << item[1].bevSto << endl;
		cout << "2> Root Beer    0.70  Qty:" << item[2].bevSto << endl;
		cout << "3> Lemon-Line   0.75  Qty:" << item[3].bevSto << endl;
		cout << "4> Grape Soda   0.80  Qty:" << item[4].bevSto << endl;
		cout << "5> Water        0.90  Qty:" << item[5].bevSto << endl;
		cout << endl;


		cout << "Select a drink <1-5> or enter 6 to quit: " << endl;
		cin >> i;

		//check if user want to end the program
		if(i==6)
		
	{   
 
		cout << endl;
		cout << "Total Revenue: " << gold << endl;

		//display the storage of beverage in the machine
		cout << "Drink             Number Left" << endl;
		cout << "1> Cola          Qty:" << item[1].bevSto << endl;
		cout << "2> Root Beer     Qty:" << item[2].bevSto << endl;
		cout << "3> Lemon-Line    Qty:" << item[3].bevSto << endl;
		cout << "4> Grape Soda    Qty:" << item[4].bevSto << endl;
		cout << "5> Water         Qty:" << item[5].bevSto << endl;


		return 0; }


		//If use didn't enter 6 then weigh the budget
		cout << "Enter the amount of money you want to insert: ";
		cin >> budget;

		//If loop to check user choice input correctness


		if (i < 1 || i>6) {

			cout << "Please only enter integers that correspond to your choice" << endl;
			cout << "           " << endl;
		}

		//If loop to check user input value
		//no less than 0  no bigger than 1
		else if  (budget<0.0 || budget>1.0) {

			cout << "This machine cannot accept values less than 0 or greater than $1.00" << endl;
			cout << endl;
			cout << "Enter the amount of cash you want to insert: ";
			cout << endl;


		}
		else if (budget < item[i].bevCost) {
			
			cout << endl;
			cout << "Insufficient Funds";
			cout << "           " << endl;
			cout << "Please try again" << endl;


		}
		else if (item[i].bevSto < 1) {
			cout << "Sorry the drink sold out  Try others" << endl;


		}
		else {

			cout << "Return Change: $" << budget - item[i].bevCost << endl;
			cout << "      " << endl;

			//Reduce the beverage storage
			item[i].bevSto--;
			gold=+ item[i].bevCost;

		}


	} 

	return 0;

}