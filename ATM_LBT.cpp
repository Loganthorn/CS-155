// ------------------------------------------------------------------------
// Name: 0221
// Course-Section: CS 155-section 02
// Assignment: Assignment 5
// Date due: 02/23/2024
// Resources: None 
// Description: A ATM program that deposits and withdraws money from an 
//              account.
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
		 << "C - Deposit to Checkings" << endl
		 << "D - Deposit to Savings" << endl 
		 << "Enter: ";
	cin >> userOption;
	
	cout << fixed << setprecision(2);
	
	// Checks if the user typed in a valid option.
	if ((userOption != 'A') && (userOption != 'B') && 
	   (userOption != 'C') && (userOption != 'D')) {
		cout << endl << "ERROR - INVALID OPTION"  << endl << endl 
			 << "*** RECEIPT ***" << endl 
			 << "Checkings: $" << checkings << endl
			 << "Savings: $" << savings; 
		}
	
	// Checks if the user typed in Option A 
	if (userOption == 'A'){ 
		cout << endl 
			 << "How much do you want to Withdraw from Checkings: $";
		cin >> withdraw;
		
		/*
		* Checks if the user withdraw amount is valid by making sure is not
		* less than zero, zero or greater than savings. */
		if ((withdraw <= 0) || (withdraw > checkings)){
				cout << "ERROR - INVALID WITHDRAW AMOUNT" << endl << endl 
				     << "*** RECEIPT ***" << endl 
					 << "Checkings: $" << checkings << endl << "Savings: $" << savings; 
		}
			
		else {
				checkings = checkings - withdraw; 
				cout << endl << "DISPENSING: $" << withdraw << endl << endl
				     << "*** RECEIPT ***" << endl 
					 << "Checkings: $" << checkings << endl 
					 << "Savings: $" << savings; 
		}
	}
	
	// Checks if the user typed in option B.
	else if (userOption == 'B'){
		cout << endl << "How much do you want to Withdraw from Savings: $";
		cin >> withdraw;
		
		/*
		* Checks if the user withdraw amount is valid by making sure is not
		* less than zero, zero or greater than savings.*/
		if  ((withdraw <= 0) || (withdraw > savings )){
				cout << "ERROR - INVALID WITHDRAW AMOUNT" << endl << endl 
				     << "*** RECEIPT ***" << endl 
					 << "Checkings: $" << checkings << endl 
					 << "Savings: $" << savings; 
		}
			
		else {
				savings = savings - withdraw;
				cout << endl << "DISPENSING: $" << withdraw << endl << endl
				     << "*** RECEIPT ***" << endl 
					 << "Checkings: $" << checkings << endl 
					 << "Savings: $" << savings; 
				
			}
	} 
	
	// Checks if the user typed in option C.
	else if (userOption == 'C'){
		cout << endl << "How much do you want to Deposit to Checkings: $";
		cin >> deposit;
		
		/*
		*Checks wether the users deposit amount is valid as making sure its
		not zero or less than zero. */
		if (deposit <= 0){
			cout << endl << "ERROR - INVALID DEPOSIT AMOUNT" << endl 
			     << endl << "*** RECEIPT ***" << endl 
				 << "Checkings: $" << checking << endl 
				 << "Savings: $" << savings; 
		}
		
		else{
			checkings =  checkings + deposit;
			cout << endl << "DEPOSITING: $"<< deposit << endl << endl 
				 << "*** RECEIPT ***" << endl << "Checkings: $" 
				 << checkings << endl << "Savings: $" << savings; 
		}
	}
	
	// Checks if the user pickesd option D.
	else if (userOption == 'D'){
		cout << endl << "How much do you want to Deposit to Savings: $";
		cin >> deposit;
		
		/*
		* Checks wether the users deposit amount is valid as making sure 
		its not zero or less than zero. */
		if (deposit <= 0){
			cout << endl << "ERROR - INVALID DEPOSIT AMOUNT" << endl 
			     << endl << "*** RECEIPT ***" << endl 
				 << "Checkings: $" << checking << endl 
				 << "Savings: $" << savings; 
		}
		
		else {
			savings =  savings + deposit;
			cout << endl << "DEPOSITING: $"<< deposit << endl << endl 
				 << "*** RECEIPT ***" << endl 
				 << "Checkings: $" << checkings << endl 
				 << "Savings: $" << savings; 
		}
	}
	
	return 0; 
}
	
