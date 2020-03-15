//YUNPENG LING
//CS 52, Section 4118
//Assignment #4, Problem #A




//Update:  Deleted unnecessary funtion
//This function manipulate the user input as string variable


#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>
#include <ctime>

using namespace std;


//Function declaration

string jumstr(string a);
void countWords(string a);
void countconsonants(string a);


//Main function let user input and make selections

int main()
{
	//Declare variables
	int soviet;
	string ura;

	//Prompt user to enter a string

	cout << "This program let you manipulate a string in different ways!" << endl;
	cout << "Now give a try! Please enter your string: ";
	getline(cin, ura);

	//using a do while loop to execute the string processing

	do {
		cout << endl;
		cout << "USE THIS MENU TO MAINPULATE YOUR STRING" << endl;
		cout << "________________________________________" << endl;
		cout << "1> Inverse String " << endl;
		cout << "2> Reverse String " << endl;
		cout << "3> To Uppercase " << endl;
		cout << "4> Jumble String " << endl;
		cout << "5> Count Number Words " << endl;
		cout << "6> Count Consonants " << endl;
		cout << "7> Enter a different string" << endl;
		cout << "8> Print the String  " << endl;
		cout << "9> Quit" << endl;
		cin >> soviet;


		//use the if else loop to deal with string input
		if (soviet == 1) {
			for (int i = 0; i < ura.length(); i++) {
				if (isupper(ura[i]))
					ura[i] = tolower(ura[i]);
				else if (islower(ura[i]))
					ura[i] = toupper(ura[i]);
			}
			cout << "String inversed" << endl;
		}

		else if (soviet == 2) {
			
			int n = ura.length();

			for (int i = 0; i < n / 2; i++) {

				swap(ura[i], ura[n - i - 1]);
			}
			
			cout << endl;
			cout << "String reversed" << endl;

		}
		else if (soviet == 3) {

			for (size_t i = 0; i < ura.length(); i++) {
				ura[i] = toupper(ura[i]);
			}

			cout << endl;
			cout << "String upcased" << endl;
		}
		else if (soviet == 4) {

			cout << jumstr(ura);

		}
		else if (soviet == 5) {

			countWords(ura);

		}
		else if (soviet == 6) {

			countconsonants(ura);

		}
		else if (soviet == 7) {

			cout << endl;
			cout << "Please enter your new string: ";
			getline(cin, ura);

		}
		else if (soviet == 8) {

			cout << ura << endl;

		}
		else {

			cout << endl;
			cout << "Your selection is invaild  Try again " << endl;

		}


	} while (soviet != 9);
}


//Fixed

string jumstr(string a) {


	srand(time(nullptr));

	for (int i = 0; i < a.length(); ++i) {

		int temp = rand() % a.length();
		char temp2 = a[i];
		a[i] = a[temp];
		a[temp2] = temp;

	}
  
	return a;

}


//Fixed
//This function count the words of user input string
void countWords(string a) {

	//We use the spaces to decide many words in a sentence
	int spaces = 1;


	if (a.empty())
		return;

	for (  size_t i= 0; i < a.length(); i++) {
		if (a[i]==' ') {

			spaces++;

		}


	}
	cout << endl;
	cout << "The string you entered has total " << spaces << " words" << endl;



}


//Fixed

//The count consonats function count the number of consonants
//in the user input string

void countconsonants(string a) {

	int vowels = 0;
	

	for (size_t i = 0; i < a.length(); i++) {

		a[i] = toupper(a[i]);

		if (a[i] != 'A'&&a[i] != 'E'&&a[i] != 'I'&&a[i] != 'O'&&a[i] != 'U')
		{

			vowels++;

		}
	}
	cout << endl;
	cout << "There are " << a.length() - vowels << " consonants in your string " << endl;
}