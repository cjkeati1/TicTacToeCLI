//
// Created by User on 5/19/2019.
//

#ifndef LINKEDLIST_BOARD_H
#define LINKEDLIST_BOARD_H


class Board {
private:
    static const int ROWS = 3;
    static const int COLUMNS = 3;
    std::string board[ROWS][COLUMNS];


public:
    Board();

    virtual ~Board();

    void displayBoard();

};


#endif //LINKEDLIST_BOARD_H
