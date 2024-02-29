// ------------------------------------------------------------------------
// Name: 0221
// Course-Section: CS 155-section 02
// Assignment: Project 2
// Date due: 03/04/2024
// Resources: None 
// Description: 
// ------------------------------------------------------------------------

#include <iostream>
using namespace std;

int main(){
	char yesOrNo1 = 'Y', yesOrNo2 = 'Y', upcomingSem = 'F';
	int highestLevelCs = 0, highestLevelMa = 0, actMath = 0, semYear = 0;
	const string LINES = "-----------------------------------------------";
	
	
	
	cout << LINES << endl << "Welcome to Semester Strategist 1.0!" << endl
	     << endl << "Have you taken any CS classes (Y/N)? ";
	cin >> yesOrNo1;
	
	if ((toupper(yesOrNo1) != 'Y') && (toupper(yesOrNo1) != 'N')){
		throw invalid_argument("ERROR - INVALID INPUT Y OR N EXPECTED");
	}
	
	if (toupper(yesOrNo1) == 'Y'){
		cout << "Whats the highest level CS class you have taken"
		     << "or are currently taking? CS-";
		cin >> highestLevelCs;
	}
	
	cout << endl << "Have you taken any Math Classes (Y/N)? ";
	cin >> yesOrNo2; 
	
	if ((toupper(yesOrNo2) != 'Y') && (toupper(yesOrNo2) != 'N')){
		throw invalid_argument("ERROR - INVALID INPUT Y OR N EXPECTED");
	}
	
	if (toupper(yesOrNo2) == 'Y'){
		cout << "Whats the highest level Math class you have taken or"
			 << "are currently taking? Ma-";
		cin >> highestLevelMa;
		
		if ((highestLevelMa != 110) && (highestLevelMa != 112) &&
		   (highestLevelMa != 113) && (highestLevelMa != 115) && 
		   (highestLevelMa != 125) && (highestLevelMa != 126) && 
		   (highestLevelMa != 126) && (highestLevelMa != 325) && 
		   (highestLevelMa != 331)){
			throw invalid_argument("ERROR - INVALID INPUT");
		}
	}
	
	
	
	cout << endl << "Enter your ACT math score: ";
	cin >> actMath;
	
	if (actMath < 1 || actMath > 36){
		throw invalid_argument("ERROR - INVALID INPUT 1-36 EXPECTED");
	}
	
	cout << endl
	     << "Enter the upcoming semester (S for Spring, M for Summer,"
		 <<" and F for Fall): ";
	cin >> upcomingSem;
	upcomingSem = toupper(upcomingSem);
	
	if ((upcomingSem != 'F') && (upcomingSem != 'M') && 
	   (upcomingSem != 'S')){
	   	throw invalid_argument
		("ERROR - INVALID INPUT F, M, AND S EXPECTED");	
	}
	
	cout << "Enter the upcoming semester year: ";
	cin >> semYear;
	
	if (semYear <= 2023){
		throw invalid_argument("ERROR - INVALID INPUT");
	}
	
	semYear = semYear % 2;
	
	cout << LINES << endl;
	cout << "You are eligible for these CS courses: " << endl; 
	
	if ((highestLevelCs == 0) && (actMath < 28)){
		cout << "CS-101" << endl << "CS-135" << endl;
	}
	
	if (((highestLevelCs == 101) || (highestLevelCs == 135) &&
	   (highestLevelMa >= 112)) || (highestLevelMa >= 125) || 
	   (actMath > 27)){
	   	if (highestLevelCs >= 155){
	   		cout <<"";
		   }
		else{
			cout << "CS-155" << endl;
		}
	}
	if (((highestLevelCs == 155) || (highestLevelCs == 255) ||
	   (highestLevelCs == 355) && (upcomingSem == 'F')) || 
	   ((highestLevelMa >= 112) && (upcomingSem == 'F'))){
		cout << "CS-245" << endl;
	}
	
	if ((highestLevelCs == 155)){
		cout << "CS-255" << endl;
	}
	
	if ((highestLevelCs == 255) && (upcomingSem != 'M')){
		cout << "CS-355"<< endl;
	}
	
	if ((highestLevelCs == 255) && (upcomingSem == 'S') &&
	   (semYear == 0)){
	   	cout << "CS-315" << endl;
	}
	
	if ((highestLevelCs == 255) && (upcomingSem == 'F') && (semYear == 1)){
		cout << "CS-325" << endl;
	}
	
	cout << endl << "You are elgible for these Math classes:" << endl;
	
	if ((highestLevelMa == 0 ) && (actMath < 22)){
		cout << "MA-110" << endl;
	}
	
	if ((highestLevelMa == 110) || ((actMath >= 22))){
		if (highestLevelMa > 110){
			cout << "";
		}
		else{
			cout << "MA-112" << endl;
		}
	}	
	
	if ((highestLevelMa == 112) || ((actMath >= 25 ))){
		if (highestLevelMa > 112){
			cout << "";
		}
		else{
			cout << "MA-113" << endl;
		}
	}
	
	if ((((highestLevelMa == 113) || (highestLevelMa == 115)) || 
	   (actMath >= 28)) && (upcomingSem != 'M')){
	   	if (highestLevelMa > 113){
			cout << "";
		}
		else{
			cout << "MA-125" << endl;
		}
	}

	if ((highestLevelMa == 125) && (upcomingSem != 'M')){
		cout << "MA-126" << endl;
	}
	
	if (((highestLevelMa >= 126) || ((highestLevelCs == 245) || 
	   (highestLevelMa == 325 )) && (upcomingSem != 'M'))){
		cout << "MA-331" << endl;
	}
	
	return 0;
	}
