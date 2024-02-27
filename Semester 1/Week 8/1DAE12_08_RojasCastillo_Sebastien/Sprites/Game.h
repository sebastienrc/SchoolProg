#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Sprites - Rojas Castillo, Sebastien- 1DAE12" };

// Change the window dimensions here
float g_WindowWidth{ 1000 };
float g_WindowHeight{ 1000 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Sprite g_KnightSprite{};
Sprite g_TiboSprite{};

int g_KnightPosition{};
int g_KnightSpeed{2};

int g_TiboPosition{};

// Declare your own functions here

void InitKnight();
void DrawKnight();
void UpdateKnight(float elapsedSec);


void InitTibo();
void DrawTibo();
void UpdateTibo(float elapsedSec);

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
