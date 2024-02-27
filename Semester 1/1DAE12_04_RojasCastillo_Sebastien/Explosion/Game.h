#pragma once
using namespace utils;
#include <iostream>
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - Rojas Castillo, Sebastien - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

//Constants

const float BOMBSIZE				{ g_WindowWidth / 5 };
const float DELTA_POSITION			{ 10.f };
const int ANIMATION_MAX_FRAMES		{ 150 };

	//Center Bomb

Color4f g_BombColor					{ 0.f, 0.f, 0.f, 1.f};
const Point2f g_BombPos				{ (g_WindowWidth - BOMBSIZE) / 2	,	(g_WindowHeight - BOMBSIZE) / 2 };

	//Residue Bomb (Red Squares)

const Color4f g_BombResidueColor	{ 1.f,0.f,0.f,1.f };

Point2f g_TopLeftBombResiduePos		{ (g_WindowWidth - BOMBSIZE) / 2	,	(g_WindowHeight - BOMBSIZE) / 2 };
Point2f g_TopRightBombResiduePos	{ (g_WindowWidth - BOMBSIZE) / 2	,	(g_WindowHeight - BOMBSIZE) / 2 };
Point2f g_BodomLeftBombResiduePos	{ (g_WindowWidth - BOMBSIZE) / 2	,	(g_WindowHeight - BOMBSIZE) / 2 };
Point2f g_BodomRightBombResiduePos	{ (g_WindowWidth - BOMBSIZE) / 2	,	(g_WindowHeight - BOMBSIZE) / 2 };


	//Animation Data

bool	g_RunAnimation				{ false };
int		g_CountFrames				{0};

// Declare your own functions here

void ProcessMouseClick();
void UpdateExplosion();
void DrawExplosion();

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
