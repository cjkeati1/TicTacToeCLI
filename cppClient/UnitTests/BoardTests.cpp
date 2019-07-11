#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Board.h"

TEST_CASE("Check that the game ends when it's supposed to", "[GameEnds]") { // The board has positions 1-9
    Board board;

    SECTION("Top row win") {
        board.setDownPiece('X', 1);
        board.setDownPiece('X', 2);
        board.setDownPiece('X', 3);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Middle row win") {
        board.setDownPiece('O', 4);
        board.setDownPiece('O', 5);
        board.setDownPiece('O', 6);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Bottom row win") {
        board.setDownPiece('X', 7);
        board.setDownPiece('X', 8);
        board.setDownPiece('X', 9);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Left column win") {
        board.setDownPiece('O', 1);
        board.setDownPiece('O', 4);
        board.setDownPiece('O', 7);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Middle column win") {
        board.setDownPiece('X', 2);
        board.setDownPiece('X', 5);
        board.setDownPiece('X', 8);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Right column win") {
        board.setDownPiece('X', 3);
        board.setDownPiece('X', 6);
        board.setDownPiece('X', 9);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Diagonal 1 win") {
        board.setDownPiece('X', 1);
        board.setDownPiece('X', 5);
        board.setDownPiece('X', 9);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Diagonal 2 win") {
        board.setDownPiece('X', 3);
        board.setDownPiece('X', 5);
        board.setDownPiece('X', 7);

        bool isThereAWinner = board.thereIsAWinner();

        CHECK(isThereAWinner);
    }
    SECTION("Tie game") {
        // X O X
        // O X O
        // O X O
        board.setDownPiece('X', 1);
        board.setDownPiece('O', 2);
        board.setDownPiece('X', 3);
        board.setDownPiece('O', 4);
        board.setDownPiece('X', 5);
        board.setDownPiece('O', 6);
        board.setDownPiece('O', 7);
        board.setDownPiece('X', 8);
        board.setDownPiece('O', 9);

        bool isThereAWinner = board.thereIsAWinner();
        bool isATie = board.isATie();

        CHECK(!isThereAWinner);
        CHECK(isATie);
    }

    SECTION("Incomplete Game"){
        board.setDownPiece('O', 1);
        board.setDownPiece('O', 2);

        bool isThereAWinner = board.thereIsAWinner();
        bool isATie = board.isATie();

        CHECK(!isThereAWinner);
        CHECK(!isATie);
    }
}



