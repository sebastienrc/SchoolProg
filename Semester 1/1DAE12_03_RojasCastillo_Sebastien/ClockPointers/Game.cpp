#include "pch.h"
#include "Game.h"
#include <iostream>
#include <math.h>

// 1DAE12 - Rojas Castillo, Sebastien

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	
	//	std::cout << g_FrameCounter << std::endl;
	
	DrawLargePointer();
	DrawSmallPointer();
		
	
	
		
		// Put your own draw statements here

}

void Update(float elapsedSec)
{
		
	//	g_FrameCounter++;
	
	
	g_AngleLarge += float(2 * M_PI) / LARGEPOINTERPERIOD;
	g_AngleSmall += float(2 * M_PI) / SMALLPOINTERPERIOD;
	UpdateLargePointer();
	UpdateSmallPointer();
	

	
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

void DrawLargePointer() {
	float clockWidth{g_ClockWidth};
	float upwardsClockPoint_X{ g_ClockBegin_X + ((LARGEPOINTERLENGTH / 3) * cosf(clockWidth + g_AngleLarge)) };
	float upwardsClockPoint_Y{ g_ClockBegin_Y + ((LARGEPOINTERLENGTH / 3) * sinf(clockWidth + g_AngleLarge))};
	float downwardsClockPoint_X{ g_ClockBegin_X + ((LARGEPOINTERLENGTH / 3) * cosf(g_AngleLarge - clockWidth)) };
	float downwardsClockPoint_Y{ g_ClockBegin_Y + ((LARGEPOINTERLENGTH / 3) * sinf(g_AngleLarge - clockWidth)) };

	SetColor(1, 1, 1);
	
	DrawLine(g_ClockBegin_X, g_ClockBegin_Y, upwardsClockPoint_X, upwardsClockPoint_Y);
	DrawLine(upwardsClockPoint_X, upwardsClockPoint_Y, g_LargeClockTip_X, g_LargeClockTip_Y);
	
	DrawLine(g_ClockBegin_X, g_ClockBegin_Y, downwardsClockPoint_X, downwardsClockPoint_Y);
	DrawLine(downwardsClockPoint_X, downwardsClockPoint_Y, g_LargeClockTip_X, g_LargeClockTip_Y);

}

void DrawSmallPointer() {
	float clockWidth{g_ClockWidth};
	float upwardsClockPoint_X{ g_ClockBegin_X + ((SMALLPOINTERLENGTH / 3) * cosf(clockWidth + g_AngleSmall)) };
	float upwardsClockPoint_Y{ g_ClockBegin_Y + ((SMALLPOINTERLENGTH / 3) * sinf(clockWidth + g_AngleSmall)) };
	float downwardsClockPoint_X{ g_ClockBegin_X + ((SMALLPOINTERLENGTH / 3) * cosf(g_AngleSmall - clockWidth)) };
	float downwardsClockPoint_Y{ g_ClockBegin_Y + ((SMALLPOINTERLENGTH / 3) * sinf(g_AngleSmall - clockWidth)) };

	SetColor(1, 0, 0);

	DrawLine(g_ClockBegin_X, g_ClockBegin_Y, upwardsClockPoint_X, upwardsClockPoint_Y);
	DrawLine(upwardsClockPoint_X, upwardsClockPoint_Y, g_SmallClockTip_X, g_SmallClockTip_Y);

	DrawLine(g_ClockBegin_X, g_ClockBegin_Y, downwardsClockPoint_X, downwardsClockPoint_Y);
	DrawLine(downwardsClockPoint_X, downwardsClockPoint_Y, g_SmallClockTip_X, g_SmallClockTip_Y);
}

void UpdateLargePointer() {
	g_LargeClockTip_X = g_ClockBegin_X + (LARGEPOINTERLENGTH * cosf(g_AngleLarge));
	g_LargeClockTip_Y = g_ClockBegin_Y + (LARGEPOINTERLENGTH * sinf(g_AngleLarge));
}

void UpdateSmallPointer() {
	g_SmallClockTip_X = g_ClockBegin_X + (SMALLPOINTERLENGTH * cosf(g_AngleSmall));
	g_SmallClockTip_Y = g_ClockBegin_Y + (SMALLPOINTERLENGTH * sinf(g_AngleSmall));
}
#pragma endregion ownDefinitions