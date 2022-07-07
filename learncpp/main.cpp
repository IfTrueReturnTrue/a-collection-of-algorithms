//Main file
#include <thread>
#include <iostream>
#include <cmath>
#include <tuple>
#include "Header.h"
using namespace std;

int main()
{
    
    //input();
    //experimental sus function
    double min;
    double max;
    double precision;
    cout << "Enter the minimum bound:\n";
    cin >> min;
    cout << "Enter the maximum bound:\n";
    cin >> max;
    cout << "Enter the precision (Number of decimal places):\n";
    cin >> precision;
    
    int num = solve_sus_equation(pow(10, -precision), min, max);
    cout << "\n" << num << " is the number of total solutions.";
    printf("\n\nPress the ENTER key to exit...");
    getchar();
    
}

