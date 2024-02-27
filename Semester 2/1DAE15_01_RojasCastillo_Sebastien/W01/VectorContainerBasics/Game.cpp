#include "pch.h"
#include "Game.h"
#include <iostream>
#include "Card.h"

//Sebastien Rojas Castillo - 1DAE15
Game::Game( const Window& window ) 
	:BaseGame{ window }
,	m_CardsScale{0.5f}
{
	Initialize();
	ShowMenu();
}

Game::~Game( )
{
	Cleanup( );
	
}

void Game::Initialize( )
{
	InitCards();
}

void Game::Cleanup( )
{
	m_MyNumbers.clear();
	DeleteCards();
}

void Game::Update( float elapsedSec )
{
	// Check keyboard state
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

void Game::Draw( ) const
{
	ClearBackground( );
	DrawCards();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch ( e.keysym.sym )
	{
	case SDLK_LEFT:
		//std::cout << "Left arrow key released\n";
		break;
	case SDLK_RIGHT:
		//std::cout << "`Right arrow key released\n";
		break;
	case SDLK_1:
	case SDLK_KP_1:
		//std::cout << "Key 1 released\n";
		break;
	case SDLK_h:
		ShowMenu();
		
		break;
	case SDLK_p:
		AddNumber();
		break;
	case SDLK_m:
		RemoveNumber();
		break;
	case SDLK_c:
		IncrementNumbers();
		DeleteCards();
		break;
	case SDLK_v:
		DecrementNumbers();
		break;
	case SDLK_s:
		ShuffleCards();
		break;
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	
	glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::ShowMenu() const
{
	std::cout << "p: Add a number at the end of the vector\n";
	std::cout << "m: Remove last number from vector\n";
	std::cout << "c: Increment all numbers in the vector \n";
	std::cout << "v: Decrement all numbers in the vector\n";
	std::cout << "h: Show menu\n";

}

void Game::IncrementNumbers()
{
	for (size_t i{ 0 }; i < m_MyNumbers.size(); i++)

	{
		m_MyNumbers[i]++;
		
	}
	PrintNumbers();
}

void Game::DecrementNumbers()
{
	for (size_t i{ 0 }; i < m_MyNumbers.size(); i++)

	{
		m_MyNumbers[i]--;
	}
	PrintNumbers();
}

void Game::AddNumber()
{
	int randomNumber{ rand() % 30 };
	m_MyNumbers.push_back(randomNumber);
	PrintNumbers();
	
}

void Game::RemoveNumber()
{
	if (!m_MyNumbers.empty())
		m_MyNumbers.pop_back();
	PrintNumbers();
}

void Game::PrintNumbers() const
{
	for (size_t i{ 0 }; i < m_MyNumbers.size(); i++)

	{
		std::cout << m_MyNumbers[i] << " ";
	}
	std::cout << std::endl;
}

void Game::InitCards()
{
	int maxSuits{ 4 };
	int maxRank{ 13 };

	for(int suit { 0 }; suit < maxSuits ; suit++)
	{
		for (int rank{ 0 }; rank < maxRank; rank++)
		{
			switch (suit)
			{
			case 0:
				m_pCards.push_back(new Card{ Card::Suit::clubs,rank + 1 });
				break;
			case 1:
				m_pCards.push_back(new Card{ Card::Suit::diamonds,rank + 1 });
				break;

			case 2:
				m_pCards.push_back(new Card{ Card::Suit::hearts,rank + 1 });
				break;
			case 3:
				m_pCards.push_back(new Card{ Card::Suit::spades,rank + 1 });
				break;
			default:
				break;
			}
		}
	}
}

void Game::DrawCards() const
{

	for (size_t i{ 0 }; i < m_pCards.size(); i++)
	{
		Rectf dstRect{
			m_pCards[i]->GetWidth()   * (i % 13)	* m_CardsScale
		,	m_pCards[i]->GetHeight() * (i % 4)	* m_CardsScale
		,	m_pCards[i]->GetWidth()				* m_CardsScale
		,	m_pCards[i]->GetHeight()			* m_CardsScale
		};

	
		m_pCards[i]->Draw(dstRect);
	}
}

void Game::ShuffleCards()
{
	for (size_t i{ 0 }; i < m_pCards.size(); i++)
	{
		int randomCard{ rand() % int(m_pCards.size() )};
		if (i == randomCard)
			randomCard = rand() % int(m_pCards.size());


		Card* temp{ m_pCards[i] };
			
		m_pCards[i] = m_pCards[randomCard];
		m_pCards[randomCard] = temp;
		temp = nullptr;
		
	}
}

void Game::DeleteCards()
{
	for (size_t i{ 0 }; i < m_pCards.size(); i++)
	{
		//m_pCards[i]->~Card();
		delete m_pCards[i];
		m_pCards[i] = nullptr;
	}

	m_pCards.clear();
}

