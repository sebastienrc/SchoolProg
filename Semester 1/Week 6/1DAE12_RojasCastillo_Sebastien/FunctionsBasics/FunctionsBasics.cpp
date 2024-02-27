// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 1DAE12_RojasCastillo_Sebastien

#include "pch.h"
#include <iostream>

int main()
{
    srand(int(time(nullptr)));
    /*Sum(50, 30);
    Sum(40, 20);
    Sum(70, 100);
    TestPrint();
    TestMultiply();*/
    //TestModulo();
   // TestPrintNumber();
   // TestCalcElapsedTime();
    //TestPrintMessage();
   // TestIsEven();
    //TestIsLeapYear();
   // TestGetFloatRand();
   // TestGetRand();
    TestGetDistance();
}



void Sum( int a,int b) {
    int sum = a + b;
    std::cout << a << " + " << b << " = " << sum << std::endl;
    return;
}

void PrintInt(unsigned int value, char delimiter)
{
    std::cout << value << delimiter;
}
void PrintChar(char value, char delimiter)
{
    std::cout << value << delimiter;
}
void PrintFloat(float value, char delimiter)
{
    std::cout << value << delimiter;
}
void TestPrint()
{
    PrintChar('a', ',');
    PrintInt(20, ',');
    PrintFloat(20.0f, ',');
}

int Multiply(int a, int b) {
    int res = a * b;
    return res;
}   

void TestMultiply() {
    int a{};
    int b{};
    int c{};
    int d{};
    std::cout << "-- Functions that calculate the product of 2 integers -- " << std::endl;
    std::cout << "2 numbers to multiply?";
    std::cin >> a>>b;
    std::cout << a << " * " << b << " = " << Multiply(a,b) << std::endl;
    std::cout << "4 numbers to multiply?";
    std::cin >> a >> b >> c >> d;
    std::cout << a << " * " << b << " * " << c << " * " << d << " = " << Multiply(Multiply(a, b), Multiply(c, d)) << std::endl;

}

int Modulo(int initialNumber, int divisor) {
    int quotient = initialNumber / divisor;
    int correction = quotient * divisor;
    int res = initialNumber - correction;
    return res;
}

void TestModulo() {
    int a{};
    int b{};
    std::cout << "-- Functions that calculate the modulo of an integers -- " << std::endl;
    std::cout << "number folowed by the modulo?";
    std::cin >> a>>b;
    std::cout << a << " % " << b << " = " << Modulo(a,b) << std::endl;
}

void PrintNumber(int start, int end) {
    while (start <= end) {
        std::cout << start << " ";
        start++;
    }
    std::cout<<std::endl;
}

void TestPrintNumber() {
    std::cout << "-- Funtion that prints the integers in a given interval -- "<<std::endl;
    std::cout << "Interval [10, 20]" << std::endl;
    PrintNumber(10, 20);
    std::cout << "Interval [90, 115]" << std::endl;
    PrintNumber(90, 115);
}


float CalcElapsedTime(int start, int end) {
    std::chrono::steady_clock::time_point startTime(std::chrono::steady_clock::now());
    for (int i = start; i <= end; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::chrono::steady_clock::time_point endTime(std::chrono::steady_clock::now());

    std::chrono::duration<float, std::milli> elapsedTime{ endTime - startTime };
    return elapsedTime.count();
}

void TestCalcElapsedTime() {
    std::cout << "-- Funtion that counts the time of a printing task --";
    std::cout << "Interval [0, 30]" << std::endl;
    std::cout << " This print task took " << CalcElapsedTime(0, 30) << " milliseconds" << std::endl;

    std::cout << "Interval [0, 400]" << std::endl;
    std::cout << " This print task took " << CalcElapsedTime(0, 400) << " milliseconds" << std::endl;
}

void PrintMessage(int spaces) {
    if (spaces == 0) {
        std::cout << "No ";
    }
    else {
        for (int i = 0; i <= spaces; i++)
        {
            std::cout << " ";
        }
        std::cout << spaces << " spaces ";
    }
    std::cout << "indentation specified" << std::endl;
}

void TestPrintMessage() {
   std::cout << "-- Function that prints an indented message --";
    PrintMessage(0);
    PrintMessage(2);
    PrintMessage(4);
}

bool IsEven(int number) {
    if (number % 2 == 0)
        return true;
    else return false;
}

void TestIsEven() {
    std::cout << "-- Function that checks whether a number is even --" << std::endl;
    int randomNumber{rand()};
    for (int i = 0; i < 6; i++)
    {
        if (IsEven(randomNumber))
            std::cout << randomNumber << " is even" << std::endl;
        else std::cout << randomNumber << " is odd" << std::endl;
        randomNumber = rand();
    }
    
}bool IsLeapYear(int year) {
    
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else return false;
        }
        else return true;
    }
    else return false;

}

