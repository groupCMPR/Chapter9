//Names: Alexis Martinez, Angie Campos, Neidy Malaga, & Vivian Huynh
//Date: 10/27/2023
// Professor Quach
//Description: Chapter 9 Assignment - Recursive Applications
//The purpose of this assignment is to familiarize ourselves with recursive functions. The following options will print a pattern, 
//guess a number, simulate the tower of hanoi game, and simulate the n-queens game. Each equation uses recursive functions, and takes into 
//consideration the recursive stack.
//Groups: (please fill in your name for your assigned roles)
//Option 1 (pattern): Angie
//Option 2 (number guessing game): Vivian
//Option 3 (tower of hanoi): Alexis
//Option 4 (n-queens): Neidy
//main.cpp organization: Vivian

#include <iostream> //For cout
#include <sstream>

//HEADER FILE
#include "input.h"  //For input validation
#include "Queen.h" //for option 4
using namespace std;

//PROTOTYPES
int menuOption();

//Option 1 - Pattern of asterisks and blanks
void option1();
string operator*(const string& str, size_t times);
string recursiveFunction(unsigned char spaces, unsigned char length);
string pattern();
//Option 2 - Guess a number
void option2();
int numbersGuessedRecursion(int, int, int);
//Option 3 - Solve Tower of Hanoi
void option3();
//Option 4 - Solve n-Queens
void option4();

//Precondition : N/A
//Postcondition: Calls option 1, 2, 3, and 4
int main()
{
	do
	{
		system("cls");
		switch (menuOption())
		{
		case 0: exit(0);
		case 1: system
			  ("cls"); option1(); break;
		case 2: system("cls"); option2(); break;
		case 3: system("cls"); option3(); break;
		case 4: system("cls"); option4(); break;
		default: cout << "\t\tERROR: - Invalid option. Please re-enter"; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return 0;
}

//Precondition : Calls from main
//Postcondition: Returns integer choice
int menuOption()
{
	cout << "\n\tCMPR131 Chapter 9: Recursive Applications (Final Group 2)";
	cout << "\n\t" << string(100, char(205));
	cout << "\n\t\t1> Pattern of asterisks and blanks";
	cout << "\n\t\t2> Guess a number";
	cout << "\n\t\t3> Solve Tower of Hanoi";
	cout << "\n\t\t4> Solve n-Queens";
	cout << "\n\t" << string(100, char(196));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(100, char(205));

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

//Precondition : Called from main
//Postcondition: Outputs the pattern
void option1()
{
	system("cls");

	cout << "\n\t1>  Pattern of astricks and blanks";
	cout << '\n' << string(55, char(196)) << endl;

	cout << pattern() << endl;
}

//Precondition : Calling from option 2; passing in valid positive integers
//Postcondition: Return the number of guesses
int numbersGuessedRecursion(int lowestNumber, int biggestNumber, int numberGuess)
{
	char choice = 'N';
	int middle = 0;

	if (biggestNumber - 1 == lowestNumber + 1)
	{
		cout << "\n\tYour number must be " << ++lowestNumber << ".";
		return numberGuess;
	}
	if (biggestNumber != 0)
	{
		middle = lowestNumber + ((biggestNumber - lowestNumber) / 2);

		choice = inputChar("\n\tIs your number " + to_string(middle) + "? (Y-yes or N-no) ", static_cast<string>("YN"));
		if (choice == 'Y')
		{
			numberGuess++;
			return numberGuess;
		}
		else
		{
			choice = inputChar("\tIs your number larger than " + to_string(middle) + "? (Y-yes or N-no) ", static_cast<string>("YN"));
			if (choice == 'Y')
			{
				lowestNumber = middle;
				numberGuess++;
				return numbersGuessedRecursion(lowestNumber, biggestNumber, numberGuess);
			}
			else
			{
				biggestNumber = middle;
				numberGuess++;
				return numbersGuessedRecursion(lowestNumber, biggestNumber, numberGuess);
			}
		}
	}
}

//Precondition : Called from main
//Postcondition: Output number of guesses 
void option2()
{
	srand(time(0));
	int random = rand() % 1000 + 1;
	int lowestNumber = 1;
	int numberGuess = 0;
	bool choice = false;

	cout << "\n\t2> Guess your number between 1 to " << random << ".";
	cout << "\n\tThink of a number from 1 to " << random << ".";
	cout << '\n';
	system("pause");

	numberGuess = numbersGuessedRecursion(lowestNumber, random, numberGuess);

	cout << "\n\tNumber of guesses: " << numberGuess;
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
	int board_space = inputInteger("\n\tEnter the board dimension dxd: ", 1, 64);
	int column = inputInteger("\n\tEnter the column position(1.." + to_string(board_space) + ") of the first Queen on row 1: ", 1, board_space);

	Queen q1(board_space, column);

	//solve the n- queens
	if (board_space > 3)
		q1.solve_Queens(1);

	//display
	if (q1.is_Correct())
		cout << q1;
	else 
		cout << "\n\tNo solution";

}
