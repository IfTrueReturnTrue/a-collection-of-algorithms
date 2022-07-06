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
   
    int num = solve_sus_equation(0.00001, -1000, 500);
    cout << "\n" << num << " is the number of total solutions.";
    
}

