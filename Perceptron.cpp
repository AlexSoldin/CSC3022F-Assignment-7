#include "Perceptron.h"

Perceptron::Perceptron(double firstWeight, double secondWeight, const double threshold, const double learningRate) : firstWeight(firstWeight), secondWeight(secondWeight), threshold(threshold), learningRate(learningRate) {}

Perceptron::Perceptron(double firstWeight, double secondWeight, double thirdWeight, const double threshold, const double learningRate, double bias) : firstWeight(firstWeight), secondWeight(secondWeight), thirdWeight(thirdWeight), threshold(threshold), learningRate(learningRate), bias(bias) {}

double Perceptron::activationThreshold(std::pair<double, double> p, const double targetValue, const int train)
{
    double first = p.first;
    double second = p.second;

    // Compute weighted sum
    double weightedSum = firstWeight * first + secondWeight * second;
    // std::cout << "Weighted Sum: " << weightedSum << "\n";

    if (weightedSum > threshold)
    {
        if (targetValue != 1 && train == 1)
            updateWeights(targetValue, 1, p);
        return 1;
    }
    else
    {
        if (targetValue != 0 && train == 1)
            updateWeights(targetValue, 0, p);
        return 0;
    }
}

double Perceptron::activationSigmoid(std::vector<double> values)
{
    double result;
    int size = values.size();
    switch (size)
    {
    case 2:
        double first = values.at(0);
        double second = values.at(1);
        double exponentTerm = first * firstWeight + second * secondWeight + bias;
        result = 1 / (1 + exp(-exponentTerm));
        break;
    case 3:
        double first = values.at(0);
        double second = values.at(1);
        double third = values.at(2);
        double exponentTerm = first * firstWeight + second * secondWeight + third * thirdWeight + bias;
        result = 1 / (1 + exp(-exponentTerm));
        break;
    }
    return result;
}

void Perceptron::updateWeights(const double targetValue, const double output, std::pair<double, double> p)
{
    double firstDelta = learningRate * (targetValue - output) * p.first;
    double secondDelta = learningRate * (targetValue - output) * p.second;
    firstWeight += firstDelta;
    secondWeight += secondDelta;
}
