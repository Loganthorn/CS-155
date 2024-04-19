// ------------------------------------------------------------------------
// Name: 0221
// Course-Section: CS 155-section 02
// Assignment: Project 4
// Date due: 04/18/2024
// Resources: None 
// Description: An application to simulate a hotel booking system for the
//			    Hilton chain of hotels. Customers can pick from multiple
//				hotels in the chain to book with along with multiple nights
//				and rooms.
// ------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

void displayHotels();
int getHotelChoice();
bool readRoomPrices(int hotelChoice, string& hotelName, double& oneQueen, 
                    double& twoQueen, double& oneKing, double& twoKing, 
                    double& luxurySuite);
void displayRoomPrices(string hotelName, double oneQueen, double twoQueen,
						double oneKing, double twoKing, 
						double luxurySuite);
int getRoomChoice();
double getRoomCost(int roomChoice, double oneQueen, double twoQueen,
						double oneKing, double twoKing, 
						double luxurySuite);
int getNumRooms();
int getNumNights();
void addToOrder(int numNights, int numRooms, double roomCost, 
				double& subTotal);
double calculateTaxes(double subTotal);	
void printReceipt(string hotelName, int numRooms, int numNights, 
				  double roomPrice,double subtotal, double taxFee,
				   ofstream& output);			



int main(){
	int hotelChoice = 0, roomChoice = 0, numRooms = 0, numNights = 0;
	string hotelName;
	double oneQueen = 0, twoQueen = 0, oneKing = 0, twoKing = 0, 
		   luxurySuite = 0, roomCost = 0, subTotal = 0, tax = 0;
	ofstream output("OutLBT.txt");

	/* 	
	*	Runs through the while loop aslong as the user doesnt pick higher 
	than 3 or lower than 1*/
	while (hotelChoice > 1 || hotelChoice < 4){
		displayHotels();
	
		// Sets hotelChoice variable to the return value of the Fucntion
		hotelChoice = getHotelChoice();
	
		/*
		*	If the readRoomPrices return true it displays the room prices
		else it outputs Error processng file*/
		if (readRoomPrices( hotelChoice, hotelName,  oneQueen, twoQueen,
	     oneKing, twoKing, luxurySuite)){
		displayRoomPrices ( hotelName, oneQueen, twoQueen, oneKing, 
			               twoKing, luxurySuite);
		}
		
		else {
			cout << endl << "ERROR PROCESSING FILE" << endl;
		}	
	
	
		roomChoice = getRoomChoice();
		
		roomCost = getRoomCost( roomChoice, oneQueen, twoQueen, oneKing,
						   twoKing, luxurySuite);
						   
		numRooms = getNumRooms();
		
		numNights = getNumNights();
		
		addToOrder(numNights, numRooms, roomCost, subTotal);
		
		cout << fixed <<  setprecision(2) << endl << "Subtotal: $" 
			 << subTotal << endl ;
		
		tax = calculateTaxes(subTotal);
    	
    	/*
		*	If the file does not open it outputs ERROR OPENING FILE 
		else it will output the receipt*/
		if (!output.is_open()) {
    		cout << "ERROR OPENING OUTPUT FILE";
		}
		
		else{
			printReceipt(hotelName, numRooms, numNights, roomCost,
						 subTotal, tax, output);
		}
	}
	
	output.close();
	
	return 0;	
}

// Function Name: displayHotels
// Input(s): N/A
// Return Value: N/A
// Description: Displays all of the options the user can pick
void displayHotels(){
	cout << endl << endl  << "Welcome to the Hilton Honors Booking System" 
		 << endl << "Choose an option below:" << endl 
		 << "1 - Embassy Suites" << endl << "2 - Hilton Garden" 
		 << endl << "3 - DoubleTree" << endl
		 << "0 - End of the Day: Stop Processing" << endl;
}

// Function Name: getHotelChoice
// Input(s): N/A
// Return Value: int hotelChoice
// Description: Retrieves which hotel the user wants to book with
int getHotelChoice(){
	int hotelChoice;
	
	// Goes through the loop until the users input is valid
	do {
		cout << "Which hotel would you like to book with? ";
		
		cin >> hotelChoice;
	}while (hotelChoice > 3 || hotelChoice < 0);

	return hotelChoice;
}

// Function Name: readRoomPrices
/* Input(s): int hotelChoice, string hotelName, double oneQueen, 
			 double twoQueen, double oneKing, double twoKing, double
			 luxurySuite*/ 
