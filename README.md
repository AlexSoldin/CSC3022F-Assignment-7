# README for CSC3022F Assignment 7

## main.cpp
This class contains the menu and and an instance of the TrainModel class. Thus limiting the amount of code contained in the main file.

## TrainModel.cpp
This class is used to create many instances of the Perceptron.cpp class thereby forming ANNs. 
* XOR() method solves the XOR problem using only perceptrons with threshold activation functions and the perceptron learning rule
* FullyConnected() trains a fully connected feed-forward neural network using a Sigmoid activation function

## Perceptron.cpp
This class contains the necessary constructors for a Perceptron of an ANN that uses a treshold activation function as well as a Sigmoid activation function.

## Makefile
The Makefile compiles and links all necessary files into the main executable.

The input is of the form: ./main  

Some examples have been commented out in the Makfile. The main commands include:
* make - compiles files
* make run - runs executable according to specific instruction
* make clean - removes executables