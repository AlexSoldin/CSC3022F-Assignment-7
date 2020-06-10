#include "TrainModel.h"

using namespace std;

TrainModel::TrainModel() {}

bool TrainModel::iterate(pair<double, double> input, Perceptron &p1, Perceptron &p2, Perceptron &p3, const double targetValue1, const double targetValue2, const double targetValue3, const int train, const int test)
{
    double x1 = p1.activationThreshold(input, targetValue1, train);
    double x2 = p2.activationThreshold(input, targetValue2, train);
    pair<double, double> x3(x1, x2);

    double result = p3.activationThreshold(x3, targetValue3, train);

    if (train == 1 || test == 1)
    {
        cout << "Expected: " << targetValue3;
        cout << "\tActual:\t" << result << endl;
    }

    if (targetValue3 == result)
        return true;
    return false;
}

void TrainModel::XOR()
{
    // Possible logic inputs
    pair<double, double> input1(0, 0);
    pair<double, double> input2(1, 0);
    pair<double, double> input3(0, 1);
    pair<double, double> input4(1, 1);

    // Create training dataset
    vector<pair<double, double>> trainingSet;
    for (int i = 0; i < 5; i++)
    {
        trainingSet.push_back(input1);
        trainingSet.push_back(input2);
        trainingSet.push_back(input3);
        trainingSet.push_back(input4);
    }

    Perceptron p11(-1, 0.5, 1, 0.8);  //AND
    Perceptron p12(0.1, 0.1, 0, 0.8); //OR
    Perceptron p2(-5, -5, 0, 0.8);    //AND(NOT AND, OR) = XOR

    cout << "--------------------------\nTest Set (Before):\n--------------------------\n";
    bool test1 = iterate(input1, p11, p12, p2, 0, 0, 0, 0, 1);
    bool test2 = iterate(input2, p11, p12, p2, 0, 1, 1, 0, 1);
    bool test3 = iterate(input3, p11, p12, p2, 0, 1, 1, 0, 1);
    bool test4 = iterate(input4, p11, p12, p2, 1, 1, 0, 0, 1);

    for (int i = 0; i < trainingSet.size(); i++)
    {
        cout << "--------------------------\nTraining Example " << (i + 1) << ":\n--------------------------\n";
        bool train = iterate(trainingSet[i], p11, p12, p2, 0, 0, 0, 1, 0);
        bool done1 = iterate(input1, p11, p12, p2, 0, 0, 0, 0, 0);
        bool done2 = iterate(input2, p11, p12, p2, 0, 1, 1, 0, 0);
        bool done3 = iterate(input3, p11, p12, p2, 0, 1, 1, 0, 0);
        bool done4 = iterate(input4, p11, p12, p2, 1, 1, 0, 0, 0);
        bool done = done1 && done2 && done3 && done4;
        if (done)
        {
            cout << "\nTrained After " << (i + 1) << " Iterations\n\n";
            break;
        }

        i++;
        cout << "--------------------------\nTraining Example " << (i + 1) << ":\n--------------------------\n";
        train = iterate(trainingSet[i], p11, p12, p2, 0, 1, 1, 1, 0);
        done1 = iterate(input1, p11, p12, p2, 0, 0, 0, 0, 0);
        done2 = iterate(input2, p11, p12, p2, 0, 1, 1, 0, 0);
        done3 = iterate(input3, p11, p12, p2, 0, 1, 1, 0, 0);
        done4 = iterate(input4, p11, p12, p2, 1, 1, 0, 0, 0);
        done = done1 && done2 && done3 && done4;
        if (done)
        {
            cout << "\nTrained After " << (i + 1) << " Iterations\n\n";
            break;
        }

        i++;
        cout << "--------------------------\nTraining Example " << (i + 1) << ":\n--------------------------\n";
        train = iterate(trainingSet[i], p11, p12, p2, 0, 1, 1, 1, 0);
        done1 = iterate(input1, p11, p12, p2, 0, 0, 0, 0, 0);
        done2 = iterate(input2, p11, p12, p2, 0, 1, 1, 0, 0);
        done3 = iterate(input3, p11, p12, p2, 0, 1, 1, 0, 0);
        done4 = iterate(input4, p11, p12, p2, 1, 1, 0, 0, 0);
        done = done1 && done2 && done3 && done4;
        if (done)
        {
            cout << "\nTrained After " << (i + 1) << " Iterations\n\n";
            break;
        }

        i++;
        cout << "--------------------------\nTraining Example " << (i + 1) << ":\n--------------------------\n";
        train = iterate(trainingSet[i], p11, p12, p2, 1, 1, 0, 1, 0);
        done1 = iterate(input1, p11, p12, p2, 0, 0, 0, 0, 0);
        done2 = iterate(input2, p11, p12, p2, 0, 1, 1, 0, 0);
        done3 = iterate(input3, p11, p12, p2, 0, 1, 1, 0, 0);
        done4 = iterate(input4, p11, p12, p2, 1, 1, 0, 0, 0);
        done = done1 && done2 && done3 && done4;
        if (done)
        {
            cout << "\nTrained After " << (i + 1) << " Iterations\n\n";
            break;
        }
    }

    cout << "--------------------------\nTest Set (After):\n--------------------------\n";
    test1 = iterate(input1, p11, p12, p2, 0, 0, 0, 0, 1);
    test2 = iterate(input2, p11, p12, p2, 0, 1, 1, 0, 1);
    test3 = iterate(input3, p11, p12, p2, 0, 1, 1, 0, 1);
    test4 = iterate(input4, p11, p12, p2, 1, 1, 0, 0, 1);
    cout << endl;
}

void TrainModel::FullyConnected()
{
    double input1 = 1.30;
    double input2 = 2.7;
    double input3 = 0.8;

    Perceptron p11(0.1, 0.2, 0.5, 0, 0.8, 0.1);
    Perceptron p12(-0.4, 1.0, -0.6, 0, 0.8, -0.3);
    Perceptron p2(0.8, 1.0, 0, 0, 0.8, -0.3);

    double p11Output = p11.activationSigmoid({input1, input2, input3});
    double p12Output = p12.activationSigmoid({input1, input2, input3});

    cout << "Hidden Layer Perceptron 1: " << p11Output
         << "\nHidden Layer Perceptron 2: " << p12Output << "\n\n";

    double p2Output = p2.activationSigmoid({p11Output, p12Output});
    cout << "Output Layer Perceptron: " << p2Output << "\n\n";

    double MSE = pow(p2Output - 0.36, 2);
    cout << "Mean Squared Error for ANN Input x: " << MSE << "\n\n";
}