#include <iostream>

#include "Board.h"

Board::Board() {
    for (int i = 0; i < 9; ++i) { // Create board. Number positions 1 - 9
        board[i] = '0' + (i + 1);
    }
}

void Board::DisplayBoard() {
    for (int i = 0; i < 9; ++i) {
        std::cout << board[i] << ((i + 1) % 3 != 0 ? "   " : "\n\n"); // Print new line every 3 positions
    }
}

bool Board::PositionIsTaken(int position, const Board &gameBoard) const {
    return !isdigit(GetPosition(position)); // If the position value is not a number,
                                            // then it is an X or O - Thus, it is not open
}

char Board::GetPosition(int pos) const {
    return board[pos];
}

bool Board::SetDownPiece(char c, int pos) {
    board[pos - 1] = c;
    return true;
}

bool Board::ThereIsAWinner() {
    return (board[0] == board[1] && board[1] == board[2]) ||
           (board[3] == board[4] && board[4] == board[5]) ||
           (board[6] == board[7] && board[7] == board[8]) ||
           (board[0] == board[3] && board[3] == board[6]) ||
           (board[1] == board[4] && board[4] == board[7]) ||
           (board[2] == board[5] && board[5] == board[8]) ||
           (board[0] == board[4] && board[4] == board[8]) ||
           (board[2] == board[4] && board[4] == board[6]);
}

bool Board::IsATie() {
    return IsBoardFull() && !ThereIsAWinner();
}

bool Board::IsBoardFull() {
    for (char i : board) {
        if (isdigit(i))
            return false; // If it finds a spot with a digit (1-9)
    }
    return true;
}








