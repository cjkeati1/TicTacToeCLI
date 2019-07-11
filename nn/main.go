package main

import (
	"encoding/json"
	"io/ioutil"
	"log"
)

type Network struct {
	inputs        int
	hiddens       int
	outputs       int
	hiddenWeights [][]float64
	outputWeights [][]float64
	learningRate  float64
}

func createNetwork(input int, hidden int, output int, rate float64) (net Network) {
	net = Network{
		inputs:       input,
		hiddens:      hidden,
		outputs:      output,
		learningRate: rate,
	}
	net.hiddenWeights = make([][]float64, net.hiddens)
	for i := 0; i < net.hiddens; i++ {
		net.hiddenWeights[i] = MakeRandArray(net.inputs, float64(net.inputs))
	}
	net.outputWeights = make([][]float64, net.outputs)
	for i := 0; i < net.outputs; i++ {
		net.outputWeights[i] = MakeRandArray(net.hiddens, float64(net.hiddens))
	}
	return
}
func (net Network) predict(inputs []float64) []float64 {
	hiddenInputs := DotProduct(net.hiddenWeights, inputs)
	for i := 0; i < len(hiddenInputs); i++ {
		hiddenInputs[i] = Sigmoid(hiddenInputs[i])
	}
	outputs := DotProduct(net.outputWeights, hiddenInputs)
	for i := 0; i < len(outputs); i++ {
		outputs[i] = Sigmoid(outputs[i])
	}
	return outputs
}

func (net *Network) learn(inputs []float64) {
	var boardList [][]byte
	currentBoard := ConvertToByteArray(inputs)
	boardList = append(boardList, currentBoard)
	turn := true
	// for !CheckBoard(currentBoard) && !BoardIsFull(currentBoard) {
	hiddenInputs := DotProduct(net.hiddenWeights, inputs)
	for i := 0; i < len(hiddenInputs); i++ {
		hiddenInputs[i] = Sigmoid(hiddenInputs[i])
	}
	outputs := DotProduct(net.outputWeights, hiddenInputs)
	for i := 0; i < len(outputs); i++ {
		outputs[i] = Sigmoid(outputs[i])
	}
	_, bestChoice := ArrayMax(outputs)
	if currentBoard[bestChoice+18] != 48 {
		if turn {
			currentBoard[bestChoice] = 49
		} else {
			currentBoard[bestChoice+9] = 49
		}
		currentBoard[bestChoice+18] = 48
		turn = !turn
	}
	if len(boards[string(currentBoard)]) == 0 {
		boards[string(currentBoard)] = MakeRandArray(9, 1)
	}
	targets := boards[string(currentBoard)]
	outputErrors := make([]float64, len(targets))
	for i := 0; i < len(targets); i++ {
		outputErrors[i] = targets[i] - outputs[i]
	}
	// hiddenErrors := DotProduct(MatTranspose(net.outputWeights), outputErrors)
	outputErrorByOutputs := make([]float64, len(outputErrors))
	for i := 0; i < len(outputErrors); i++ {
		outputErrorByOutputs[i] = SigmoidPrime(outputs[i]) * outputErrors[i]
	}
	hiddenWeightTotals := make([]float64, len(outputs))
	for i := 0; i < len(outputs); i++ {
		hiddenWeightTotals[i] = 0
		for j := 0; j < len(net.hiddenWeights); j++ {
			hiddenWeightTotals[i] += net.hiddenWeights[j][i]
		}
	}
	outputWeightErrors := make([]float64, net.hiddens)
	for i := 0; i < net.hiddens; i++ {
		outputWeightErrors[i] = 0
		for j := 0; j < len(net.hiddenWeights); j++ {
			outputWeightErrors[i] += net.hiddenWeights[j][i] * outputErrors[i] / hiddenWeightTotals[i]
		}
	}
	log.Println(outputWeightErrors)

	boardList = append(boardList, currentBoard)
	PrintBoard(currentBoard)
	// }
}
func main() {
	net := createNetwork(27, 9, 9, 0.1)
	initialBoard := make([]float64, 27)
	for i := 0; i < 27; i++ {
		initialBoard[i] = 0
		if i >= 18 {
			initialBoard[i] = 1
		}
	}
	// log.Println(net.predict(initialBoard))
	log.Println(net.outputWeights)
	// net.learn(initialBoard)
	// GenerateGameState(ConvertToByteArray(initialBoard), false)
	// boards is lookup table
	boardsJSON, _ := json.Marshal(boards)
	ioutil.WriteFile("boards.json", boardsJSON, 0644)
}
