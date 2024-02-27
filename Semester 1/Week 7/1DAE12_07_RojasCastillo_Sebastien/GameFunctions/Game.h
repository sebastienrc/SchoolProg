#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Game Functions - Rojas Castillo, Sebastien- 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 800 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

Point2f g_CircleCenter{ 400.f,400.f };
Circlef g_Circle1{g_CircleCenter,200.f};
Color4f g_Color_Base(1.f, 1.f, 1.f, 1.f);
Color4f g_Color_Update(1.f, 0.f, 0.f, 1.f);

Rectf g_Rect1(100.f, 100.f, 300.f, 200.f);

bool g_CircleBorder{};
bool g_RectBorder{};





// Declare your own functions here

void DrawCircle();
void TestRect();


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
