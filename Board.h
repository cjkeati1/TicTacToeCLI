//
// Created by User on 5/19/2019.
//

#ifndef LINKEDLIST_BOARD_H
#define LINKEDLIST_BOARD_H

class Board {
private:
    static const int BOXES = 9;
    std::string board[BOXES];

public:
    Board();

    virtual ~Board();

    bool getPlayerInput(int position, int player);

    bool checkGameState();

    void displayBoard();

    void resetBoard();
};

#endif //LINKEDLIST_BOARD_H
