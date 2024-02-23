// ------------------------------------------------------------------------
// Name: 0221
// Course-Section: CS 155-section 02
// Assignment: Assignment 5
// Date due: 02/23/2024
// Resources: None 
// Description: A Scream horror movie trivia quiz that outputs the users
// score and letter grade once the user finishes the quiz.
// ------------------------------------------------------------------------
#include <iostream>
using namespace std;

int main(){
	string name;
	char answer1 = 'A', answer2 = 'A', answer3 = 'A', answer4 = 'A',
	     letterGrade = 'A';
	int finalScore = 100;
	
	cout << "Please enter your name: ";
	cin >> name;
	cout << endl; 
	
	cout << "Q1: In what fictional town does the movie Scream take place?"
		 << endl << "A: Sunnydale" << endl << "B: Gainesville" << endl 
		 << "C: Woodsboro" << endl << "D: Lake Wobegon" << endl 
		 << "Enter in your answer: ";
	cin >> answer1;
	
	/* 
	Checks wether the answer is a valid option or not then gives the
    user another chance to fix there mistake */
	if ((toupper(answer1) != 'A') && (toupper(answer1) != 'B') &&
	   (toupper(answer1) != 'C') && (toupper(answer1) != 'D')){
		cout << endl << "ERROR - INVALID INPUT" << endl
		     << "Please enter a valid option (A, B, C ,D): ";
		cin >> answer1; 
	}
	/*
	Checks whether the user entered the correct option and if its wrong
	substract 25 from the 100 because they dont get credit for
	the question then outputs the corect answer */
	if (toupper(answer1) != 'C'){
		finalScore = finalScore - 25;
		cout << "X - The correct answer is C: Woodsboro" << endl;
	} 
	
	cout << endl << "Q2: Who directed Scream?" << endl
	 	 << "A: David Cronenberg" << endl << "B: George A. Romero" << endl
	 	 << "C: John Carpenter" << endl << "D: Wes Craven" << endl 
		 << "Enter in your answer: ";
	cin >> answer2;
	
	if ((toupper(answer2) != 'A') && (toupper(answer2) != 'B') &&
	   (toupper(answer2) != 'C') && (toupper(answer2) != 'D')){
		cout << endl << "ERROR - INVALID INPUT" << endl
		     << "Please enter a valid option (A, B, C ,D): ";
		cin >> answer2; 
	}
	
	if (toupper(answer2) != 'D'){
		finalScore = finalScore - 25;
		cout << "X - The correct answer is D: John Carpenter" << endl;
	}
	
	cout << endl 
		 << "Q3: What food is Casey preparing in the opening scene?"
		 << endl << "A: Popcorn" << endl << "B: Poptarts" << endl 
		 << "C: Nachos" << endl << "D: Pizza" << endl 
		 << "Enter in your answer: ";
	cin >> answer3;
	
	if ((toupper(answer3) != 'A') && (toupper(answer3) != 'B') &&
	   (toupper(answer3) != 'C') && (toupper(answer3) != 'D')){
		cout << endl << "ERROR - INVALID INPUT" << endl
		     << "Please enter a valid option (A, B, C ,D): ";
		cin >> answer3; 
	}
	
	if (toupper(answer3) != 'A'){
		finalScore = finalScore - 25;
		cout << "X - The correct answer is A: Popcorn"<< endl;
	}
	
	cout << endl << "Q4: What is the janitor's name?" << endl
	 	 << "A: The Fonz" << endl << "B: Ted" << endl << "C: Carrie"
		 << endl << "D: Fred" << endl << "Enter in you answer: ";
	cin >> answer4;
	
	if ((toupper(answer4) != 'A') && (toupper(answer4) != 'B') &&
	   (toupper(answer4)!= 'C') && (toupper(answer4) != 'D')){
		cout << endl << "ERROR - INVALID INPUT" << endl
		     << "Please enter a valid option (A, B, C ,D): ";
		cin >> answer4; 
	}
	
	if (toupper(answer4) != 'D'){   
		finalScore = finalScore - 25;
		cout << "X - The correct answer is D: Fred" << endl;
	}
	
	/*
	Finds what letter grade they have by seeing if its greater then the
	minimum score they can have to keep said letter grade
	*/
	if(finalScore >= 90){
		letterGrade = 'A';
	}
	
	else if (finalScore >= 80){
		letterGrade = 'B';
	}
	
	else if (finalScore >= 70){
		letterGrade = 'C';
	}
	
	else if (finalScore >= 60){
		letterGrade = 'D';
	}
	
	else {
		letterGrade = 'F';
	}
	
	cout << endl << "**** QUIZ RESULTS ****" << endl << "Name: " << name 
		 << endl << "Score: " << finalScore <<"/100" << endl 
		 << "Letter Grade: " <<	letterGrade; 
	
	return 0;
}