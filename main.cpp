//
// Created by User on 5/19/2019.
//

#include <iostream>
#include <string.h>

#include "Board.cpp"

int main() {
    Board board;
    int player = 1;
    int position;
    bool gameState;
    bool repeat;

    board.displayBoard();

    do {
        std::cout << "Player " << player << "'s" << ((player == 1) ? " (X)" : " (O)") << " turn. Choose a position"
                  << std::endl;

        do {
            std::cin >> position;
            repeat = board.getPlayerInput(position, player);
        } while (!repeat);

        board.displayBoard();
        gameState = board.checkGameState();

        if ((gameState))
            std::cout << "Player " << player << ((player == 1) ? " (X)" : " (O)") << " wins!" << std::endl;

        if (player == 1) player++;
        else if (player == 2) player--;

    } while (!gameState);


}