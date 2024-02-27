#include "pch.h"
#include "Game.h"
#include <iostream>

//  Rojas Castillo, Sébastien - 1DAE12

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	ClearBackground(0.2f, 0.0f, 0.2f);
	DrawHouse();
	DrawFlag();
	DrawCheckerPattern();
	DrawColorBand();
	DrawPentagram();
	DrawColumnChart();

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

void DrawHouse() {

	float widthStart{20.f};
	float heightStart{190.f};
	float widthRect{150.f};
	float heightRect{50.f};


	SetColor(1.0f, 0.0f, 0.0f, 0.5f); //red

	FillTriangle(	Point2f{widthStart , heightStart + heightRect}, //left point of triangle
					Point2f{widthStart + widthRect , heightStart + heightRect}, //right point of triangle
					Point2f{ (widthStart + widthRect / 2) , heightStart + (2 * heightRect)}); // height of triangle
	FillRect(widthStart, heightStart, widthRect, heightRect);

	SetColor(1, 1, 1); //white border
	DrawRect(widthStart, heightStart, widthRect, heightRect);
	DrawTriangle(Point2f{ widthStart , heightStart + heightRect },
		Point2f{ widthStart + widthRect , heightStart + heightRect },
		Point2f{ (widthStart + widthRect / 2) , heightStart + (2 * heightRect) });
}

void DrawFlag() {
	float widthStart{20.f};
	float heightStart{100.f};
	float widthRect{50.f};
	float heightRect{70.f};


	SetColor(0, 0, 0); //black
	FillRect(widthStart, heightStart, widthRect,heightRect);
	
	SetColor(1, 1, 0); //yellow
	FillRect(widthStart+widthRect,heightStart,widthRect,heightRect);
	
	SetColor(1, 0, 0); //red
	FillRect(widthStart + (2 * widthRect), heightStart, widthRect, heightRect);
	
	SetColor(1, 1, 1); //white border
	DrawRect(widthStart, heightStart, (3 * widthRect), heightRect);
}

void DrawCheckerPattern() {
	float widthStart{20.f};
	float heightStart{20.f};
	float squareSize{20.f};

	SetColor(0, 0, 0); //black

	FillRect(widthStart, heightStart, squareSize, squareSize); //1
	FillRect(widthStart + (2 * squareSize), heightStart, squareSize, squareSize); //3
	FillRect(widthStart + squareSize, heightStart + squareSize, squareSize, squareSize); //5
	FillRect(widthStart, heightStart + (2 * squareSize), squareSize, squareSize); //7
	FillRect(widthStart + (2 * squareSize), heightStart + (2 * squareSize), squareSize, squareSize); //9

	SetColor(1, 1, 1); //white

	FillRect(widthStart + squareSize, heightStart, squareSize , squareSize); //2
	FillRect(widthStart, heightStart + squareSize, squareSize, squareSize); //4
	FillRect(widthStart + (2 * squareSize), heightStart + squareSize, squareSize, squareSize); //6
	FillRect(widthStart + squareSize, heightStart + (2 * squareSize), squareSize, squareSize); //8

	DrawRect(widthStart, heightStart, squareSize * 3, squareSize * 3);

}

void DrawColorBand() {
	float posX{250};
	float posY{190};
	float widthBand{20};
	float heightBand{ 4 * widthBand };

	SetColor(0, 0, 0);
	FillRect(posX, posY, widthBand, heightBand);
	
	SetColor(1, 0, 0);
	FillRect(posX + widthBand, posY, widthBand, heightBand);

	SetColor(0, 1, 0);
	FillRect(posX + (2 * widthBand), posY, widthBand, heightBand);

	SetColor(0, 0, 1);
	FillRect(posX + (3 * widthBand), posY, widthBand, heightBand);

	SetColor(1, 0, 1);
	FillRect(posX + (4 * widthBand), posY, widthBand, heightBand);

	SetColor(1, 1, 0);
	FillRect(posX + (5 * widthBand), posY, widthBand, heightBand);

	SetColor(0, 1, 0);
	FillRect(posX + (6 * widthBand), posY, widthBand, heightBand);

	SetColor(0, 1, 1);
	FillRect(posX + (7 * widthBand), posY, widthBand, heightBand);

	SetColor(1, 1, 1);
	FillRect(posX + (8 * widthBand), posY, widthBand, heightBand);

	SetColor(0.f, 0.f, 0.f, 0.5f);
	FillRect(posX, posY, 9 * widthBand, heightBand / 2);

	SetColor(1, 1, 0);
	DrawRect(posX, posY, (9 * widthBand), heightBand);



}


void DrawPentagram() {
	


}

void DrawColumnChart() {

	int percentageEnjoyingChildhood{};
	int percentageResponisibitiesTime{};
	int percentageTooMuchTutitionCost{};
	int percentageLaidbackLifeInAFarm{};

	float posX{250};
	float posY{20};
	float widthColumn{30};
	float heightColumn{ 3 * widthColumn };
		

	std::cout << "%people playing games \nIn the range [0, 20]?" << std::endl;
	std::cin >> percentageEnjoyingChildhood;
	std::cout << "In the range [21, 40]?" << std::endl;
	std::cin >> percentageResponisibitiesTime;
	std::cout << "In the range [41, 60]?" << std::endl;
	std::cin >> percentageTooMuchTutitionCost;
	std::cout <<"Older than 60?" << std::endl;
	std::cin >> percentageLaidbackLifeInAFarm;

	SetColor(0, 0.6f, 0.6f);
	FillRect(posX, posY, widthColumn, heightColumn * (percentageEnjoyingChildhood / 100.f));
	SetColor(0, 0.4f, 0.8f);
	FillRect(posX + widthColumn, posY,widthColumn, heightColumn * (percentageResponisibitiesTime / 100.f));
	SetColor(0, 0.8f, 0.8f);
	FillRect(posX + 2 * widthColumn, posY,widthColumn, heightColumn * (percentageTooMuchTutitionCost / 100.f));
	SetColor(0, 0.5f, 1);
	FillRect(posX + 3 * widthColumn, posY,widthColumn, heightColumn * (percentageLaidbackLifeInAFarm / 100.f));




}

#pragma endregion ownDefinitions