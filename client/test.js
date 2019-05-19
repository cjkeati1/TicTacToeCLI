const expect = require("chai").expect;
const { checkBoard, boardIsFull } = require("./app.js");
describe("Tic Tac Toe Utility Functions", () => {
  describe("checkBoard()", () => {
    let board = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]];
    beforeEach(() => {
      board = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]];
    });
    it("should return false for an empty board", () => {
      expect(checkBoard(board)).to.be.false;
    });

    it("should return the winner for a major diagonal win", () => {
      board[0][0] = "X";
      board[1][1] = "X";
      board[2][2] = "X";
      expect(checkBoard(board)).to.equal("X");
    });

    it("should return the winner for a minor diagonal win", () => {
      board[2][0] = "O";
      board[1][1] = "O";
      board[0][2] = "O";
      expect(checkBoard(board)).to.equal("O");
    });
    it("should return true for a row win", () => {
      board[0][0] = "X";
      board[0][1] = "X";
      board[0][2] = "X";
      expect(checkBoard(board)).to.equal("X");
    });
    it("should return true for a column win", () => {
      board[1][0] = "O";
      board[1][1] = "O";
      board[1][2] = "O";
      expect(checkBoard(board)).to.equal("O");
    });
  });
  describe("boardIsFull()", () => {
    let board = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]];
    beforeEach(() => {
      board = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]];
    });
    it("shoud return false for an empty board", () => {
      expect(boardIsFull(board)).to.be.false;
    });
    it("should return false for a semi-full board", () => {
      board[1][0] = "X";
      board[2][0] = "O";
      board[1][1] = "X";
      board[2][2] = "O";
      expect(boardIsFull(board)).to.be.false;
    });
    it("should return true for a full board", () => {
      for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[i].length; j++) {
          board[i][j] = "X";
        }
      }
      expect(boardIsFull(board)).to.be.true;
    });
  });
});
