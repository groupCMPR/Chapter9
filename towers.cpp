//Alexis and Angie
#include "towers.h"

//Precondition:none
//Postcondition: 
towers::towers(int numOfRings)
{
	move = 0;

	for (int i = numOfRings; i >= 1; i--)
	{
		pegs[0].push(i);
	}
}

int towers::getMove() {
	return move;
}

//Precondition:none
//Postcondition: this will trun the char (A,B,C) into int 
int towers::charToInt(char letter)
{
	switch (letter)
	{
	case 'A':return 0; break;
	case 'B':return 1; break;
	case 'C':return 2; break;
	default:cout << "\n\tInvalid Choice."; break;
	}
}

// Added the char(num + 'A') inorder to flip the number into a char - ASCII 
// Added an if else if else for an empty set to out putting and other
//Precondition:none
//Postcondition: This function will move the rings 
void towers::moveRing(char fromStack, char toStack)
{
	int from = charToInt(fromStack);
	int to = charToInt(toStack);

	if (pegs[from].empty())
	{
		cout << "ERROR - Cannot make the move. There is no disk in the selected peg-" << char(from + 'A') << "\nTry Again.\n";
	}
	else if (pegs[to].empty() || pegs[from].top() < pegs[to].top())
	{
		pegs[to].push(pegs[from].top());
		pegs[from].pop();
		cout << "\n\tMove #" << move + 1 << ": disk " << pegs[to].top() << " from peg-" << char(from + 'A') << " has moved to peg-" << char(to + 'A') << ".\n\n";
		move++;

		// Display the state of the game after each move
		displayAllTowers(pegs[0].pegSize() + pegs[1].pegSize() + pegs[2].pegSize());
	}
	else
	{
		cout << "\n\tERROR - Invalid Move.";
	}
}

//Precondition:none
//Postcondition: displays all the towers 
void towers::displayAllTowers(int numberOfRings) const
{
	if (numberOfRings > 9) {
		stack<int> tempStacks[3];
		for (int i = 0; i < 3; i++)
		{
			tempStacks[i] = pegs[i].getStack();
		}
		cout << '\t' << char(186) << '\t' << char(186) << '\t' << char(186);
		cout << endl;
		for (int i = numberOfRings; i > 0; i--)
		{

			for (int j = 0; j < 3; j++)
			{

				if (!tempStacks[j].empty() && tempStacks[j].size() >= i)
				{
					cout << "\t" << tempStacks[j].top();
					tempStacks[j].pop();
				}
				else {
					cout << "\t" << char(186);
				}
			}
			cout << endl;
		}
		cout << "     " << string(3, char(205)) << char(202) << string(3, char(205)) << " " << string(3, char(205)) << char(202) << string(3, char(205)) << " " << string(3, char(205)) << char(202) << string(3, char(205));
		cout << "\n\tA\tB\tC" << endl;
	}
	else {

		stack<int> tempStacks[3];

		for (int i = 0; i < 3; i++) {
			tempStacks[i] = pegs[i].getStack();
		}

		int baseWidth = numberOfRings * 2 + 1;

		if (numberOfRings <= 3) {
			baseWidth = max(baseWidth, 7);
		}

		for (int i = 0; i < 3; i++) {
			cout << '\t' << string((baseWidth - 7) / 2, char(32)) << string(3, char(32)) << char(186) << string(3, char(32)) << string((baseWidth - 7) / 2, char(32));
		}
		cout << endl;

		for (int i = numberOfRings; i > 0; i--) {
			for (int j = 0; j < 3; j++) {
				int space = (baseWidth - 1) / 2;

				if (!tempStacks[j].empty() && tempStacks[j].size() >= i) {
					int diskSize = tempStacks[j].top();
					int padding = (baseWidth - (diskSize * 2 + 1)) / 2;

					cout << '\t' << string(padding, char(32)) << string(diskSize, char(223)) << tempStacks[j].top() << string(diskSize, char(223)) << string(padding, char(32));
					tempStacks[j].pop();
				}
				else {
					cout << '\t' << string(space, char(32)) << char(186) << string(space, char(32));
				}
			}
			cout << endl;
		}

		for (int i = 0; i < 3; i++) {
			cout << '\t' << string((baseWidth - 7) / 2, char(32)) << string(3, char(205)) << char(202) << string(3, char(205)) << string((baseWidth - 7) / 2, char(32));
		}
		cout << endl;

		for (int i = 0; i < 3; i++) {
			cout << '\t' << string((baseWidth - 7) / 2, char(32)) << string(3, char(32)) << char('A' + i) << string(3, char(32)) << string((baseWidth - 7) / 2, char(32));
		}
		cout << endl;
	}
}
//Precondition:none
//Postcondition: checks for wins
bool towers::winCheck(int numOfRings)
{
	if (pegs[2].pegSize() == numOfRings)
	{
		return true;
	}
	else return false;
}

void towers::solveGame(int numOfRings, char fromPeg, char toPeg, char auxPeg) {
	if (numOfRings == 1) {
		moveRing(fromPeg, toPeg);
		return;
	}

	solveGame(numOfRings - 1, fromPeg, auxPeg, toPeg);

	moveRing(fromPeg, toPeg);

	solveGame(numOfRings - 1, auxPeg, toPeg, fromPeg);
}
