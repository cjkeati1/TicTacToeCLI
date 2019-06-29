package main

import (
	"log"
	"math"

	"gonum.org/v1/gonum/stat/distuv"
)

func PrintBoard(board []byte) {
	boardArr := make([]string, 9)
	for i := 0; i < 9; i++ {
		if board[i] == 49 {
			boardArr[i] = "X"
		}
	}
	for i := 9; i < 18; i++ {
		if board[i] == 49 {
			boardArr[i-9] = "O"
		}
	}
	for i := 0; i < 9; i++ {
		if boardArr[i] == "" {
			boardArr[i] = "null"
		}
	}
	for i := 0; i < 9; i += 3 {
		log.Println(boardArr[i], " ", boardArr[i+1], " ", boardArr[i+2])
	}
	log.Println("")
}
func ConvertToByteArray(floatArr []float64) []byte {
	var byteArr []byte
	for i := 0; i < len(floatArr); i++ {
		if floatArr[i] == 0 {
			byteArr = append(byteArr, 48)
		} else {
			byteArr = append(byteArr, 49)
		}
	}
	return byteArr
}
func ConvertToFloatArr(byteArr []byte) []float64 {
	var floatArr []float64
	for i := 0; i < len(byteArr); i++ {
		if byteArr[i] == 48 {
			floatArr = append(floatArr, 0)
		} else {
			floatArr = append(floatArr, 1)
		}
	}
	return floatArr
}
func ArrayMax(arr []float64) (max float64, idx int) {
	max = 0
	idx = -1
	for i := 0; i < len(arr); i++ {
		if arr[i] > max {
			max = arr[i]
			idx = i
		}
	}
	return
}
func MakeRandArray(size int, v float64) []float64 {
	dist := distuv.Uniform{
		Min: -1 / math.Sqrt(v),
		Max: 1 / math.Sqrt(v),
	}
	array := make([]float64, size)
	for i := 0; i < size; i++ {
		array[i] = dist.Rand()
	}
	return array
}
func Sigmoid(x float64) float64 {
	return 1 / (1 + math.Exp(-1*x))
}
func SigmoidPrime(x float64) (y float64) {
	return Sigmoid(x) * (1 - Sigmoid(x))
}

func DotProduct(a [][]float64, b []float64) []float64 {
	product := make([]float64, len(a))
	for i := 0; i < len(a); i++ {
		var sum float64 = 0
		for j := 0; j < len(a[0]); j++ {
			sum += a[i][j] * b[j]
		}
		product[i] = sum
	}
	return product
}

func MatTranspose(matrix [][]float64) (transposedArr [][]float64) {
	transposedArr = make([][]float64, len(matrix[0]))
	for i := 0; i < len(matrix[0]); i++ {
		transposedArr[i] = make([]float64, len(matrix))
		for j := 0; j < len(matrix); j++ {
			transposedArr[i][j] = matrix[j][i]
		}
	}
	return
}

func ScaleMatrix(factor float64, matrix [][]float64) (scaledMatrix [][]float64) {
	scaledMatrix = make([][]float64, len(matrix))
	for i := 0; i < len(matrix); i++ {
		scaledMatrix[i] = make([]float64, len(matrix[i]))
		for j := 0; j < len(matrix[i]); j++ {
			scaledMatrix[i][j] = matrix[i][j] * factor
		}
	}
	return
}