// Return Value: True if ran successfully else false 
// Description: reads and sets all the room price varables from files
bool readRoomPrices(int hotelChoice, string& hotelName, double& oneQueen, 
                    double& twoQueen, double& oneKing, double& twoKing, 
                    double& luxurySuite) {
    string nameOfFile; 
    
    switch (hotelChoice) {
        case 0:
            exit(0);
        
		case 1:
            hotelName = "Embassy Suites";
            nameOfFile = "Embassy.txt"; 
            
			break;
        
		case 2:
            hotelName = "Hilton Garden";
            nameOfFile = "Hilton_Garden.txt";
            
			break; 
        
		case 3:
            hotelName = "DoubleTree";
            nameOfFile = "DoubleTree.txt"; 
            
			break;
    }
    
    ifstream prices(nameOfFile);
    
	// If the file does not open it returns false
    if (!prices.is_open()) {
        return false;
    }
    
    // If the file does not read the and set variables it returns false
    else if (!(prices >> oneQueen >> twoQueen >> oneKing >> twoKing
					 >> luxurySuite)) {
        return false;
    }
    
	
	prices.close();   
    return true;        
}

// Function Name: displayRoomPrices
/* Input(s): string hotelName, double oneQueen, double twoQueen, 
			 double oneKing, double twoKing, double luxurySuite*/ 
// Return Value: N/A 
// Description: displays all of the room Prices
void displayRoomPrices(string hotelName, double oneQueen, double twoQueen,
						double oneKing, double twoKing, 
						double luxurySuite){
	cout << endl << "Welcome to " << hotelName << ":" << endl
	 	 << "1 - 1 Queen: $" << oneQueen << endl << "2 - 2 Queens: $" 
		 << twoQueen << endl << "3 - 1 King: $" << oneKing << endl 
		 << "4 - 2 Kings: $" << twoKing << endl 
		 << "5 - Luxury Suite for 2: $" << luxurySuite << endl;											
}

// Function Name: getRoomChoice
// Input(s): N/A
// Return Value: int roomChoice
// Description: Retrieves which room the user wants to book 
int getRoomChoice(){
	int roomChoice = 0;
	
	/*
		Runs through the loop as long as the users choice is greater than
	five and lower than one */
	do{
		cout << "Select Your Room: ";
		
		cin >> roomChoice;
	}while (roomChoice > 5 || roomChoice < 1);
	
	return roomChoice;
}

// Function Name: getRoomCost
/* Input(s): int roomChoice, double oneQueen, double twoQueen, 
			 double oneKing, double twoKing, double luxurySuite */
// Return Value: double roomCost
/* Description: Changes the variable roomCost according to which room the 
				user picks*/
double getRoomCost(int roomChoice, double oneQueen, double twoQueen,
                    double oneKing, double twoKing, 
                    double luxurySuite) {
    double roomCost = 0;
   
    switch(roomChoice) {
        case 1:
            roomCost = oneQueen;
            break;
        case 2: 
            roomCost = twoQueen;
            break;
        case 3:
            roomCost = oneKing;
            break;
        case 4:
            roomCost = twoKing;
            break;
        case 5:
            roomCost = luxurySuite;
            break;
    }
    
    return roomCost;
}

// Function Name: getNumRooms
// Input(s): N/A
// Return Value: int numRooms
// Description: Retrieves how many rooms the user wants 
int getNumRooms(){
	int numRooms = 0; 
	
	// Runs the loops if the numRooms is less than 1
	do{
		cout << "Enter the number of rooms: ";
		
		cin >> numRooms;
	}while(numRooms < 1);
	
	return numRooms;
}

// Function Name: getNumNights
// Input(s): N/A
// Return Value: int numNights
// Description: Retrieves how many Nights the user wants to stay 
int getNumNights(){
	int numNights = 0;
	
	// Runs the loops if the numNights is less than 1
	do{
		cout << "Enter the number of nights: ";
		
		cin >> numNights;
	} while(numNights < 1); 
	
	return numNights;
}

// Function Name: addToOrder
// Input(s): int numNights, int numRooms, double roomCost, double subTotal
// Return Value: N/A
// Description: Calcaluates the subtotal
void addToOrder(int numNights, int numRooms, double roomCost, 
				double& subTotal){
	cout << "Room successfully booked!"	;
	
	subTotal = numNights * numRooms * roomCost;				
}

// Function Name: calculateTaxes
// Input(s): double subTotal
// Return Value: double tax
// Description: Calcaluates the tax for the users order tax
double calculateTaxes(double subTotal){
	double tax = 0;
	
	tax = subTotal * .04;
	
	return tax;
}

// Function Name: printReceipt
/* Input(s): string hotelName, int numRooms, int numNights, 
			 double roomPrice,double subtotal, double taxFee, 
			 ofstream& output*/ 
// Return Value: N/A
// Description: Outputs the users bill onto a ouput file
void printReceipt(string hotelName, int numRooms, int numNights, 
				  double roomPrice,double subtotal, double taxFee,
				  ofstream& output) {
    
    double total = subtotal + taxFee;
  
    output << "Hotel Name: " << hotelName << endl << "Number of Rooms: " 
		   << numRooms << endl << "Number of Nights: " << numNights << endl
		   << fixed << setprecision(2) << "Room Price per Night: $" 
		   << roomPrice << endl << "Subtotal: $" << subtotal << endl 
		   << "Tax Fee: $" << taxFee << endl << "Total Amount Due: $" 
		   << total << endl
		   <<  "||||||||||||||||||||||||||||||||||||||||||||" << endl
		   << endl;
}		