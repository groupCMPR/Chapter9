#include <iostream>
#include <sstream>
#include "input.h"

using namespace std;

int mainMenu();
void caseOne();

string operator*(const string& str, size_t times);
string recursiveFunction(unsigned char spaces, unsigned char length);
string pattern();

int main() {
	do {
		system("cls");
		switch (mainMenu()) {
		case 0: return EXIT_SUCCESS;
		case 1: caseOne(); break;
			//case 2: caseTwo(); break;
			//case 3: caseThree(); break;
		}
		cout << "\n\n\t\t";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//PreCondition: None
//PostConidtion: Displays menu to user and returns an integer
int mainMenu() {
	cout << "\n\t\tCMPR131 Chapter 9: Recursive Applications by Group 11 (11/5/2023)";
	cout << "\n\t\t" << string(100, char(205));
	cout << "\n\t\t1> Pattern of astricks and blanks";
	cout << "\n\t\t2> Guess a number";
	cout << "\n\t\t3> Solve Tower of Hanoi";
	cout << "\n\t\t4> 4> Solve n-Queens";
	cout << "\n\t\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t\t" << string(100, char(205));

	return inputInteger("\n\t\tOption: ", 0, 4);
}

//PreCondition: None
//PostConidtion: 
string operator*(const string& str, size_t times) {
    stringstream stream;
    for (size_t i = 0; i < times; i++) {
        stream << str;
    }
    return stream.str();
}

//PreCondition: None
//PostConidtion: Here we are applying the recursive fuction inorder to print the pattern
string recursiveFunction(unsigned char spaces, unsigned char length) {
    // base case 
    if (length == 0) {
        return "";
    }
    else {
        //recursive calling 
        return (recursiveFunction(spaces, length / 2) + string("  ") * spaces +
            string("* ") * length + "\n" +
            recursiveFunction(spaces + length / 2, length / 2));
    }

}

//PreCondition: None
//PostConidtion: This will return our recursive function for the pattern
string pattern() {

    return recursiveFunction(0, 8);
}


//PreCondition: None
//PostConidtion: Outputs the pattern
void caseOne() {
    system("cls");

    cout << "\n\t1>  Pattern of astricks and blanks";
    cout << '\n' << string(55, char(196)) << endl;

    cout << pattern() << endl; 

}
