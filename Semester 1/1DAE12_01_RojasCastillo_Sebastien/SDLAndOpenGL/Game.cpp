#include "pch.h"
#include "Game.h"

// Rojas Castillo, Sébastien - 1DAE12

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	
}

void Draw()
{
	float firstVerticalLine{ ((g_WindowWidth - 1.0f) / 3) };
	float secondVerticalLine{ ((g_WindowWidth - 1.0f) / 3) * 2 };
	float firstHorizontalLine{ ((g_WindowHeight - 1.0f) / 3) };
	float secondHorizontalLine{ ((g_WindowHeight - 1.0f) / 3) * 2 };
	/*RGB VALUES : WHITE(255, 255, 255)	RED(255, 0, 0)
					GREEN(0,128,0)		BLUE(0,0,255)
					GRAY(128,128,128) */
	ClearBackground();
	/* SetColor(0.0f, 0.0f, 255.0f);
	FillRect(1.0f, 1.0f, g_WindowWidth, g_WindowHeight);*/
	SetColor(0.0f, 255.0f, 0.0f);
	DrawRect(1.0f, 1.0f, (g_WindowWidth-1.0f), (g_WindowHeight-1.0f));
	SetColor(255.0f, 255.0f, 255.0f);
	DrawLine(0.0f, firstHorizontalLine, g_WindowWidth, firstHorizontalLine);
	DrawLine(0.0f, secondHorizontalLine, g_WindowWidth, secondHorizontalLine, 0.0f);
	DrawLine(firstVerticalLine, 0.0f, firstVerticalLine, g_WindowHeight);
	DrawLine(secondVerticalLine, 0.0f, secondVerticalLine, g_WindowHeight);
	SetColor(255.0f, 0.0f, 0.0f);
	DrawLine(0.0f, 0.0f, g_WindowWidth, g_WindowHeight);
	DrawLine(0.0f, g_WindowHeight, g_WindowWidth, 0.0f);
	SetColor(0.0f, 0.0f, 255.0f);
	FillRect(((g_WindowWidth-2) / 2), ((g_WindowHeight-2) / 2),4.0f,4.0f);

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

#pragma endregion ownDefinitions