package main

import (
	"math",
	"gonum.org/v1/gonum/mat"
)

func Sigmoid(x float64) float64 {
	return 1 / (1 + math.Exp(-1*x))
}

func dotProduct(a [][]int, b [][]int) [][]int{

}
func main() {

}