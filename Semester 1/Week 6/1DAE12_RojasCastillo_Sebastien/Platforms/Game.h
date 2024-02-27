#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Platform - Rojas Castillo, Sebastien - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 1000 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const float		PLATFORM_WIDTH{	100.0f	};
const float		PLATFORM_HEIGHT{	20.0f	};
const Color4f	PLATFORM_COLOR{ 0.f,0.f,1.f,1.f };

const float		POINT_RADIUS{ 10.0f };
const Color4f	POINT_COLOR{ 1.f,0.f,0.f,1.f };	

const int FULLMOVEMENT_FRAMES{ 100 };
const float STARTPOSITION_Y	{ g_WindowHeight / 2 };
const float STARTPOSITION_X	{ g_WindowWidth / 2};
const int MAX_MOVEMENT		{};

float g_LocationX	{	STARTPOSITION_X };
float g_LocationY	{	STARTPOSITION_Y};
int g_CountFrames	{};

// Declare your own functions here

void DrawPlatform(float x, float y);
void DrawPoint(float x, float y);

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
