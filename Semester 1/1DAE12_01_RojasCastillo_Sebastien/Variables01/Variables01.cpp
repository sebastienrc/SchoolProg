// Variables01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Rojas Castillo,Sebastien - 1DAE12

#include "pch.h"
#include <iostream>

int main() {
    //Variables
    int wholeNumber{51};
    float floatingNumber{153.5f};
    double doubleNumber{8.0145};
    char letter{'h'};
    bool isSomething{false};

    std::cout << "number? " << wholeNumber;
    std::cout << "\nfloating number? " << floatingNumber;
    std::cout << "\ndouble number? " << doubleNumber;
    std::cout << "\nletter? " << letter;
    std::cout << "\nis something true(1) or false(0)? " << isSomething;

    wholeNumber = 12;
    floatingNumber = 14.3f;
    doubleNumber = 2.518;
    letter = 'v';
    isSomething = true;

    std::cout << "\nnumber? " << wholeNumber;
    std::cout << "\nfloating number? " << floatingNumber;
    std::cout << "\ndouble number? " << doubleNumber;
    std::cout << "\nletter? " << letter;
    std::cout << "\nis something true(1) or false(0)? " << isSomething;

    std::cout << "\nnumber? ";
    std::cin >> wholeNumber;
    std::cout<< wholeNumber;

    std::cout << "\nfloating number? ";
    std::cin >> floatingNumber;
    std::cout<< floatingNumber;

    std::cout << "\ndouble number? ";
    std::cin >> doubleNumber;
    std::cout << doubleNumber;

    std::cout << "\nletter? ";
    std::cin >> letter;
    std::cout << letter;

    std::cout << "\nis something true(1) or false(0)? ";
    std::cin >> isSomething;
    std::cout << isSomething;





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
