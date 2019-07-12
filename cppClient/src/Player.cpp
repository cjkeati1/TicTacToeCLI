#include <iostream>
#include <limits>
#include "Player.h"


Player::Player(int playerNum, char XOrO) : playerNumber(playerNum), XOrO(XOrO) {}

bool Player::choosePosition(Board &gameBoard) {
    int pos = 0;
    std::cout << "Player " << playerNumber << "'s (" << getXOrO() << ")" << " turn. Choose a position." << std::endl;
    bool choseValidPosition;
    do {
        while (!(std::cin >> pos)) {
            std::cout << "ERROR: Please enter an integer (1-9)." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (pos > 0 && pos < 10) {
            pos -= 1; // Array starts at 0 index
            if (!gameBoard.positionIsTaken(pos, gameBoard)) {
                gameBoard.setDownPiece(XOrO, pos);
                choseValidPosition = true;
            } else {
                std::cout << "That position is already occupied. Choose again." << std::endl;
                choseValidPosition = false;
            }
        } else {
            std::cout << "ERROR: Please enter an integer (1-9)." << std::endl;
            choseValidPosition = false;
        }

    } while (!choseValidPosition);

    return true;
}

char Player::getXOrO() const {
    return XOrO;
}

void Player::hasWon() {
    std::cout << "Player  " << playerNumber << " (" << getXOrO() << ")" << " has won!" << std::endl;
}







