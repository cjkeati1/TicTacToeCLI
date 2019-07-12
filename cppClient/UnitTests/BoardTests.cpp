#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Board.h"
#include <string>

TEST_CASE("Check that the game ends when it's supposed to", "[GameEnds]") { // The board has positions 1-9
    Board board;

    SECTION("Top row win") {
        board.setDownPiece('X', 0);
        board.setDownPiece('X', 1);
        board.setDownPiece('X', 2);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Middle row win") {
        board.setDownPiece('O', 3);
        board.setDownPiece('O', 4);
        board.setDownPiece('O', 5);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Bottom row win") {
        board.setDownPiece('X', 6);
        board.setDownPiece('X', 7);
        board.setDownPiece('X', 8);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Left column win") {
        board.setDownPiece('O', 0);
        board.setDownPiece('O', 3);
        board.setDownPiece('O', 6);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Middle column win") {
        board.setDownPiece('X', 1);
        board.setDownPiece('X', 4);
        board.setDownPiece('X', 7);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Right column win") {
        board.setDownPiece('X', 2);
        board.setDownPiece('X', 5);
        board.setDownPiece('X', 8);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Diagonal 1 win") {
        board.setDownPiece('X', 0);
        board.setDownPiece('X', 4);
        board.setDownPiece('X', 8);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Diagonal 2 win") {
        board.setDownPiece('X', 2);
        board.setDownPiece('X', 4);
        board.setDownPiece('X', 6);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Tie game") {
        // X O X
        // O X O
        // O X O
        board.setDownPiece('X', 0);
        board.setDownPiece('O', 1);
        board.setDownPiece('X', 2);
        board.setDownPiece('O', 3);
        board.setDownPiece('X', 4);
        board.setDownPiece('O', 5);
        board.setDownPiece('O', 6);
        board.setDownPiece('X', 7);
        board.setDownPiece('O', 8);

        bool isThereAWinner = board.thereIsAWinner();
        bool isATie = board.isATie();

        CHECK(!isThereAWinner);
        CHECK(isATie);
    }

    SECTION("Incomplete Game") {
        board.setDownPiece('O', 1);
        board.setDownPiece('O', 2);

        bool isThereAWinner = board.thereIsAWinner();
        bool isATie = board.isATie();

        CHECK(!isThereAWinner);
        CHECK(!isATie);
    }
}

TEST_CASE("Board helper functions work properly", "[HelperFunctions]") {
    Board board;

    SECTION("SetDownPiece_CallsSetDownPiece_SetsDownTheGivenCharAtTheGivenPosition") {
        bool originalBoardIsThereAnXAtFive = (board.getPosition(5) == 'X');

        board.setDownPiece('X', 5);

        bool finalBoardIsThereAnXAtFive = (board.getPosition(5) == 'X');

        CHECK(!originalBoardIsThereAnXAtFive);
        CHECK(finalBoardIsThereAnXAtFive);

    }

    SECTION("GetPosition_CallsGetPosition_ReturnsCharacterAtTheGivenPosition") {
        board.setDownPiece('O', 4);
        board.setDownPiece('X', 5);
        board.setDownPiece('O', 6);

        char charAtPositionFive = board.getPosition(5);

        CHECK(charAtPositionFive == 'X');
    }

    SECTION("PositionIsTaken_ChecksIfAPositionTakenAndItIs_ReturnsTrue") {
        board.setDownPiece('O', 5);
        board.setDownPiece('X', 6);

        bool isFiveTaken = board.positionIsTaken(5, board);
        bool isSixTaken = board.positionIsTaken(6, board);

        CHECK(isFiveTaken);
        CHECK(isSixTaken);
    }

    SECTION("PositionIsTaken_ChecksIfAPositionTakenAndItIsNot_ReturnsFalse") {
        bool isFiveTaken = board.positionIsTaken(5, board);

        CHECK(!isFiveTaken);
    }

    SECTION("IsBoardFull_BoardIsFull_ReturnsTrue") {
        board.setDownPiece('X', 0);
        board.setDownPiece('X', 1);
        board.setDownPiece('X', 2);
        board.setDownPiece('X', 3);
        board.setDownPiece('X', 4);
        board.setDownPiece('X', 5);
        board.setDownPiece('X', 6);
        board.setDownPiece('X', 7);
        board.setDownPiece('X', 8);

        bool isBoardFull = board.isBoardFull();

        CHECK(isBoardFull);
    }
    SECTION("IsBoardFull_BoardIsNotFull_ReturnsFalse") {
        board.setDownPiece('X', 1);

        bool isBoardFull = board.isBoardFull();

        CHECK(!isBoardFull);
    }
}



