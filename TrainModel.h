#include "Perceptron.h"

#ifndef TRAINMODEL_H
#define TRAINMODEL_H

class TrainModel
{
public:
    TrainModel();

    bool iterate(std::pair<double, double> input, Perceptron &p1, Perceptron &p2, Perceptron &p3, const double targetValue1, const double targetValue2, const double targetValue3, const int train, const int test);
    void XOR();
    void FullyConnected();
};

#endif