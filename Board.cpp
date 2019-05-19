//
// Created by User on 5/19/2019.
//

#include <cmath>
#include <string>
#include "Board.h"

Board::Board() : board{"1", "2", "3", "4", "5", "6", "7", "8", "9"} {}

Board::~Board() = default;

void Board::displayBoard() {
    for (int i = 0; i < BOXES; ++i) {
        if (i % 3 == 0 && i != 0) std::cout << "\n\n";
        std::cout << board[i] << "   ";
    }
    std::cout << "\n\n";
}

bool Board::getPlayerInput(int position, int player) {
    if (board[position - 1] != "X" && board[position - 1] != "O") {
        if (player == 1) board[position - 1] = "X";
        else if (player == 2) board[position - 1] = "O";

        return true;
    }
    std::cout << "ERROR: Position '" << position << "' is already occupied. Choose another." << std::endl;
    return false;
}

bool Board::checkGameState() {
    return (board[0] == board[1] && board[1] == board[2]) ||
           (board[3] == board[4] && board[4] == board[5]) ||
           (board[6] == board[7] && board[7] == board[8]) ||
           (board[0] == board[3] && board[3] == board[6]) ||
           (board[1] == board[4] && board[4] == board[7]) ||
           (board[2] == board[5] && board[5] == board[8]) ||
           (board[0] == board[4] && board[4] == board[8]) ||
           (board[2] == board[4] && board[4] == board[6]);
}

void Board::resetBoard() {
    for (int i = 0; i < BOXES; ++i) {
        board[i] = std::to_string(i + 1);
    }
}


