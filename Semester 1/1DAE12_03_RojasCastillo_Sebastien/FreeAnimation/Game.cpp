#include "pch.h"
#include "Game.h"
#include <math.h>
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
	DrawExtSquare();
	DrawSecondSquare();
	DrawThirdSquare();
	DrawFourthSquare();
	DrawMiddleSquare();

	// Put your own draw statements here

}

void Update(float elapsedSec)
{

	UpdateExtSquare();
	UpdateSecondSquare();
	UpdateThirdSquare();
	UpdateFourthSquare();
	UpdateMiddleSquare();


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

void DrawExtSquare() {
	float squareStart_X{g_SquareStart_X};
	float squareStart_Y{g_SquareStart_Y};
	
	float squareLength{ SQUAREWIDTH };				// Full Size
	
	float degrees45{ g_Degrees45 };
	float degrees135{ g_Degrees135 };
	float degrees225{ g_Degrees225 };
	float degrees315{ g_Degrees315 };


	SetColor(1, 1, 1);

	//											X													Y

	DrawLine(	squareStart_X + (squareLength * cosf(g_AngleExt + degrees45))	,	squareStart_Y + (squareLength * sinf(g_AngleExt + degrees45)),
				squareStart_X + (squareLength * cosf(g_AngleExt + degrees135))	,	squareStart_Y + (squareLength * sinf(g_AngleExt + degrees135))	);

	DrawLine(	squareStart_X + (squareLength * cosf(g_AngleExt + degrees135))	,	squareStart_Y + (squareLength * sinf(g_AngleExt + degrees135)),
				squareStart_X + (squareLength * cosf(g_AngleExt + degrees225))	,	squareStart_Y + (squareLength * sinf(g_AngleExt + degrees225)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_AngleExt + degrees225))	,	squareStart_Y + (squareLength * sinf(g_AngleExt + degrees225)),
				squareStart_X + (squareLength * cosf(g_AngleExt + degrees315))	,	squareStart_Y + (squareLength * sinf(g_AngleExt + degrees315)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_AngleExt + degrees315))	,	squareStart_Y + (squareLength * sinf(g_AngleExt + degrees315)),
				squareStart_X + (squareLength * cosf(g_AngleExt + degrees45))	,	squareStart_Y + (squareLength * sinf(g_AngleExt + degrees45)));


}

void DrawSecondSquare(){
	float squareStart_X{ g_SquareStart_X };
	float squareStart_Y{ g_SquareStart_Y };

	float squareLength{ (SQUAREWIDTH * 8) / 11 };			

	float degrees45{ g_Degrees45 };
	float degrees135{ g_Degrees135 };
	float degrees225{ g_Degrees225 };
	float degrees315{ g_Degrees315 };


	SetColor(1, 1, 1);

	//											X																	Y

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle2nd + degrees45))	,	squareStart_Y + (squareLength * sinf(g_Angle2nd + degrees45)),
				squareStart_X + (squareLength * cosf(g_Angle2nd + degrees135))	,	squareStart_Y + (squareLength * sinf(g_Angle2nd + degrees135)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle2nd + degrees135))	,	squareStart_Y + (squareLength * sinf(g_Angle2nd + degrees135)),
				squareStart_X + (squareLength * cosf(g_Angle2nd + degrees225))	,	squareStart_Y + (squareLength * sinf(g_Angle2nd + degrees225)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle2nd + degrees225))	,	squareStart_Y + (squareLength * sinf(g_Angle2nd + degrees225)),
				squareStart_X + (squareLength * cosf(g_Angle2nd + degrees315))	,	squareStart_Y + (squareLength * sinf(g_Angle2nd + degrees315)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle2nd + degrees315))	,	squareStart_Y + (squareLength * sinf(g_Angle2nd + degrees315)),
				squareStart_X + (squareLength * cosf(g_Angle2nd + degrees45))	,	squareStart_Y + (squareLength * sinf(g_Angle2nd + degrees45)));

}

void DrawThirdSquare() {
	float squareStart_X{ g_SquareStart_X };
	float squareStart_Y{ g_SquareStart_Y };

	float squareLength{ (SQUAREWIDTH * 6) / 11 };		

	float degrees45{ g_Degrees45 };
	float degrees135{ g_Degrees135 };
	float degrees225{ g_Degrees225 };
	float degrees315{ g_Degrees315 };


	SetColor(1, 1, 1);

	//											X													Y

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle3rd + degrees45))	,	squareStart_Y + (squareLength * sinf(g_Angle3rd + degrees45)),
				squareStart_X + (squareLength * cosf(g_Angle3rd + degrees135))	,	squareStart_Y + (squareLength * sinf(g_Angle3rd + degrees135)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle3rd + degrees135))	,	squareStart_Y + (squareLength * sinf(g_Angle3rd + degrees135)),
				squareStart_X + (squareLength * cosf(g_Angle3rd + degrees225))	,	squareStart_Y + (squareLength * sinf(g_Angle3rd + degrees225)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle3rd + degrees225))	,	squareStart_Y + (squareLength * sinf(g_Angle3rd + degrees225)),
				squareStart_X + (squareLength * cosf(g_Angle3rd + degrees315))	,	squareStart_Y + (squareLength * sinf(g_Angle3rd + degrees315)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle3rd + degrees315))	,	squareStart_Y + (squareLength * sinf(g_Angle3rd + degrees315)),
				squareStart_X + (squareLength * cosf(g_Angle3rd + degrees45))	,	squareStart_Y + (squareLength * sinf(g_Angle3rd + degrees45)));


}

