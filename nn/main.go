package main

import (
	"log"
	"math"

	"gonum.org/v1/gonum/stat/distuv"
)

type Network struct {
	inputs        int
	hiddens       int
	outputs       int
	hiddenWeights []int
	outputWeights []int
	learningRate  float64
}

func sigmoid(x float64) float64 {
	return 1 / (1 + math.Exp(-1*x))
}

func dotProduct(a [][]int, b []int) []int {
	product := make([]int, len(a))
	for i := 0; i < len(a); i++ {
		sum := 0
		for j := 0; j < len(a[0]); j++ {
			sum += a[i][j] * b[j]
		}
		product[i] = sum
	}
	return product
}
func createNetwork(input int, hidden int, output int, rate float64) (net Network) {
	net = Network{
		inputs:       input,
		hiddens:      hidden,
		outputs:      output,
		learningRate: rate,
	}
	net.hiddenWeights = make([][]int, randomArray(len(hidden)))
	return
}
func randomArray(size int, v float64) (data []float64) {
	dist := distuv.Uniform{
		Min: -1 / math.Sqrt(v),
		Max: 1 / math.Sqrt(v),
	}

	data = make([]float64, size)
	for i := 0; i < size; i++ {
		data[i] = dist.Rand()
	}
	return
}
func main() {
	log.Println("hello world")
	var a = [][]int{{1, 2}, {3, 4}}
	var b = []int{5, 6}
	log.Println(dotProduct(a, b))
	log.Println(randomArray(3, 1))
}