void TestIsLeapYear() {
    int year{};
    bool activeLoop{true};
    std::cout << "-- Function that checks whether year is leap -- " << std::endl;
    
    while (activeLoop)
    {
        std::cout << "Year? ";
        std::cin >> year;
        if (year <= 0)
            activeLoop = false;
        else {

            if (IsLeapYear(year))
                std::cout << year << " has 29 days in February" << std::endl;
            else std::cout << year << " has 28 days in February" << std::endl;

        }
    }
}

int GetRand(int min, int max) {
    int randomInt{};
    randomInt = rand() % (max + 1) + min;

    return randomInt;
}

void TestGetRand() {
    std::cout << "-- Function that generates a random number in a given integer interval --" << std::endl;
    std::cout << "In [1, 6] " << GetRand(1, 6) << std::endl;
    std::cout << "In [10, 20] " << GetRand(10, 20) << std::endl;
    std::cout << "In [-5, 0] " << GetRand(-5, 0) << std::endl;
}

float GetRand(float min, float max) {
    float randomFloat{};
    int intMin{int(min * 100)};
    int intMax{int(max * 100)};
    
    randomFloat = rand() % ((intMax * + 1) + intMin);
    randomFloat = randomFloat / 100.f;

    return randomFloat;

}

void TestGetFloatRand() {
    std::cout << "-- Function that generates a random number in a given float interval --" << std::endl;
    std::cout << "In [0, 3.14159] " << GetRand(0.f, 3.14159f) << std::endl;
    std::cout << "In [-2, 3] " << GetRand(-2.f, 3.f) << std::endl;
}

float GetDistance(float x1, float y1, float x2, float y2) {
    float distance{};

    distance = sqrtf(powf((x2 - x1), 2) + powf((y2 - y1), 2));

    return distance;

}

float GetDistance(struct Point2f first, struct Point2f second) {
    float distance{};

    distance = sqrtf(powf((second.x - first.x), 2) + powf((second.y - first.y), 2));
    
    return distance;

}

void TestGetDistance() {
    float firstCoX{ GetRand(0.f,300.f) };
    float secondCoX{ GetRand(0.f,300.f) };
    float firstCoY{ GetRand(0.f,300.f) };
    float secondCoY{ GetRand(0.f,300.f) };

    Point2f firstCo{ firstCoX,firstCoY };
    Point2f secondCo{ secondCoX,secondCoY };

    std::cout << "-- Function that calculates distance between 2 points --" << std::endl;

    for (int i = 0; i < 2; i++)
    {
        
        std::cout << "Distance between [" << firstCoX << ", " << firstCoY << "] and " <<
            "[" << secondCoX << ", " << secondCoY << "]" << std::endl;
        std::cout << "Calling one version: " << GetDistance(firstCoX, firstCoY, secondCoX, secondCoY) << std::endl;
        std::cout << "Calling the other version: " << GetDistance(firstCo, secondCo) << std::endl;


        firstCoX = GetRand(0.f, 300.f);
        firstCoY = GetRand(0.f, 300.f);
        secondCoX = GetRand(0.f, 300.f);
        secondCoY = GetRand(0.f, 300.f);

        firstCo.x = firstCoX;
        firstCo.y = firstCoY;
        secondCo.x = secondCoX;
        secondCo.y = secondCoY;


    }


}
