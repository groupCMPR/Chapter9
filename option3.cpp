#include <iostream>
#include "towers.h"
#include "input.h"

using namespace std;

int mainMenu();
void option3();

int main() {

    do {
        system("cls");
        switch (mainMenu()) {
        case 0: return EXIT_SUCCESS;
        case 3: system("cls"); option3(); break;
        default: cout << "\n\tERROR - INVALID CHOICE";
        }
        cout << "\n\n\t";
        system("pause");

    } while (true);
}

void option3() {

    char playAgain;

    do {
        int numOfRings = inputInteger("\n\tEnter the number of rings (1...64): ", 1, 64);
        cout << endl;
        towers game(numOfRings);

        game.displayAllTowers(numOfRings);

        game.solveGame(numOfRings, 'A', 'C', 'B');

        cout << "\n\tCongratulations! The game has been solved in " << game.getMove() << " moves."; // this gets the size reformat to show moves later

        playAgain = inputChar("\n\tPlay again? (Y-yes or N-no): ", 'y', 'n');
    } while (toupper(playAgain) == 'Y');

    return;
}


int mainMenu() {
    cout << "\n\tCMPR131 Chapter 9: Recursive Applications";
    cout << "\n\t" << string(100, char(205));
    cout << "\n\t 1> Pattern of astricks and blanks";
    cout << "\n\t 2> Guess a number";
    cout << "\n\t 3> Solve Tower of Hanoi";
    cout << "\n\t 4> Solve n-Queens";
    cout << "\n\t" << string(100, char(196));
    cout << "\n\t 0> Exit";
    cout << "\n\t" << string(100, char(205));
    return inputInteger("\n\t Option: ", 0, 4);
}
