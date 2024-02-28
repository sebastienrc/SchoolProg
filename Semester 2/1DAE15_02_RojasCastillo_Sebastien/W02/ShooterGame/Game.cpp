#include "pch.h"
#include "Game.h"
#include "Enemy.h"
//#include "utils.h"
#include <iostream>

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	InitializeEnemies();
}

void Game::Cleanup( )
{
	DeleteEnemies();
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
	DrawEnemies();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
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
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		DoHitEnemies(Rectf{ float(e.x),float(e.y),2,2 });

		std::cout << " left button " << std::endl;
		break;
	case SDL_BUTTON_RIGHT:
		//std::cout << " right button " << std::endl;
		break;
	case SDL_BUTTON_MIDDLE:
		//std::cout << " middle button " << std::endl;
		break;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}


void Game::InitializeEnemies()
{
	int maxRows{ 10 };
	int maxCollumns{ 4 };

	float squareSize{ 20.f };
	float margin{ 10.f };
	
	float distanceToCenter{ squareSize / 2 };


	for (int rows{ 0 }; rows < maxRows; rows++) 
	{
		for (int collumns{ 0 }; collumns < maxCollumns; collumns++)
		{
			float centerX{ margin + (squareSize * float(rows % maxRows)) + (distanceToCenter + float((distanceToCenter * (rows % maxRows)))) };
			float centerY{ 400 - (squareSize * float(collumns % maxCollumns)) - (distanceToCenter + float((distanceToCenter * (collumns % maxCollumns)))) };

			Point2f center{ centerX,centerY };
			m_pEnemies.push_back(new Enemy{ center, squareSize, squareSize });
		}

		
	}
}

void Game::DrawEnemies() const
{	
	for (size_t i{ 0 }; i < m_pEnemies.size(); i++)
	{
		m_pEnemies[i]->Draw();
	}


}

void Game::DeleteEnemies()
{
	for (size_t i{ 0 }; i < m_pEnemies.size(); i++)
	{
		delete m_pEnemies[i];
		m_pEnemies[i] = nullptr;
	}

	m_pEnemies.clear();
}

void Game::DoHitEnemies(const Rectf& other)
{
	for (size_t i{ 0 }; i < m_pEnemies.size(); i++)
	{
		m_pEnemies[i]->DoHitTest(other);
	}
}