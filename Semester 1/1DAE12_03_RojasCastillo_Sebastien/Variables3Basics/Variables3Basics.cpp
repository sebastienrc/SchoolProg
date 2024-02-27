// Variables3Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1DAE12 - Rojas Castillo, Sebastien

#include "pch.h"
#include <iostream>


void OperatingSizeOf();
void HexAndBinValues();
void RangeOfValues();

int main()
{
    OperatingSizeOf();
    HexAndBinValues();
    RangeOfValues();
}



void OperatingSizeOf(){
    int someInt{41};
    float someFloat{51.21f};
    double someDouble{1.6427};
    bool someBool{true};

    std::cout << sizeof(someInt) << std::endl;
    std::cout << sizeof(someFloat) << std::endl;
    std::cout << sizeof(someDouble) << std::endl;
    std::cout << sizeof(someBool) << std::endl;
}

void HexAndBinValues() {
    int decimal{12};
    int hex{0xC};
    int binary{0b00001100};

    std::cout << decimal << std::endl;
    std::cout << hex << std::endl;
    std::cout << binary << std::endl;
    

}

void RangeOfValues() {
    int minNormalInt{-2147483648};
    int maxNormalInt{2147483647};
    unsigned int minUnsignedInt{0};
    unsigned int maxUnsignedInt{4294967295};

    std::cout << minNormalInt << std::endl;
    std::cout << maxNormalInt << std::endl;
    std::cout << minUnsignedInt << std::endl;
    std::cout << maxUnsignedInt << std::endl;

    minNormalInt--;
    maxNormalInt++;
    minUnsignedInt--;
    maxUnsignedInt++;

    std::cout << minNormalInt << std::endl;
    std::cout << maxNormalInt << std::endl;
    std::cout << minUnsignedInt << std::endl;
    std::cout << maxUnsignedInt << std::endl;



}

