// ------------------------------------------------------------------------
// Name: 0221
// Course-Section: CS 155-section 02
// Assignment: Project 1
// Date due: 02/14/2024
// Resources: cmath
// Description: Converts a 8-bit binary number the user inputs to 
// the Base-10 number and into the ASCII charecter representation.
// ------------------------------------------------------------------------
#include <iostream>
#include <cmath> 
using namespace std;

int main(){
	int binaryNum = 0, binaryDigit0 = 0, binaryDigit1 = 0,
	    binaryDigit2 = 0, binaryDigit3 = 0, binaryDigit4 = 0,
		binaryDigit5 = 0, binaryDigit6 = 0, binaryDigit7 = 0,
		base10Num = 0; 
	
	// Prompts the user to enter the 8-bit binary number.
	cout << "Enter an 8-bit binary number: ";
	cin >> binaryNum;
	
	/* 
	Each individual digit is calculated by 8-bit binary number modulus 10, 
	and then by dividing the binary number by 10, the reason as to why
	divison by 10 is nescarry is so repeating modulus by 10 on the binary
	number, will get the next binary digit. 
	*/
	binaryDigit0 = binaryNum % 10;
	binaryNum = binaryNum / 10; 
		
	binaryDigit1 = binaryNum % 10;
	binaryNum = binaryNum / 10;
	
	binaryDigit2 = binaryNum % 10; 
	binaryNum = binaryNum / 10; 
	
	binaryDigit3 = binaryNum % 10;
	binaryNum = binaryNum / 10; 
		
	binaryDigit4 = binaryNum % 10;
	binaryNum = binaryNum / 10;
	
	binaryDigit5 = binaryNum % 10; 
	binaryNum = binaryNum / 10; 
	
	binaryDigit6 = binaryNum % 10;
	binaryNum = binaryNum / 10; 
		
	binaryDigit7 = binaryNum % 10;
	binaryNum = binaryNum / 10;
	
	/* 
	Calculates the base-10 number by multiplying each individual 8-bit 
	binary digit by 2 to the power of the digit that corresponds to the
	position it is in the 8-bit binary number.
	*/
	base10Num = (binaryDigit0 * pow(2, 0)) + (binaryDigit1 * pow(2, 1)) +
			(binaryDigit2 * pow(2, 2)) + (binaryDigit3 * pow(2, 3)) + 
			(binaryDigit4 * pow(2, 4)) + (binaryDigit5 * pow(2, 5)) +
			(binaryDigit6 * pow(2, 6)) + (binaryDigit7 * pow(2, 7));
	
	/* 
	Outputs the Base-10 representation and the ASCII character 
    representaiton. The ASCII representation is found by using char on the
    base 10 number.
	*/
	cout << endl << "The base-10 number is " << base10Num
	 	 << " and the ASCII character representation is "
		 << char(base10Num) << "!";

	return 0;
}