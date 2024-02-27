#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

// Rojas Castillo,Sebastien - 1DAE12

void TestOneParFunctions();

int main( )
{
	const double pi{ 3.1415926535 };
	double angle{0};

	// 1. Show my data
	std::cout << "My name is Rojas Castillo, Sébastien" << std::endl;
	std::cout << "I am in group 1DAE12" << std::endl << std::endl;

	// 2. Show my student history
	std::cout << "Name of my high school: Sint-Victor Alsemberg" << std::endl;
	std::cout << "In the last year I had 8 hours math a week" << std::endl << std::endl;

	// Wait

	

#pragma region angle
	std::cout << "Use existing functions with 1 parameter \n";

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;

	angle = pi / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;

	angle = pi / 2;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;

	angle = (3 * pi) / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;

	angle = pi;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "cos: " << cos(angle) << std::endl;
#pragma endregion angle


	TestOneParFunctions();
	std::cout << "Push ENTER to quit\n";
	std::cin.get( );

	return 0;
}

void TestOneParFunctions() { //Testing function
	double base{ 2.0 };
	double exponent{ 8.0 };

	double result = pow(base, exponent);
	std::cout << result << std::endl;

	exponent = 2.0;
	result = (sqrt	(pow(3, exponent) + pow(4, exponent)));
	std::cout << result << std::endl;
}