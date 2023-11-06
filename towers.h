//Alexis and Angie
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

	int getMove();

	void solveGame(int numOfRings, char fromPeg, char toPeg, char auxPeg);

};

