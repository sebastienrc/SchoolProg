// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H
#include <chrono>
#include <math.h>

// add headers that you want to pre-compile here

struct Point2f
{
	float x;
	float y;
};

void Sum(int a, int b);

void PrintInt(unsigned int value, char delimiter);
void PrintChar(char value, char delimiter);
void PrintFloat(float value, char delimiter);
void TestPrint();
int Multiply(int a, int b);
void TestMultiply();
int Modulo(int initialNumber, int divisor);
void TestModulo();
void PrintNumber(int start,int end);
void TestPrintNumber();
float CalcElapsedTime(int start, int end);
void TestCalcElapsedTime();
void PrintMessage(int spaces);
void TestPrintMessage();
bool IsEven(int number);
void TestIsEven();

bool IsLeapYear(int year);
void TestIsLeapYear();

int GetRand(int min, int max);
void TestGetRand();

float GetRand(float min, float max);
void TestGetFloatRand();

float GetDistance(float x1, float y1, float x2, float y2);
float GetDistance(struct Point2f first, struct Point2f second);
void TestGetDistance();


#endif //PCH_H
