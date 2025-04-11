#include <iostream>
#include <cstdlib>
#include <ctime>    
#include "Header1.h"

using namespace std;

int main(){
    int maxRange;
    string playerName;
    char playAgain;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Enter your name: ";
    cin >> playerName;

    Player player(playerName);

    do {
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
    
        int attempts = game.getAttempts();
        cout << "Congratulations! You guessed the correct number in " << game.getAttempts() << " attempts." << endl;


        player.updateBestScore(attempts);
        player.displayStats();

        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;

    } 
    
    while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing, ";
    player.finalDisplayStats();

    return 0;
}


