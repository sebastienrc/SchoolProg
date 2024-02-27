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
	ClearBackground(0.f,0.f,0.f);
	// Put your own draw statements here

	DrawCircle();
	TestRect();
}

void Update(float elapsedSec)
{


	// process input, do physics 
	//DrawCircleBorder();
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
	std::cout << "  [" << e.x << ", " << e.y << "]\n";
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };

	if (IsPointInCircle(mousePos, g_Circle1))
		g_CircleBorder = true;
	else
		g_CircleBorder = false;

	if (IsPointInRect(mousePos, g_Rect1))
		g_RectBorder = true;
	else
		g_RectBorder = false;

		
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

void DrawCircle() {
	
	SetColor(g_Color_Base);
	FillEllipse(g_CircleCenter, 200.f, 200.f);
	if (g_CircleBorder) {

		SetColor(g_Color_Update);
		DrawEllipse(g_CircleCenter, g_Circle1.radius, g_Circle1.radius, 5.f);
		std::cout << "Point is in circle" << std::endl;

	}

	else {

		SetColor(g_Color_Base);
		DrawEllipse(g_CircleCenter, g_Circle1.radius, g_Circle1.radius, 5.f);

	}

}

void TestRect() {

	SetColor(g_Color_Base);
	FillRect(g_Rect1);

	if (g_RectBorder) {
		SetColor(g_Color_Update);
		DrawRect(g_Rect1,5.f);
	}
	else {
		SetColor(g_Color_Base);
		DrawRect(g_Rect1,5.f);
	}

}



#pragma endregion ownDefinitions