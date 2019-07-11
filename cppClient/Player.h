#ifndef TTT_PLAYER_H
#define TTT_PLAYER_H


#include "Board.h"

class Player {
private:
    char XOrO;
    int playerNumber;
public:
    explicit Player(int playerNum, char XorO);

    bool choosePosition(Board &gameBoard);

    char getXOrO() const;

    void hasWon();
};


#endif //TTT_PLAYER_H
