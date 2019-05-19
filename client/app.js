const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout
});
// readline.question("Enter input: \n", ans => {
//   console.log(ans);
// });
let board = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]];
let turn = true; // true == X, false == O;

const printBoard = board => {
  console.log("____0___1___2__");
  let i = 0;
  for (let row of board) {
    console.log(String(i++), "|", row.join(" | "), "|");
    console.log("_______________");
  }
};
const checkBoard = board => {
  for (let row of board) {
    if (row[0] === row[1] && row[1] === row[2] && row[0] !== " ") {
      return row[0];
    }
  }
  for (let i = 0; i < board.length; i++) {
    if (
      board[0][i] === board[1][i] &&
      board[1][i] === board[2][i] &&
      board[0][i] !== " "
    ) {
      return board[0][i];
    }
  }
  if (
    board[0][0] === board[1][1] &&
    board[1][1] === board[2][2] &&
    board[0][0] !== " "
  ) {
    return board[0][0];
  }
  if (
    board[2][0] === board[1][1] &&
    board[1][1] === board[0][2] &&
    board[2][0] !== " "
  ) {
    return board[2][0];
  }
  return false;
};
const boardIsFull = board => {
  for (let row of board) {
    for (let piece of row) {
      if (piece === " ") {
        return false;
      }
    }
  }
  return true;
};
const playGame = () => {
  printBoard(board);
  readline.question(
    `${
      turn ? "X's Turn" : "O's Turn"
    }\n Enter the coords of your move (Ex: '0,0')\n`,
    ans => {
      ans = ans.split(",");
      ans[0] = Number(ans[0]);
      ans[1] = Number(ans[1]);
      if (!board[ans[1]] || !board[ans[1]][ans[0]]) {
        console.log("Invalid Move");
        playGame();
      }
      if (board[ans[1]][ans[0]] !== " ") {
        console.log("Invalid Move");
        playGame();
      } else {
        board[ans[1]][ans[0]] = turn ? "X" : "O";
        let winner = checkBoard(board);
        let full = boardIsFull(board);
        if (winner) {
          printBoard(board);
          console.log(`${checkBoard(board)} Wins!`);
          promptRestart();
        } else if (full) {
          printBoard(board);
          console.log("Cat's Game!");
          promptRestart();
        } else {
          turn = !turn;
          playGame();
        }
      }
    }
  );
};
const promptRestart = () => {
  readline.question("Play Again? (y/n)\n", res => {
    if (res === "y") {
      board = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]];
      playGame();
    } else {
      process.exit(0);
    }
  });
};
playGame();

module.exports = {
  checkBoard,
  boardIsFull
};
