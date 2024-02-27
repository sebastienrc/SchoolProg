// Applications.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
// Rojas Castillo, Sébastien - 1DAE12

#include "pch.h"
#include <iostream>

int main()
{
    const float pi{ 3.14159265359 };
    const float g{9.8};

    float rgbValueR{};
    float rgbValueG{};
    float rgbValueB{};
    float rgbValueA{};

    int distanceInKm{};
    float angleInRadians{};
    float angleInDegrees{};
    int secondsSingelRotation{};

    float speedInKm{};
    int elapsedTimeInMinutes{};

    int secondsFreeFall{};
    int radiusCircle{};
    int rectangleWidth{};
    int rectangleHeight{};
    int triangleBase{};
    int triangleHeight;

    std::cout << "RGBA in [0, 255]?";
    std::cin >> rgbValueR >> rgbValueG >> rgbValueB >> rgbValueA;
    std::cout << "RGBA in [0.0f, 1.0f]: \n" << rgbValueR / 255 << std::endl << rgbValueG / 255 << std::endl << rgbValueB / 255 << std::endl << rgbValueA / 255 << std::endl;

    std::cout << "Distance in km?";
    std::cin >> distanceInKm;
    std::cout << distanceInKm * 1000 << " meters, "<< distanceInKm * 100000 << "cm"<<std::endl;

    std::cout << "Angle in radians ?";
    std::cin >> angleInRadians;
    std::cout << (angleInRadians / pi) * 180 << " degrees \n";
    
    std::cout << "Angle in degrees?";
    std::cin >>  angleInDegrees;
    std::cout << (angleInDegrees / 180) * pi << " radians \n";
    
    std::cout << "Seconds of one rotation?";
    std::cin >> secondsSingelRotation;
    std::cout << 360 / secondsSingelRotation << " degrees/second \n";

    std::cout << "Speed(km/h)? ";
    std::cin >> speedInKm;
    std::cout << "Elapsed time (minutes)? ";
    std::cin >> elapsedTimeInMinutes;
    std::cout << (speedInKm / 60) * elapsedTimeInMinutes * 1000 << " meters \n";
    
    std::cout << "Seconds? ";
    std::cin >> secondsFreeFall;
    std::cout << "Velocity " << secondsFreeFall * g << " m/sec \n";

    std::cout << "Radius of circle? ";
    std::cin >> radiusCircle;
    std::cout << "Circumference: " << radiusCircle * 2 * pi << std::endl << "Area: " << radiusCircle * radiusCircle * pi<<std::endl;

    std::cout << "Width and height? ";
    std::cin >> rectangleWidth >> rectangleHeight;
    std::cout << "Circumference: " << (rectangleWidth * 2) + (rectangleHeight * 2) << std::endl << "Area: " << rectangleWidth * rectangleHeight<<std::endl;
    
    std::cout << "Base and height? ";
    std::cin >> triangleBase >> triangleHeight;
    std::cout << "Area: " << (triangleBase * triangleHeight) / 2;



}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
