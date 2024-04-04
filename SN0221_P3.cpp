// ------------------------------------------------------------------------
// Name: 0221
// Course-Section: CS 155-section 02
// Assignment: Project 3
// Date due: 03/22/2024
// Resources: None 
// Description: A program that checks wether a credit card is valid or not
// by checking its experation date, card type, and if it passes Luhn's  
// algorithim. 
// ------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line, creditCardNumber, expirationMonth, expirationYear, 
		   cardType;
    int expYear = 0, expMonth = 0, counter = 0, sumTwo = 0, remaining = 0,
		digit = 0, total = 0;
    ifstream inputFile("payment.csv");
    ofstream validOutput("valid.csv");
    ofstream invalidOutput("invalid.csv");

	/*
	*	Checks if the input file opens correctly if it doesnt it shoots an
	error and ends the program.*/
    if (inputFile.fail()){
        cout << "ERROR - OPENING INPUT FILE";
        return (1);
    }

	
    while (getline(inputFile, line)){
    	sumTwo = 0;
		remaining = 0;
		
    	// Find the position of the comma in the line.
        int commaPosition = line.find(',');
    
        //Finds and intializies the Credit Card number.
        if (commaPosition != -1){
        	
        	// Finds where the credit card number is.
            creditCardNumber = line.substr(0, commaPosition);
            
            // Finds where the slash is.
            int slashPosition = line.find('/', commaPosition + 1);
            
			 
			if (slashPosition != -1){
				// Finds and initializes the month of expiration.  
                expirationMonth = line.substr(commaPosition + 1,
								  slashPosition - commaPosition - 1);
                
                // Finds and intializies the year of expiration.
                expirationYear = line.substr(slashPosition + 1);
            }
            
            // Changes these string into integers.
            expYear = stoi(expirationYear);
            expMonth = stoi(expirationMonth);
        }

		 /*
		 *	Finds and makes the length of credit cardnumber and makes that
		length a varable*/
        int length = creditCardNumber.length();
	
		/*
		*	Checks if the month is invalid if so it ends the program 
		outputting credit card number and Expired on the file.*/ 
        if (expYear < 2024 || (expYear == 2024 && expMonth < 3)){
            invalidOutput << creditCardNumber << ", EXPIRED" << endl;
        } 
        
        /*
		*	Checks if the month is invalid if so it ends the program 
		outputting credit card number and Expired on the file.*/ 
		else if (expMonth < 1 || expMonth > 12){
        	invalidOutput << creditCardNumber << ", EXPIRED" << endl;
		}
		
		else {
			 /*
			*	Checks the first two digits of the credit card number and
			the if the first two digits fit the conditions it check the
			length if it meets these condition it set the cardtype 
			to American Express.*/ 
            if ((creditCardNumber.substr(0, 2) == "34" ||
				creditCardNumber.substr(0, 2) == "37") && length == 15){
                cardType = "American Express";
        	}
           	
			/*
			*	Checks the first two digits of the credit card number and
			the if the first two digits fit the conditions it check the
			length if it meets these condition it set the cardtype to
			MasterCard.*/   
			else if (((creditCardNumber.substr(0, 2) == "51") || 
					(creditCardNumber.substr(0, 2) == "52") ||
                    (creditCardNumber.substr(0, 2) == "53") || 
					(creditCardNumber.substr(0, 2) == "54") ||
                    (creditCardNumber.substr(0, 2) == "55")) &&
					(length == 16)){
                cardType = "MasterCard";
            } 
				
			/*
			*	Checks the first digit of the credit card number and the 
			if the first digit fit the conditions it check the length if 
			it meets these condition it set the cardtype to Visa.*/
			else if (creditCardNumber.substr(0, 1) == "4" && 
					(length == 16 || length == 13)){
                cardType = "Visa";
            } 
			
			/*
			*	Checks the first two digits and first three of the credit
			card number and the if the first two digits and first three fit
			the conditions it check the length if it meets these condition
			it set the cardtype to Diners Club and Carte Blanche.*/
			else if (((creditCardNumber.substr(0, 2) == "36") || 
					(creditCardNumber.substr(0, 2) == "38") ||
                    (creditCardNumber.substr(0, 3) == "300") || 
					(creditCardNumber.substr(0, 3) == "301") ||
                    (creditCardNumber.substr(0, 3) == "302") ||
					(creditCardNumber.substr(0, 3) == "303") ||
                    (creditCardNumber.substr(0, 3) == "304") || 
					(creditCardNumber.substr(0, 3) == "305")) &&
                    (length == 14)){
                cardType = "Diners Club and Carte Blanche";
            } 
			
			/*
			*	Checks the first four digits of the credit card number and  
			if the first four digits fit the conditions it check the length
			if it meets these condition it set the cardtype to Discover.*/ 
			else if (creditCardNumber.substr(0, 4) == "6011" &&
					(length == 16)){
                cardType = "Discover";
            } 
			
			 /*
			*	Checks the first four digits of the credit card number and  
			if the first four digits fit the conditions it check the length
			if it meets these condition it set the cardtype to JCB.*/   
			else if (((creditCardNumber.substr(0, 4) == "2123") || 
					(creditCardNumber.substr(0, 4) == "1800")) &&
                    (length == 15)){
                cardType = "JCB";
            } 
			
			/*
			*	Checks the first digit of the credit card number and the 
			if the first digit fit the conditions it check the length if 
			it meets these condition it set the cardtype to JCB.*/  
			else if (creditCardNumber.substr(0, 1) == "3" && 
					(length == 16)){
                cardType = "JCB";
            } 
			
			/*
      	  	*	if the card never eaches any of htese conditions it outputs
			that its an invalid card type and ends the program */
			else {
                invalidOutput << creditCardNumber << ", INVALID CARD TYPE" 
								<< endl;
            }

			/*
			*	Iterate through the credit card number starting from the 
			second to last digit, moving backwards by 2*/
           for (int i = length - 2; i >= 0; i -= 2){
           		//finds each individual digtit
                digit = (creditCardNumber[i] - '0') * 2;
                // If the conditions mett it goes through wiht the math. 
				if (digit >= 10){
                    digit = digit / 10 + digit % 10;
                }
                //digits is added to sumtwo
                sumTwo += digit;
            }
			
			/*
			*	Iterate through the credit card number starting from the 
			last digit, moving backwards by 2.*/ 
            for (int i = length - 1; i >= 0; i -= 2) {
            	/* 
				*	if the conditions met Add the digit to the sum of
				remaining digits */
                if (creditCardNumber[i] != ' '){
                    remaining += (creditCardNumber[i] - '0');
                }
            }

            total = sumTwo + remaining;

			// if it meets this condition it failed the algorithim.
            if (total % 10 != 0) {
                invalidOutput << creditCardNumber 
							  << ", FAILED LUHN’S ALGORITHIM" << endl;
            } 
			
			//else it passed
			else {
                validOutput << creditCardNumber << ", " << cardType 
							<< endl;
            }
        }
    }

    inputFile.close();
    invalidOutput.close();
    validOutput.close();

    return 0;
}