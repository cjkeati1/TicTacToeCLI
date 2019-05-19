//
// Created by User on 5/19/2019.
//

#ifndef TicTacToeCLI_BOARD_H
#define TicTacToeCLI_BOARD_H

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

#endif //TicTacToeCLI_BOARD_H
