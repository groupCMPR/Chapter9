//Names: Alexis Martinez, Angie Campos, Neidy Malaga, & Vivian Huynh
//Date: 10/27/2023
//Description: Chapter 9 Assignment - Recursive Applications

#include <iostream> //For cout

//HEADER FILE
#include "input.h"  //For input validation
using namespace std;

//PROTOTYPES
int menuOption();

//Option 1 - Pattern of astricks and blanks
void option1();
//Option 2 - Guess a number
void option2();
//Option 3 - Solve Tower of Hanoi
void option3();
//Option 4 - Solve n-Queens
void option4();

//Precondition : N/A
//Posctondition: Calls option 1, 2, 3, and 4
int main()
{
	do
	{
		system("cls");
		switch (menuOption())
		{
		case 0: exit(0);
		case 1: system("cls"); option1(); break;
		case 2: system("cls"); option2(); break;
		case 3: system("cls"); option3(); break;
		case 4: option4(); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return 0;
}

//Precondition : Calls from main
//Posctondition: Returns integer choice
int menuOption()
{
	cout << "\n\tCMPR131 Chapter 9: Recursive Applications (Final Group 2)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Pattern of astricks and blanks";
	cout << "\n\t\t2> Guess a number";
	cout << "\n\t\t3> Solve Tower of Hanoi";
	cout << "\n\t\t4> Solve n-Queens";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));

	return inputInteger("\n\t\tOption: ", 0, 4);
}

//Precondition : Called from main
//Postcondition: Outputs the pattern
void option1()
{
	cout << "\n\t1> Pattern of astricks and blanks";
}

//Precondition : Called from main
//Postcondition: Output number of guesses 
void option2()
{
	cout << "\n\t2> Guess your number between 1 to " << ".";
	cout << "\n\tThink of a number from 1 to " << ".";
	cout << "\n\tIs your number " << "? (Y-yes or N-no) ";
	cout << "\n\tIs your number larger than " << "? (Y-yes or N-no) ";
	cout << "\n\tNumber of guesses: ";
}

//Precondition : Called from main
//Postcondition: Output number of moves to win the game Tower of Hanoi
void option3()
{
	cout << "\n\t3> Tower of Hanoi (Recursive)";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\tEnter the number of rings(1..64): ";
	cout << "\n\tThe computer has solved the game in " << " moves.";

	cout << "\n\tPlay again? (Y-yes or N-no)";
}

//Precondition : Called from main
//Postcondition: Output the solved n-Queens game 
void option4()
{
	cout << "\n\tEnter the board dimension dxd: ";
	cout << "\n\tEnter the colume position(1.." << ") of the first Queen on row 1: ";
}
