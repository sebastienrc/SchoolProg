// Variables2Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  Rojas Castillo, Sébastien - 1DAE12

#include "pch.h"
#include<string>
#include <iostream>

void ExploreStrings();

int main()
{
    ExploreStrings();

    int randomNumber{5};
    float randomFloat{};

    std::cout << "Ever or uneven number, give me one to see\n";
    int evenOrOdd{};
    std::cin >> evenOrOdd;
    std::cout << evenOrOdd % 2 << std::endl;
    srand(int(time(nullptr)));
    std::cout << rand() << std::endl;
    randomNumber = rand() % 50;
    std::cout << randomNumber<<std::endl;
    randomNumber = rand() % 70 + 10;
    std::cout << randomNumber << std::endl;
    randomNumber = rand() % 40 - 20;
    std::cout << randomNumber << std::endl;
    randomNumber = rand() % 4 - 2;
    std::cout << randomNumber << std::endl;


    randomFloat = (rand() % 101 + 50)/10.f;
    std::cout << randomFloat << std::endl;
    char character{};
    std::cout << "Letter?" ;
    std::cin >> character;
    int ascii{ character };
    std::cout << "\nLetter " << character << " , ASCII value " << ascii << std::endl;
    char randomCharacter{ rand() % 58 + 65 };
    int randomAscii{ randomCharacter };
    std::cout << "Random letter " << randomCharacter << ", ASCII value " << randomAscii<<std::endl;

    float firstFloat{ 5.44f };
    float secondFloat{ 5.45f };
    float thirdFloat{ 5.51f };

    std::cout << firstFloat << ", rounded: " << roundf(firstFloat) << ", int cast: " << int(firstFloat)<<std::endl;
    std::cout << secondFloat << ", rounded: " << roundf(secondFloat) << ", int cast: " << int(secondFloat)<<std::endl;
    std::cout << thirdFloat << ", rounded: " << roundf(thirdFloat) << ", int cast: " << int(thirdFloat)<<std::endl;

    std::cout << "The aspect ratio of full HD (1920 x 1080 is: " << 1920 / float(1080)<<std::endl;

    int i{ 10 };
    int j{ ++i };
    std::cout << "i: " << i << ", j: " << j << std::endl;
    int k{ 10 };
    int l{ k++ };
    std::cout << "k: " << k << ", l: " << l << std::endl;


}

void ExploreStrings() {
    std::string myText;
    std::string myOtherText{ "I am a string literal" };
    std::cout << myText << std::endl;
    std::cout << myOtherText << std::endl;
    myOtherText = "Just changed my text";
    std::cout << myOtherText<<std::endl;
    std::cout << "Please enter a text without spaces" << std::endl;
    std::cin >> myText;
    std::cout << myText<< std::endl;


    std::string firstWord{};
    std::string secondWord{};
    char myChar{ 'a' };

    std::cout << "First word? ";
    std::cin >> firstWord;
    std::cout << "\n Second Word? "<<std::endl;
    std::cin >>secondWord;
    std::string combinedText{ firstWord + secondWord };
    std::cout << combinedText << std::endl;
    std::cout << "key" + secondWord << std::endl;
    std::cout << 'a' + firstWord<<std::endl;
    std::cout << myChar + firstWord<<std::endl;

    int enteredNr{};
    std::string numbersLog{};
    std::cout << "Enter an integer value: "<<std::endl;
    std::cin >> enteredNr;
    numbersLog = numbersLog + " " + std::to_string(enteredNr);

    std::cout << "Enter an integer value: " << std::endl;
    std::cin >> enteredNr;
    numbersLog = numbersLog + " " + std::to_string(enteredNr);

    std::cout << "Enter an integer value: " << std::endl;
    std::cin >> enteredNr;
    numbersLog = numbersLog +" " + std::to_string(enteredNr);

    std::cout << numbersLog << std::endl;

    std::string intString{ "3" };
    std::string floatString{ "3.1415" };
    int StringToInt{ std::stoi(intString) };
    float StringToFloat{std::stof(floatString) };
    std::cout << "One string contains: " << intString << std::endl;
    std::cout << "Other string contains contains: " << floatString << std::endl;
    std::cout << "Adding strings " << intString + floatString << std::endl;
    std::cout << "adding numbers " << StringToFloat + StringToInt << std::endl;
    






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
  