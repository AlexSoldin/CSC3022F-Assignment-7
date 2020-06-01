#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "TrainModel.h"

using namespace std;

// Main Method
int main(int argc, char * argv[]){

    TrainModel train;
    
    // Menu
    int choice;
    do
    {
        cout << "--------------------------\nChoose from the following:\n--------------------------" << endl;
        cout << "0: Quit" << endl;
        cout << "1: Question 1" << endl;
        cout << "2: Question 2" << endl;
       
        cin >> choice;

        if (choice == 1) train.XOR();
        else if (choice == 2) train.XOR();
        else if (choice) cout << "Invalid Choice. Please try again.\n" << endl;

    } while (choice != 0);    

    return 0;

}