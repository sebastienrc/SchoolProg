// FlowControlBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    //PrintTruthTable();
    //CompareTwoNumbers();
   // CalculatePrice();
   // ConvertDayNumber();
  //CheckLeapYear();
    ConvertSeconds();
    UseActorState();
    UsePoint2f();

}



void PrintTruthTable() {
    bool boolTrue{true};
    bool boolFalse{false};
    std::cout << "-- Print truth table --" << std::endl;
        
        std::cout << "Logical binary AND-Operator (&&)" << std::endl;
    std::cout << "true && true is " << std::boolalpha << (boolTrue && boolTrue) << std::endl;
    std::cout << "true && false is " << std::boolalpha << (boolTrue && boolFalse) << std::endl;
    std::cout << "false && true is " << std::boolalpha << (boolFalse && boolTrue) << std::endl;
    std::cout << "false && false is " << std::boolalpha << (boolFalse && boolFalse) << std::endl;
    
        std::cout << "Logical binary OR-Operator (||)" << std::endl;
    std::cout << "true && true is " << std::boolalpha << (boolTrue || boolTrue) << std::endl;
    std::cout << "true && false is " << std::boolalpha << (boolTrue || boolFalse) << std::endl;
    std::cout << "false && true is " << std::boolalpha << (boolFalse || boolTrue) << std::endl;
    std::cout << "false && false is " << std::boolalpha << (boolFalse || boolFalse) << std::endl;
        std::cout << "Logical unary NOT-Operator (!)" << std::endl;
    std::cout << "!true is " << std::boolalpha << (!boolTrue) << std::endl;
    std::cout << "!false is " << std::boolalpha << (!boolFalse) << std::endl;
}

void CompareTwoNumbers() {
    srand(unsigned int (time(nullptr)));
    int firstNumber{ rand() % 11 };
    int secondNumber{ rand() % 11 };
    std::cout << "-- Compare 2 numbers --" << std::endl;
    std::cout << "First Number is " << firstNumber << std::endl;
    std::cout << "Second Number is " << secondNumber << std::endl;
    if (firstNumber < secondNumber)
        std::cout << "Second number is larger than first one" << std::endl;
    else std::cout << "First number is larger than second one" << std::endl;
}

void CalculatePrice() {
    int numberOfBallpoints{};
    float totalPrice{};
    float under20Price{ 4.00f };
    float under50Price{ 3.50f };
    float under101Price{ 3.25f };
    float above101{ 3.10f };

    std::cout << "-- Calculate price --\nNr of ballpoints? " << std::endl;
    std::cin >> numberOfBallpoints;
    if (numberOfBallpoints < 20)
        totalPrice = numberOfBallpoints * under20Price;
    else if (numberOfBallpoints < 50)
        totalPrice = numberOfBallpoints * under50Price;
    else if (numberOfBallpoints < 101)
        totalPrice = numberOfBallpoints * under101Price;
    else totalPrice = numberOfBallpoints * above101;
    std::cout << "Total price is " << totalPrice << std::endl;
}

void ConvertDayNumber() {
    int dayOfTheWeek{};
    std::cout << "Day number [1, 7] ?" << std::endl;
    std::cin >> dayOfTheWeek;

    switch (dayOfTheWeek)
    {
    case 1:
        std::cout << "Start of the week" << std::endl;
        break;
    case 2:
    case 3:
    case 4:
        std::cout << "Middle of the week" << std::endl;
        break;
    case 5:
        std::cout << "Nearly weekend" << std::endl;
        break;
    case 6:
    case 7:
        std::cout << "Weekend" << std::endl;
        break;
    default:
        std::cout << "Wrong day number" << std::endl;
        break;
    }
}

void CheckLeapYear() {
    int year{};
    std::cout << "-- Check leap year --\nYear ?" << std::endl;
    std::cin >> year;
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                std::cout << "February has 29 days" << std::endl;
            }
            else
                std::cout << "February has 28 days" << std::endl;
        }
        else
            std::cout << "February has 29 days" << std::endl;
    }
    else
        std::cout << "February has 28 days" << std::endl;

}

void ConvertSeconds() {
    int nrOfSeconds{};
    int days{};
    int hours{};
    int minutes{};
    int seconds{};

    std::cout << "-- convert seconds --" << std::endl;
    std::cin >> nrOfSeconds;

    if (nrOfSeconds > 60) {
        if ((nrOfSeconds % 86400) > 0) {
            days++;
            nrOfSeconds -= 86400;
        }
        else if ((nrOfSeconds % 3600) > 0) {
            hours++;
            nrOfSeconds -= 3600;
        }
        else if ((nrOfSeconds % 60) > 0) {
            minutes++;
            nrOfSeconds -= 60;
        }
    }
    else
        seconds += nrOfSeconds;





     std::cout << days << " days" << std::endl;
    std::cout << hours << " hours" << std::endl;
    std::cout << minutes << " minutes" << std::endl;
    std::cout << seconds << " seconds" << std::endl;

}

void UseActorState() {

}

void UsePoint2f() {

}