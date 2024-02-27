#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	DrawPoint(g_LocationX, g_LocationY);
	DrawLine(0, STARTPOSITION_Y, g_WindowWidth, STARTPOSITION_Y);

	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// y-coordinate stuff

	g_SpeedGravity += ACCELERATION * elapsedSec * SPEED_SCALE;
	g_LocationY += g_SpeedGravity * elapsedSec;

	if (g_LocationY < BOUNCE_LOCATION_Y) {
		g_SpeedGravity *= -BOUNCINESS;
		g_LocationY = BOUNCE_LOCATION_Y;
	}
		
	// x-coordinate stuff

	g_LocationX += SPEED_X * elapsedSec;

	if (g_LocationX > g_WindowWidth || g_LocationX < 0) {
		SPEED_X *= -1;

		if (g_LocationX > g_WindowWidth)
			g_LocationX = g_WindowWidth;
		else if (g_LocationX < 0)
			g_LocationX = 0;
		
	}





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

void DrawPlatform(float x, float y) {

	float xValue{ x - (PLATFORM_WIDTH / 2) };
	float yValue{ y - (PLATFORM_HEIGHT / 2) };

	SetColor(PLATFORM_COLOR);
	FillRect(xValue, yValue,
		PLATFORM_WIDTH, PLATFORM_HEIGHT);

}

void DrawPoint(float x, float y) {

	SetColor	(POINT_COLOR);
	FillEllipse	(x, y, POINT_RADIUS, POINT_RADIUS);

}

#pragma endregion ownDefinitions