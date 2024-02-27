#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Shuffle Cards - Rojas Castillo, Sebastien - 1DAE12" };

// Change the window dimensions here
const int CARD_WIDTH{ 140 };
const int CARD_HEIGHT{ 190 };


const int NR_SUITS{ 4 };
const int NR_CARDS_PER_SUIT{ 13 };

float g_WindowWidth{ CARD_WIDTH * NR_CARDS_PER_SUIT };
float g_WindowHeight{ CARD_HEIGHT * NR_SUITS };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here


Texture g_CardsTexturesArr[NR_CARDS_PER_SUIT * NR_SUITS]{};




// Declare your own functions here


void ShuffleCard();
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
