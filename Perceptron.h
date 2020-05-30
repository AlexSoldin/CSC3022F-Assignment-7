#include <iostream>
#include <string>
#include <vector>
#include <utility>

#ifndef PERCEP_H
#define PERCEP_H

class Perceptron {
    public:
        double firstWeight;
        double secondWeight;
        double threshold;
        double learningRate;

        Perceptron(double firstWeight, double secondWeight, const double threshold, const double learningRate);

        double activationFunction(std::pair<double, double> p, const double targetValue, const int train);
        void updateWeights(const double targetValue, const double output, std::pair<double, double> p);

};

#endif 