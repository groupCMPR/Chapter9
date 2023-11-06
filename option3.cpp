#include <iostream>
#include "towers.h"
#include "input.h"

using namespace std;

int main() {
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

    return EXIT_SUCCESS;
}
