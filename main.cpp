//
// Created by User on 5/19/2019.
//

#include <iostream>
#include <string.h>
#include <limits>

#include "Board.cpp"

bool isInteger(int input);

int main() {
    Board board;
    int player = 1;
    int position = 0;
    int turns = 0;
    bool gameState;
    bool repeat;
    char playAgain;

    do {
        board.displayBoard();

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
        turns++;

        gameState = board.checkGameState() || turns >= 9;

        if (gameState) {
            board.displayBoard();
            if (board.checkGameState())
                std::cout << "Player " << player << ((player == 1) ? " (X)" : " (O)") << " wins!" << std::endl;
            else if (turns >= 9)
                std::cout << "Tie Game!" << std::endl;
            std::cout << "Play again? (y/n)" << std::endl;

            while (!(std::cin >> playAgain) || (playAgain != 'y' && playAgain != 'n')) {
                std::cout << "ERROR: Please enter 'y' or 'n'." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            gameState = (playAgain == 'n');

            if (!gameState) {
                board.resetBoard();
                turns = 0;
            }

        }

        if (player == 1) player++;
        else if (player == 2) player--;


    } while (!gameState);
}

bool isInteger(int input) {
    return std::floor(std::abs(input)) == std::abs(input);
}
