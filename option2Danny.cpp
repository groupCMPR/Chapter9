#include <iostream>
#include <random>
#include "input.h"
 
using namespace std;
 
//precondition: recieves an integer for lowest number, int for highest number, integer for count
//postconditioN: recurvsive function that finds the number the user guesses
void guess(int low, int high, int& count)
{
    if (low == high)
    {
        cout << "\n\nYour number must be " << low;
        cout << "\nNumber of guesses: " << count << endl; return;
    }
 
    int showGuess = (low + high) / 2;
    cout << "\n\n\tIs your number " << showGuess;
    char input = inputChar("? (Y-yes or N-no): ", static_cast<string>("YN"));
 
    if (input == 'Y' || input == 'y')
    {
        count++;
        cout << "\n\n\tNumber of guesses: " << count << "\n\n\t";
    }
    else if (input == 'N' || input == 'n') {
        count++;
        cout << "\n\tIs your number larger than " << showGuess;
        char input2 = inputChar("? (Y-yes or N-no)", static_cast<string>("YN"));
 
        if (input2 == 'Y' || input2 == 'y') {
            guess(showGuess + 1, high, count);
        }
        else if (input2 == 'N' || input2 == 'n') {
            guess(low, showGuess - 1, count);
        }
    }
    else { //did he do this on purpose? i doubt it
 
        cout << "\nNumber of guesses: " << count << endl; return;
    }
    
}
 
 
int main()
{
    random_device rd;//random device to seed the generator
    mt19937 gen(rd()); //pseudo random number generator
    uniform_int_distribution<int> dist(400, 1000);
 
    int random_number = dist(gen);
 
    cout << "\n\t2> Guess your number between 1 to " << random_number << ".";
    cout << "\n\n\tThink of a number from 1 to " << random_number << ".";
    cout << "\n\n\tPress any key to begin...";
    cin.get();
 
    int count = 0;
    int low = 1;
 
    guess(low, random_number, count);
}
 
