#include "pch.h"
#include "Game.h"

#include <sstream>
#include <iostream>

#include <random>		//
#include <algorithm>	// Shuffle Libs

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	
	for (int suitIndex {}; suitIndex < NR_SUITS; ++suitIndex)
	{
		for (int cardIndex{}; cardIndex < NR_CARDS_PER_SUIT; ++cardIndex)
		{

			std::stringstream buffer;

			buffer << "Resources/Cards/";
			buffer << (suitIndex + 1);
			if (cardIndex < 9) {
				buffer << "0";
			}
			buffer << (cardIndex + 1);
			buffer << ".png";

			TextureFromFile(buffer.str(), g_CardsTexturesArr[cardIndex + suitIndex * NR_CARDS_PER_SUIT]);
		}
	}




}

void Draw()
{
	ClearBackground();


	for (int suitIndex{}; suitIndex < NR_SUITS; ++suitIndex){
		for (int cardIndex{}; cardIndex < NR_CARDS_PER_SUIT; ++cardIndex) {
			int index{ cardIndex + suitIndex * NR_CARDS_PER_SUIT };
			DrawTexture(g_CardsTexturesArr[index], Point2f{ g_CardsTexturesArr[index].width * float(cardIndex),
															g_CardsTexturesArr[index].height * suitIndex });


		}
	}

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
	switch (key)
	{
	case SDLK_LEFT:
		//std::cout << "left arrow key released\n";
		break;
	case SDLK_RIGHT:
		//std::cout << "right arrow key released\n";
		break;
	case SDLK_1:
	case SDLK_KP_1:
		//std::cout << "key 1 released\n";
		break;
	case SDLK_s:
		ShuffleCard();
		break;
	}
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


void ShuffleCard() {

	for (int cardIndex {0}; cardIndex < NR_SUITS * NR_CARDS_PER_SUIT; ++cardIndex)
	{

		int randomCardIndex{ rand() % NR_SUITS * NR_CARDS_PER_SUIT };
		//swap the cards:
		//make a temp to copy the first
		//copy the second in the first
		//copy the temp into the second

		Texture temp{ g_CardsTexturesArr[cardIndex] };
		g_CardsTexturesArr[cardIndex] = g_CardsTexturesArr[randomCardIndex];
		g_CardsTexturesArr[randomCardIndex] = temp;

	}




	/*std::shuffle(	g_CardsTexturesArr,
					g_CardsTexturesArr +NR_SUITS * NR_CARDS_PER_SUIT,
					std::default_random_engine{std::random_device{}()});*/

}

#pragma endregion ownDefinitions