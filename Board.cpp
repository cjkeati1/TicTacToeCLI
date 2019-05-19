//
// Created by User on 5/19/2019.
//

#include "Board.h"

Board::Board() : board{{"1", "2", "3"},
                       {"4", "5", "6"},
                       {"7", "8", "9"}} {}

Board::~Board() = default;

void Board::displayBoard() {
    for (auto &i : board) {
        for (const auto &j : i) {
            std::cout << j << "  ";

        }
        std::cout << "\n";

    }


}

