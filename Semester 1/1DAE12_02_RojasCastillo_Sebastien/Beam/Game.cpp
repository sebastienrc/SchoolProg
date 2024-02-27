#include "pch.h"
#include "Game.h"

//  Rojas Castillo, S�bastien - 1DAE12
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0,0,0);
	DrawBeam();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 

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

void DrawBeam() {
	float squareSize{ 200 };
	float border{ 10 };

	SetColor(0, 0.8f, 0, 0.6f); //green transparent
	FillRect(border, border, squareSize, squareSize);
	FillRect(g_WindowWidth - border - squareSize, g_WindowHeight - border - squareSize, squareSize, squareSize);


	SetColor(1, 1, 1); //white
	DrawRect(border, border, squareSize, squareSize);
	DrawRect(g_WindowWidth - border - squareSize, g_WindowHeight - border - squareSize, squareSize, squareSize);
	
	DrawLine(border, border, g_WindowWidth - border - squareSize, g_WindowHeight - border - squareSize);
	DrawLine(border+squareSize, border+squareSize, g_WindowWidth - border, g_WindowHeight - border);
	DrawLine(border, border + squareSize, g_WindowWidth - border - squareSize, g_WindowHeight - border);
	DrawLine(border + squareSize, border, g_WindowWidth - border, g_WindowHeight - border - squareSize);

}

#pragma endregion ownDefinitions