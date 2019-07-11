#include <iostream>
#include "Player.h"
#include "Board.h"

int main() {
    Player playerOne{1, 'X'}; // Create two players. An X and an O
    Player playerTwo{2, 'O'};
    Board board;

    int player = 1;

    do {
        board.displayBoard();
        player == 1 ? playerOne.choosePosition(board) : playerTwo.choosePosition(board); // Choose a position
        player = player == 1 ? 2 : 1; // Switch players
    } while (!board.thereIsAWinner() && !board.isATie());

    board.displayBoard(); // Display final board

    if (board.isATie())
        std::cout << "\n-------GAME OVER-------\nIt's a tie!\n";
    else {
        std::cout << "\n-------GAME OVER-------\n";
        player == 1 ? playerTwo.hasWon()  // Players will switch before the game ends so whoever is
                    : playerOne.hasWon(); // the player at this point is the loser
    }

    return 0;
}