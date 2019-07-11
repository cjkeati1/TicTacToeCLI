#ifndef TTT_BOARD_H
#define TTT_BOARD_H

#include <vector>

class Board {
private:
    char board[9]{};
public:
    explicit Board();

    void DisplayBoard();

    bool PositionIsTaken(int position, const Board &gameBoard) const;

    char GetPosition(int pos) const;

    bool SetDownPiece(char c, int pos);

    bool ThereIsAWinner();

    bool IsATie();

    bool IsBoardFull();
};


#endif //TTT_BOARD_H
