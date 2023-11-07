//Names: Alexis Martinez & Angie Campos 
//Date: 10/28/2023
//Description: Derived header file for class tower

#pragma once
#include "peg.h"

class towers
{
private:
	peg pegs[3];
	int move;

public:
	//default game start
	towers(int);
	//coverts user char choice to access array of objects
	int charToInt(char);
	//moves rings from one stack to the other needs a source char and destination
	void moveRing(char, char);
	//displays the game
	void displayAllTowers(int) const;
	//checks for a win 
	bool winCheck(int);
	//get the move
	int getMove();
	//display solved game
	void solveGame(int numOfRings, char fromPeg, char toPeg, char auxPeg);
};
