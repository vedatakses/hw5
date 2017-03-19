//
// Created by VeraxMedax on 19/03/2017.
//

#include <iostream>
#include "ClockPatience.h"

int playGame(int index) {
    int count = 0;

    for (int i = 0; i < index; i++) {

        ClockPatience game;
        game.pileCards();
        game.startGame();

        if (game.isGameWon()) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(time(NULL));

    int winningCount = playGame(100);

    cout << "Game played 100 times" << endl;
    cout << "Winning rate is: " << winningCount << "/ " << 100 << endl;

    return 0;
}