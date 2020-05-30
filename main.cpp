#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "Perceptron.h"

using namespace std;

// Main Method
int main(int argc, char * argv[]){
    pair<double,double> input1(0,0);
    pair<double,double> input2(1,0);
    pair<double,double> input3(0,1);
    pair<double,double> input4(1,1);

    // Create training dataset 
    vector<pair<double, double>> trainingSet;
    for(int i=0; i < 5; i++){
        trainingSet.push_back(input1);
        trainingSet.push_back(input2);
        trainingSet.push_back(input3);
        trainingSet.push_back(input4);
    }

    Perceptron p11(-1, 0.5, 1, 0.8);    //AND
    Perceptron p12(0.1, 0.1, 0, 0.8);    //OR
    Perceptron p2(-5, -5, 0, 0.8);      //AND(NOT AND, OR) = XOR
    
}