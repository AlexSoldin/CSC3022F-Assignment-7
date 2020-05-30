#include "Perceptron.h"

Perceptron::Perceptron(double firstWeight, double secondWeight, const double threshold, const double learningRate) : 
firstWeight(firstWeight), secondWeight(secondWeight), threshold(threshold), learningRate(learningRate) {}

double Perceptron::activationFunction(std::pair<double, double> p, const double targetValue, const int train){
    double first = p.first;
    double second = p.second;

    // Compute weighted sum
    double weightedSum = firstWeight*first + secondWeight*second;
    // std::cout << "Weighted Sum: " << weightedSum << "\n";

    if(weightedSum > threshold){
        if (targetValue!=1 && train==1) updateWeights(targetValue, 1, p);
        return 1;
    }
    else{
        if (targetValue!=0 && train==1) updateWeights(targetValue, 0, p);
        return 0;
    }
}

void Perceptron::updateWeights(const double targetValue, const double output, std::pair<double, double> p){
    double firstDelta = learningRate * (targetValue - output) * p.first;
    double secondDelta = learningRate * (targetValue - output) * p.second;
    firstWeight += firstDelta;
    secondWeight += secondDelta;
}

