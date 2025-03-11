#include <iostream>
#include <cstdlib>
#include <ctime>    
#include "Header1.h"

using namespace std;



int main(){
    int maxRange;
    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Enter the maximum number in the range (from 1 to ?): ";
    cin >> maxRange;

    NumberGuessingGame game(maxRange);
    GameStatus status = Ongoing;
    int userGuess;

    while (status == Ongoing) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        status = game.guess(userGuess);
    }

    cout << "Congratulations! You guessed the correct number in " << game.getAttempts() << " attempts." << endl;
    return 0;
}
