//
// Created by User on 5/19/2019.
//

#include <iostream>
#include <string.h>
#include <limits>
#include <cmath>

#include "Board.h"

bool isInteger(int input);

int main() {
    Board board;
    int player = 1, position = 0, elapsedTurns = 0;
    bool gameOver, repeat;
    char playAgain = 0;

    do {
        board.displayBoard();
        elapsedTurns++;

        std::cout << "Player " << player << "'s" << ((player == 1) ? " (X)" : " (O)") << " turn. Choose a position"
                  << std::endl;

        // Will loop if the user's input is invalid
        do {

            // Loops if user does not enter an integer
            while (!(std::cin >> position)) {
                std::cout << "ERROR: Please enter an integer (1-9)." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            // If user entered a position within the bounds of the array
            if (isInteger(position) && position > 0 && position < 10) {
                repeat = board.getPlayerInput(position, player);
            } else {
                std::cout << "ERROR: Please enter an integer (1-9)." << std::endl;
                repeat = false;
            }
        } while (!repeat);

        // Game over if someone has won or if no one won and the board is full (tie)
        gameOver = board.didSomeoneWin() || elapsedTurns >= 9;

        // Game Over
        if (gameOver) {
            board.displayBoard();
            if (board.didSomeoneWin())
                std::cout << "Player " << player << ((player == 1) ? " (X)" : " (O)") << " wins!" << std::endl;
            else if (elapsedTurns >= 9)
                std::cout << "Tie Game!" << std::endl;

            std::cout << "Play again? (y/n)" << std::endl;
            while (!(std::cin >> playAgain) || (playAgain != 'y' && playAgain != 'n')) {
                std::cout << "ERROR: Please enter 'y' or 'n'." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (playAgain != 'n') {
                board.resetBoard();
                elapsedTurns = 0;
            }
        }

        // Switch players
        if (player == 1) player++;
        else if (player == 2) player--;


    } while (playAgain != 'n');
}

bool isInteger(int input) {
    return floor(std::abs(input)) == std::abs(input);
}
