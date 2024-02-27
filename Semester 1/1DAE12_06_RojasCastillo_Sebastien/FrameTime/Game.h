#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FrameTime - Rojas Castillo, Sebastien - 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 1500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

const float		PLATFORM_WIDTH		{ 100.0f };
const float		PLATFORM_HEIGHT		{ 20.0f };
const Color4f	PLATFORM_COLOR		{ 0.f,0.f,1.f,1.f };

const float		POINT_RADIUS		{ 10.0f };
const Color4f	POINT_COLOR			{ 1.f,0.f,0.f,1.f };

const float		STARTPOSITION_Y		{ g_WindowHeight * 2 / 3};
const float		STARTPOSITION_X		{0};

const float ACCELERATION			{ -9.81f };
const int	SPEED_SCALE				{50};
const float BOUNCINESS				{0.8f};	//number between 0 and 1
const float BOUNCE_LOCATION_Y		{POINT_RADIUS };

float g_SpeedGravity				{ 0 };
float g_LocationY					{STARTPOSITION_Y};

float g_LocationX					{STARTPOSITION_X};
float SPEED_X						{100};									//pixels per seconds


int g_CountFrames{};

// Declare your own functions here

void DrawPlatform(float x, float y);
void DrawPoint(float x, float y);

// Declare your own functions here

void DrawPlatform	(float x, float y);
void DrawPoint		(float x, float y);

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
