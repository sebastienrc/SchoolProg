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
	ClearBackground(0.5f,0.5f,0.5f);

	// Put your own draw statements here
	DrawExplosion();

}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateExplosion();

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
	/*Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };*/
	
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		//std::cout << "Left mouse button released\n";
		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		if (	(mousePos.x >= g_BombPos.x		&&		mousePos.x <= (g_BombPos.x + BOMBSIZE))
												&&
				(mousePos.y >= g_BombPos.y		&&		mousePos.y <= (g_BombPos.y + BOMBSIZE))	){
			ProcessMouseClick();
		}
		break;
	}
	case SDL_BUTTON_RIGHT:
		//std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		//std::cout << "Middle mouse button released\n";
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
	
void ProcessMouseClick() {
	g_BombColor.a = 0.5f;
	g_RunAnimation = true;
}

void UpdateExplosion() {

	if (g_RunAnimation == true && g_CountFrames <= ANIMATION_MAX_FRAMES) {

		g_TopLeftBombResiduePos.x -= DELTA_POSITION;
		g_TopLeftBombResiduePos.y += DELTA_POSITION;

		g_TopRightBombResiduePos.x += DELTA_POSITION;
		g_TopRightBombResiduePos.y += DELTA_POSITION;

		g_BodomLeftBombResiduePos.x -= DELTA_POSITION;
		g_BodomLeftBombResiduePos.y -= DELTA_POSITION;

		g_BodomRightBombResiduePos.x += DELTA_POSITION;
		g_BodomRightBombResiduePos.y -= DELTA_POSITION;

		g_CountFrames++;
	}
	else{
		g_BombColor.a = 1.f;
		g_CountFrames = 0;
		g_RunAnimation = false;

		g_TopLeftBombResiduePos.x = g_BombPos.x;
		g_TopLeftBombResiduePos.y = g_BombPos.y	;

		g_TopRightBombResiduePos.x = g_BombPos.x;
		g_TopRightBombResiduePos.y = g_BombPos.y;

		g_BodomLeftBombResiduePos.x = g_BombPos.x;
		g_BodomLeftBombResiduePos.y = g_BombPos.y;

		g_BodomRightBombResiduePos.x = g_BombPos.x;
		g_BodomRightBombResiduePos.y = g_BombPos.y;

	}

}

void DrawExplosion() {

	SetColor(g_BombColor);
	FillRect(g_BombPos, BOMBSIZE, BOMBSIZE);

	if (g_RunAnimation == true) {

		SetColor(g_BombResidueColor);
		FillRect(g_TopLeftBombResiduePos	, BOMBSIZE	, BOMBSIZE);
		FillRect(g_TopRightBombResiduePos	, BOMBSIZE	, BOMBSIZE);
		FillRect(g_BodomLeftBombResiduePos	, BOMBSIZE	, BOMBSIZE);
		FillRect(g_BodomRightBombResiduePos	, BOMBSIZE	, BOMBSIZE);
	}
	


}
#pragma endregion ownDefinitions