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

        Perceptron(const double firstWeight, const double secondWeight, const double threshold, const double learningRate);


};

#endif 