#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ClockPointers - Rojas Castillo, Sebastien- 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

//float g_FrameCounter;


const float LARGEPOINTERLENGTH{150};
const float SMALLPOINTERLENGTH{LARGEPOINTERLENGTH/2};
const float LARGEPOINTERPERIOD{ 240 };
const float SMALLPOINTERPERIOD{LARGEPOINTERPERIOD * 12 };

float g_AngleLarge{};
float g_AngleSmall{};
float g_ClockWidth{0.2f};


float g_ClockBegin_X{ g_WindowWidth / 2 };
float g_ClockBegin_Y{ g_WindowHeight / 2 };

float g_LargeClockTip_X{g_ClockBegin_X + (LARGEPOINTERLENGTH * cosf(g_AngleLarge))};
float g_LargeClockTip_Y{g_ClockBegin_Y + (LARGEPOINTERLENGTH * sinf(g_AngleLarge))};

float g_SmallClockTip_X{ g_ClockBegin_X + (SMALLPOINTERLENGTH * cosf(g_AngleSmall)) };
float g_SmallClockTip_Y{ g_ClockBegin_Y + (SMALLPOINTERLENGTH * sinf(g_AngleSmall)) };

void DrawLargePointer();
void DrawSmallPointer();
void UpdateLargePointer();
void UpdateSmallPointer();



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
