#pragma once
#include <iostream>
#include <cstdlib>


using namespace std;

enum GameStatus {Ongoing, Won};

class NumberGuessingGame {
private:
    int secretNumber;
    int attempts;

public:

    NumberGuessingGame(int maxRange) {
        srand(time(0));
        secretNumber = rand() % maxRange + 1;
        attempts = 0;
    }

    GameStatus guess(int number) {
        attempts++;
        if (number == secretNumber) {
            return Won;
        }
        else {
            if (number < secretNumber) {
                cout << "Too low! Try again." << endl;
            }
            else {
                cout << "Too high! Try again." << endl;
            }
            return Ongoing;
        }
    }

    int getAttempts() {
        return attempts;
    }
};