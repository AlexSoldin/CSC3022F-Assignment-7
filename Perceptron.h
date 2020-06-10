#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <math.h>

#ifndef PERCEP_H
#define PERCEP_H

class Perceptron
{
public:
    double firstWeight;
    double secondWeight;
    double thirdWeight;
    double threshold;
    double learningRate;
    double bias;

    Perceptron(double firstWeight, double secondWeight, const double threshold, const double learningRate);
    Perceptron(double firstWeight, double secondWeight, double thirdWeight, const double threshold, const double learningRate, double bias);

    double activationThreshold(std::pair<double, double> p, const double targetValue, const int train);
    double activationSigmoid(std::vector<double> values);
    void updateWeights(const double targetValue, const double output, std::pair<double, double> p);
};

#endif