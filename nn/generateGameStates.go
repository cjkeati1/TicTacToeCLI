package main

import "log"

var boards = make(map[string][]float64)

func CheckBoard(board []byte) bool {
	if (board[0] == board[1] && board[1] == board[2] && board[0] != 48) ||
		(board[3] == board[4] && board[4] == board[5] && board[3] != 48) ||
		(board[6] == board[7] && board[7] == board[8] && board[6] != 48) ||
		(board[0] == board[3] && board[3] == board[6] && board[0] != 48) ||
		(board[1] == board[4] && board[4] == board[7] && board[1] != 48) ||
		(board[2] == board[5] && board[5] == board[8] && board[2] != 48) ||
		(board[0] == board[4] && board[4] == board[8] && board[0] != 48) ||
		(board[2] == board[4] && board[4] == board[6] && board[2] != 48) {
		return true
	}
	if (board[9] == board[10] && board[10] == board[11] && board[9] != 48) ||
		(board[12] == board[13] && board[13] == board[14] && board[12] != 48) ||
		(board[15] == board[16] && board[16] == board[17] && board[15] != 48) ||
		(board[9] == board[12] && board[12] == board[15] && board[9] != 48) ||
		(board[10] == board[13] && board[13] == board[16] && board[10] != 48) ||
		(board[11] == board[14] && board[14] == board[17] && board[11] != 48) ||
		(board[9] == board[13] && board[13] == board[17] && board[9] != 48) ||
		(board[11] == board[13] && board[13] == board[15] && board[11] != 48) {
		return true
	}
	return false
}
func BoardIsFull(board []byte) bool {
	for i := 0; i < 9; i++ {
		if board[i+18] == 49 {
			return false
		}
	}
	return true
}

func GenerateGameState(board []byte, turn bool) {
	offset := 0
	if turn {
		offset = 9
	}
	log.Println(board)
	boards[string(board)] = MakeRandArray(9, 1)
	for i := 0; i < 9; i++ {
		if board[i+18] == 49 {
			newBoard := make([]byte, len(board))
			for j := 0; j < len(board); j++ {
				newBoard[j] = board[j]
			}
			newBoard[i+offset] = 49
			newBoard[i+18] = 48
			if !BoardIsFull(newBoard) && !CheckBoard(board) {
				GenerateGameState(newBoard, !turn)
			}
		}

	}
}
