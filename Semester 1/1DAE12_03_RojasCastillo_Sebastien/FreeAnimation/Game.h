#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FreeAnimation - Rojas Castillo, Sebastien - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const float OUTSIDEBORDER{100};
const float SQUAREWIDTH{sqrtf(float(2 * pow(g_WindowWidth/2,2))) - OUTSIDEBORDER };  // Using Pythagoras Theorem to get width



const float g_Degrees45{ float(M_PI / 4) };
const float g_Degrees135{ float((3 * M_PI) / 4) };
const float g_Degrees225{ float((5 * M_PI) / 4) };
const float g_Degrees315{ float((7 * M_PI) / 4) };


float g_SquareStart_X{g_WindowWidth / 2};
float g_SquareStart_Y{ g_WindowHeight / 2 };


float g_AngleExt{};
float g_Angle2nd{};
float g_Angle3rd{};
float g_Angle4th{};
float g_AngleMid{};

int g_RotationSpeed{ 150 };			//		frames / p

void DrawExtSquare();
void DrawSecondSquare();
void DrawThirdSquare();
void DrawFourthSquare();
void DrawMiddleSquare();

void UpdateExtSquare();
void UpdateSecondSquare();
void UpdateThirdSquare();
void UpdateFourthSquare();
void UpdateMiddleSquare();

// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