void DrawFourthSquare() {
	
	float squareLength{ (SQUAREWIDTH * 4) / 11 };
	
	float squareStart_X{ g_WindowWidth / 2 };
	float squareStart_Y{ g_WindowHeight / 2 };

	float degrees45{g_Degrees45};
	float degrees135{g_Degrees135};
	float degrees225{g_Degrees225};
	float degrees315{g_Degrees315};


	DrawRect(squareStart_X, squareStart_Y, 1, 1);
	
	SetColor(1, 1, 1);

	//											X													Y

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle4th + degrees45))	,	squareStart_Y + (squareLength * sinf(g_Angle4th + degrees45)),
				squareStart_X + (squareLength * cosf(g_Angle4th + degrees135))	,	squareStart_Y + (squareLength * sinf(g_Angle4th + degrees135))	);

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle4th + degrees135))	,	squareStart_Y + (squareLength * sinf(g_Angle4th + degrees135)),
				squareStart_X + (squareLength * cosf(g_Angle4th + degrees225))	,	squareStart_Y + (squareLength * sinf(g_Angle4th + degrees225)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle4th + degrees225))	,	squareStart_Y + (squareLength * sinf(g_Angle4th + degrees225)),
				squareStart_X + (squareLength * cosf(g_Angle4th + degrees315))	,	squareStart_Y + (squareLength * sinf(g_Angle4th + degrees315)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_Angle4th + degrees315))	,	squareStart_Y + (squareLength * sinf(g_Angle4th + degrees315)),
				squareStart_X + (squareLength * cosf(g_Angle4th + degrees45))	,	squareStart_Y + (squareLength * sinf(g_Angle4th + degrees45)));




}

void DrawMiddleSquare() {
	float squareStart_X{ g_SquareStart_X };
	float squareStart_Y{ g_SquareStart_Y };

	float squareLength{ (SQUAREWIDTH * 2) / 11 };

	float degrees45{ g_Degrees45 };
	float degrees135{ g_Degrees135 };
	float degrees225{ g_Degrees225 };
	float degrees315{ g_Degrees315 };


	SetColor(1, 1, 1);

	//											X													Y

	DrawLine(	squareStart_X + (squareLength * cosf(g_AngleMid + degrees45))	,	squareStart_Y + (squareLength * sinf(g_AngleMid + degrees45)),
				squareStart_X + (squareLength * cosf(g_AngleMid + degrees135))	,	squareStart_Y + (squareLength * sinf(g_AngleMid + degrees135)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_AngleMid + degrees135))	,	squareStart_Y + (squareLength * sinf(g_AngleMid + degrees135)),
				squareStart_X + (squareLength * cosf(g_AngleMid + degrees225))	,	squareStart_Y + (squareLength * sinf(g_AngleMid + degrees225)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_AngleMid + degrees225))	,	squareStart_Y + (squareLength * sinf(g_AngleMid + degrees225)),
				squareStart_X + (squareLength * cosf(g_AngleMid + degrees315))	,	squareStart_Y + (squareLength * sinf(g_AngleMid + degrees315)));

	DrawLine(	squareStart_X + (squareLength * cosf(g_AngleMid + degrees315))	,	squareStart_Y + (squareLength * sinf(g_AngleMid + degrees315)),
				squareStart_X + (squareLength * cosf(g_AngleMid + degrees45))	,	squareStart_Y + (squareLength * sinf(g_AngleMid + degrees45)));

}


void UpdateExtSquare() {
	g_AngleExt += float(2 * M_PI) / (g_RotationSpeed * 5);
	

}

void UpdateSecondSquare() {

	g_Angle2nd += float(2 * M_PI) / (g_RotationSpeed * 4);

}

void UpdateThirdSquare() {

	g_Angle3rd += float(2 * M_PI) / (g_RotationSpeed * 3);

}
void UpdateFourthSquare() {
	g_Angle4th += float(2 * M_PI) / (g_RotationSpeed * 2);


}
void UpdateMiddleSquare() {
	g_AngleMid += float(2 * M_PI) / g_RotationSpeed;


}


#pragma endregion ownDefinitions