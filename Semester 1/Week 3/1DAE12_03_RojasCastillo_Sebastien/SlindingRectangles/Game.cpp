#include "pch.h"
#include "Game.h"


// 1DAE - Rojas Castillo , Sebastien
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawGreenRect();
	DrawBlueRect();
	DrawRedRect();
	DrawYellowRect();

	// Put your own draw statements here

}

void Update(float elapsedSec)
{

	g_SquareCounter = g_SquareCounter++ % int(g_WindowWidth - g_SquareSize);

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

void DrawGreenRect() {
	float posX{0};
	float posY{g_WindowHeight - g_SquareSize};
	float squarePos{ float(g_SquareCounter) };

	SetColor(0, 1, 0,0.5f);
	FillRect(posX + squarePos, posY- squarePos, g_SquareSize, g_SquareSize);

	SetColor(0, 0, 0);
	DrawRect(posX + squarePos, posY- squarePos, g_SquareSize, g_SquareSize);

}

void DrawBlueRect() {
	float posX{g_WindowWidth - g_SquareSize};
	float posY{g_WindowHeight - g_SquareSize};
	float squarePos{float(g_SquareCounter)};

	SetColor(0, 0, 1,0.5f);
	FillRect(posX - squarePos, posY - squarePos, g_SquareSize, g_SquareSize);
	
	SetColor(0, 0, 0);
	DrawRect(posX - squarePos, posY - squarePos, g_SquareSize, g_SquareSize);


}

void DrawRedRect() {
	float posX{0};
	float posY{0};
	float squarePos{ float(g_SquareCounter) };

	SetColor(1, 0, 0,0.5f);
	FillRect(posX + squarePos, posY + squarePos, g_SquareSize, g_SquareSize);
	
	SetColor(0, 0, 0);
	DrawRect(posX + squarePos, posY + squarePos, g_SquareSize, g_SquareSize);
}

void DrawYellowRect() {
	float posX{g_WindowWidth - g_SquareSize};
	float posY{0};
	float squarePos{ float(g_SquareCounter) };

	SetColor(1, 1, 0,0.5f);
	FillRect(posX - squarePos, posY + squarePos, g_SquareSize, g_SquareSize);
	
	SetColor(0, 0, 0);
	DrawRect(posX - squarePos, posY + squarePos, g_SquareSize, g_SquareSize);
}

#pragma endregion ownDefinitions