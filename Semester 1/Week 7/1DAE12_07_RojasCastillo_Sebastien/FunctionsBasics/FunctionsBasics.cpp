// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1DAE12_RojasCastillo_Sebastien

#include "pch.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


int main()
{

    //

}

double CalcCosSin(double radians,double sine, double cossine) {

}

void TestCalcCosSi() {
    int radian{};
    std::cout << "--Function that calculates cosine and sine --" << std::endl;
    std::cout << "\tRadians\tCos\tSin" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        radian = (rand() % int((2 * M_PI) * 100) ) / 100.0;
        CalcCosSin(radian);
        std::cout<<
    }
 }