#include "pch.h"
#include "Game.h"

// 1DAE12 - Rojas Castillo - Sebastien
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0,0,0.5f);
	DrawVerticalLines();
	DrawHorizontalLines();
	DrawConnectingLines();
	//                                                                                                                                    DrawConnectingLines();

	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	g_LinesHorizontal = g_LinesHorizontal++ %int(g_WindowHeight);
	g_LinesVertical = g_LinesVertical++ % int(g_WindowWidth);



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

void DrawHorizontalLines() {
	float posX1{0};
	float posX2{g_WindowWidth};
	float posY{g_WindowHeight};
	
	SetColor(1, 1, 1);
	DrawLine(posX1, posY - float(g_LinesHorizontal), posX2, posY - float(g_LinesHorizontal));
	DrawLine(posX1, float(g_LinesHorizontal), posX2, float(g_LinesHorizontal));
	
}

void DrawVerticalLines() {
	float posY1{ 0 };
	float posY2{ g_WindowHeight };
	float posX{g_WindowWidth};


	SetColor(1, 1, 1);
	DrawLine(posX - float(g_LinesVertical), posY1, posX - float(g_LinesVertical), posY2);
	DrawLine(float(g_LinesVertical), posY1, float(g_LinesVertical), posY2);
	
}

void DrawConnectingLines() {
	float posY0{ 0 };
	float posX0{0};
	
	SetColor(1, 1, 0);
	DrawLine(float(g_LinesVertical), posY0,g_WindowWidth, float(g_LinesHorizontal));
	DrawLine(g_WindowWidth, float(g_LinesHorizontal), g_WindowWidth - float(g_LinesVertical), g_WindowHeight);
	DrawLine(g_WindowWidth - float(g_LinesVertical), g_WindowHeight,posX0,g_WindowHeight-float(g_LinesHorizontal));
	DrawLine(posX0, g_WindowHeight-float(g_LinesHorizontal),float(g_LinesVertical), posY0);



}
#pragma endregion ownDefinitions