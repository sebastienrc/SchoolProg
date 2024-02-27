#include "pch.h"
#include "Game.h"
#include "MyFunctions.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawPlatform(g_LocationX, g_LocationY);
	DrawPoint(		g_LocationX, g_LocationY);


}

void Update(float elapsedSec)
{
	// process input, do physics 

	++g_CountFrames;
	g_LocationY = STARTPOSITION_Y + float( WaveMovement(g_CountFrames, FULLMOVEMENT_FRAMES) * MAX_MOVEMENT);



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

void DrawPlatform(float x, float y) {

	float xValue{x-(PLATFORM_WIDTH/2)};
	float yValue{y-(PLATFORM_HEIGHT/2)};
	
	SetColor(PLATFORM_COLOR);
	FillRect(	xValue, yValue,
				PLATFORM_WIDTH, PLATFORM_HEIGHT);

}

void DrawPoint(float x, float y) {

	SetColor(POINT_COLOR);
	FillEllipse(x, y, POINT_RADIUS, POINT_RADIUS);

}



#pragma endregion ownDefinitions