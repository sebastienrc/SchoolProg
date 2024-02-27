// Expressions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Rojas Castillo, Sébastien - 1DAE12

#include "pch.h"
#include <iostream>

int main()
{
    int firstNumber{5};
    int secondNumber{ -45 };
    float firstFloat{54.9f};
    float secondFloat{ -26.71f };
    char firstLetter{'h'};
    char secondLetter{ 'n' };

    std::cout <<"My first number + my second equals: " << firstNumber + secondNumber << std::endl;
    std::cout << "My first number + 20 equals: " << firstNumber + 20 << std::endl;
    std::cout << "My first number - 20 equals: " << firstNumber - 20 << std::endl;
    std::cout << "My first number - my second equals: " << firstNumber - secondNumber << std::endl;

    std::cout << "My first float + my second equals: " << firstFloat + secondFloat << std::endl;
    std::cout << "My first float + 9.81 equals: " << firstFloat + 9.81f << std::endl;
    std::cout << "My first float - 1.58 equals: " << firstFloat - 1.58f << std::endl;
    std::cout << "My first float - my second equals: " << firstFloat - secondFloat<< std::endl;

    std::cout << "My first letter + my second: " << firstLetter + secondLetter<< std::endl;
    std::cout << "My first letter - my second:  " << firstLetter- secondLetter << std::endl;
    std::cout << "My first letter + e equals: " << firstLetter + 'e'<<std::endl;
    std::cout << "My second letter + p equals: " << secondLetter + 'p'<<std::endl;

    std::cout << "My first letter + 5 equals: " << firstLetter + 5 << std::endl;
    std::cout << "My first letter - 5 equals: " << firstLetter - 5 << std::endl;
    std::cout << "My first letter + my first number: " << firstLetter + firstNumber << std::endl;   
    std::cout << "My second letter - my second number: " << firstLetter + secondNumber << std::endl;


    std::cout << "My first number * my second equals: " << firstNumber * secondNumber << std::endl;
    std::cout << "My first number / 20 equals: " << firstNumber * 20 << std::endl;

    std::cout << "My first float * my second equals: " << firstFloat * secondFloat << std::endl;
    std::cout << "My first float / 9.81 equals: " << firstFloat * 9.81f << std::endl;

    std::cout << "My first number divided by a smaller one equals: " << firstNumber / 3 << std::endl;


    std::cout << "[(first float / second float) * (second number / first number) + 50] equals: "
        << ((firstFloat / secondFloat) * (secondNumber / firstNumber) + 50 ) << std::endl;

    //Compound Assignment Operators : += , -=, *=, /=, %=

    //Unary Operators : (a,b variable) a = a++, b=++a, b=b-- , b=++b,  a=-a, c=!c (c=bool)


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
