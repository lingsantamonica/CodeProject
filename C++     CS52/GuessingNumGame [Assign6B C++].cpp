
//YUNPENG LING
//CS 52, Section 4118
//Assignment #6, Problem #B
//This program let user guessing numbers from 1 to 10
//User has to bet before they start the game


#include <iostream>
#include <string> // Needed to use strings
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
 
 
//Function declaration
void drawLine(int n, char symbol);
void rules();
 
 
 
 
int main()
{
    string playerName;
    int amount; // hold player's account balance 
    int bettingAmount; 
    int guess;
    int dice; // the dice hold computer generated number
    char choice;
 
    srand(time(0)); 
	
	
	//Stars here
    drawLine(60,'_');
    cout << "\n\t\tGOT THE RIGHT NUMBER\n";
    drawLine(60,'_');
 
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);
 
    cout << "\n\nEnter Desired Deposit amount to bet : $";
    cin >> amount;
    
	
	//A do while loop to proceed game 
    do
    {
        system("cls");
        rules();
        cout << "\nYour current balance is $ " << amount << "\n";
		
		// do while loop to get player's betting amount
        do
        {
            cout <<playerName<<", enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Sorry you don't have enough balance in your account\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
 
		//do while loop to get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);
 
 
 
 
        dice = rand()%10 + 1; // hold the random integer 
    
        if(dice == guess)
        {
            cout << "\n\nJack Pot!!! You won Big." << bettingAmount * 20;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Not this time !! You lost $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }
 
        cout << "\nThe winning number is : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You don't have enough credit to continue ";
            break;
        }
        cout << "\n\n-->Do you want to play again (Y/N)? ";		
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n";
    drawLine(60,'=');
    cout << "\nThanks for playing. Your balance is $ " << amount << "\n";
    drawLine(60,'=');
 
    return 0;
}
 
 
 
 
//Draw lines on the screen
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}



 
 
//Display rules to user
void rules()
{
    system("cls");
    cout << "\n";
    drawLine(70,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 20 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting\n";
	cout << "Good Luck\n";
	
    drawLine(80,'-');
}



