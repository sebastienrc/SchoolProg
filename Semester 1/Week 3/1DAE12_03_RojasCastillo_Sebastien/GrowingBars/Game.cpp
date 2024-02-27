#include "pch.h"
#include "Game.h"
#include <iostream>

// 1DAE12 - Rojas Castillo, Sebastien

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0,0,0);
	DrawYellowBar();
	DrawRedBar();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_NrFrames++;
	std::cout <<g_NrFrames << std::endl;
	g_YellowBarFilling = g_YellowBarFilling++ % int(g_BarWidth+1);
	
	g_RedBarFilling = (g_RedBarFilling + (15 * (g_NrFrames % 31 / 30) ))% int(g_BarWidth+1);
	g_RedColorSaturation = (g_RedColorSaturation + (45 * (g_NrFrames % 31 / 30)))%2551 + (1200 * (g_NrFrames % 961 / 960));





	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void DrawYellowBar() {
	float barHeight{ (g_WindowHeight / 3) - 40 };
	float posX{20};
	float posY{g_WindowHeight-barHeight-20};

	SetColor(1, 1, 0);
	FillRect(posX, posY, float(g_YellowBarFilling), barHeight);
	
	SetColor(1, 1, 1);
	DrawRect(posX, posY, g_BarWidth, barHeight,2.f);



}


void DrawRedBar() {;
	float barHeight{ (g_WindowHeight / 3) - 40 };
	float posX{20};
	float posY{20};

	SetColor(float(g_RedColorSaturation)/2550.f, 0, 0);
	//SetColor(1, 0, 0);
	FillRect(posX, posY, float(g_RedBarFilling), barHeight);

	SetColor(1, 1, 1);
	DrawRect(posX, posY, g_BarWidth, barHeight,2.f);

}
#pragma endregion ownDefinitions