// BasicAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
   // TestCount();
}

int Count(int arr[], int arrSize, int CountNr) {
    int counter{};


    for (int i{}; i < arrSize; i++) {

        if (arr[i] == CountNr)
            counter++;
    }
    return counter;
}

void TestCount() {
    int countNr1{ 2 };
    int countNr2{ 1 };

    std::cout << "--Test of Count Function" << std::endl;
    for (int i{ 0 }; i < ARRLENGTH_NR1; i++)
    {
        std::cout << arrNr1[i] << " ";
    }
    std::cout << std::endl;
    std::cout<<countNr1<<" occurs " << Count(arrNr1, ARRLENGTH_NR1, countNr1)
        <<" times in this array"<<std::endl;
}
