// ArrayBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "structs.h"
#include <iostream>

int main()
{
	int numbers1Arr[ARRAYSIZE]{};
	int numbers2Arr[]{ 10,20,30,40,50 };
	int numbers3Arr[ARRAYSIZE]{ 5,10,15 };
	Point2f arrPoints[ARRAYSIZE]{};

	std::cout << "-- Accesing elements --" << std::endl;
	std::cout << "First element: " << numbers3Arr[0] << std::endl;
	std::cout << "Last element: " << numbers3Arr[4] << std::endl;
	std::cout << "\nIterating over the elements" << std::endl;


	for (int i = 0; i < ARRAYSIZE; i++)
	{
		std::cout << numbers3Arr[i] << " ";
}
	std::cout << "\n\n--Size of arrays" << std::endl;
	std::cout << "\t2nd array" << std::endl;
	std::cout << "\tnr of bytes: " << sizeof(numbers2Arr) << std::endl;
	std::cout << "\tsize of one element: " << sizeof(numbers2Arr[0]) << std::endl;
	std::cout << "\tnr of elements: " << sizeof(numbers2Arr) / sizeof(numbers2Arr[0]) << std::endl;

	std::cout << "\n-- The elements occupy consecutive memory locations --\nArray of int types" << std::endl;
	for (int i{ 0 }; i < ARRAYSIZE; i++){

		std::cout << "Address of element with index " << i << " is " << &numbers1Arr[i] << std::endl;

	}
	std::cout << "\n\nArray of Point2f types" << std::endl;
	for (int i{ 0 }; i < ARRAYSIZE; i++) {

		std::cout << "Address of element with index " << i << " is " << &arrPoints[i] << std::endl;

	}
}