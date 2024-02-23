// ------------------------------------------------------------------------
// Name: 0221
// Course-Section: CS 155-section 02
// Assignment: Assignment 5
// Date due: 02/23/2024
// Resources: None 
// Description: 
// ------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	float checkings = 1350, savings = 780 , deposit = 0, withdraw = 0;
	char userOption;
	
	cout << "*** DEWEY, CHEATUM, & HOWE BANK ***" << endl 
	     << "A - Withdraw from Checkings" << endl
		 << "B - Withdraw from Savings" << endl
		 << "C - Deposit to Checkings" << endl << "D - Deposit to Savings"
		 << endl << "Enter: ";
	cin >> userOption;
	
	cout << fixed << setprecision(2);
	
	if ((userOption != 'A') && (userOption != 'B') && 
	   (userOption != 'C') && (userOption != 'D')) {
		cout << endl << "ERROR - INVALID OPTION"  << endl << "Checkings: $" 
			 << checkings << endl << "Savings: $" << savings; 
	}
	
	if (userOption == 'A'){ 
		cout << endl << "How much will you Withdraw from Checkings: ";
		cin >> withdraw;
			if ((withdraw < 0) || (withdraw > checkings)){
				cout << "ERROR - INVALID WITHDRAW AMOUNT" <<endl
					 << "Checkings: $" << checkings << endl 
					 << "Savings: $" << savings; 
				}
			else {
				checkings = checkings - withdraw; 
				cout << "Checkings: $" << checkings << endl << "Savings: $"
					 << savings; 
			}
		}
	else if (userOption == 'B'){
		cout << endl << "How much do you want to Withdraw from Savings: ";
		cin >> withdraw;
			if  ((withdraw < 0) || (withdraw > savings )){
				cout << "ERROR - INVALID WITHDRAW AMOUNT" << endl
				     << "Checkings: $" << checkings << endl << "Savings: $"
				     << savings;
			}
			else {
				savings = savings - withdraw;
				cout << "Checkings: $" << checkings << endl << "Savings: $"
					 << savings;
				
			}
	} 
	return 0; 
}
	
