#ifndef TTT_BOARD_H
#define TTT_BOARD_H

#include <vector>

class Board {
private:
    char board[9]{};
public:
    explicit Board();

    void displayBoard();

    bool positionIsTaken(int position, const Board &gameBoard) const;

    char getPosition(int pos) const;

    bool setDownPiece(char c, int pos);

    bool thereIsAWinner();

    bool isATie();

    bool isBoardFull();
    
};


#endif //TTT_BOARD_H
