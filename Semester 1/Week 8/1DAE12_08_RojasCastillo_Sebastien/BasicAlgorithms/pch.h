// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
const int ARRLENGTH_NR1{ 10 };
const int ARRLENGTH_NR2{ 14 };


int Count(int arr[], int arrSize, int nr);



void TestCount();


int arrNr1[ARRLENGTH_NR1]{7,-3,9,-8,0,7,1,9,8};
int arrNr2[ARRLENGTH_NR2]{-4,-1,2,0,-3, 0,2,4,2,0, 0,-5,-1,-1};



#endif //PCH_H
