#include "pch.h"
#include "Game.h"

#include "Square.h"
#include "Time.h"
#include <iostream>

Game::Game( const Window& window ) 
	:BaseGame{ window }
,	m_Squares{}
{
	Initialize();
	TestSquares();
	//CompareTimes(m_Time[0],m_Time[0]);
	//CompareTimes(m_Time[0], m_Time[1]);
	PrintInstancesCntr("message");
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Squares.push_back(new Square { 10 });
	m_Squares.push_back(new Square{ 20,30,10 });

	/*m_Time.push_back(new Time{ 40,40,7 });
	m_Time.push_back(new Time{ 20,30,11 });*/
}

void Game::Cleanup( )
{

	for (size_t i{ 0 }; i < m_Squares.size(); i++)
	{
		delete m_Squares[i];
		m_Squares[i] = nullptr;
	}

	m_Squares.clear();

	/*for (size_t i{ 0 }; i < m_Time.size(); i++)
	{
		delete m_Time[i];
		m_Time[i] = nullptr;
	}

	m_Time.clear();*/

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
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::TestSquares()
{

	for (size_t i{ 0 }; i < m_Squares.size(); i++)
	{
		std::cout << "--> Squares with contructor delegation\n";
		m_Squares[i]->Print();
	}


}

void Game::CompareTimes(const Time* t1, const Time* t2)
{
	std::cout << "--> Comparing 2 time objects\n";
	t1->Print();
	t2->Print();

	if (t1->GetSeconds() == t2->GetSeconds() &&
		t1->GetMinutes() == t2->GetMinutes() &&
		t1->GetHours() == t2->GetHours())
		std::cout << "They are equal\n";
	else
		std::cout << "They are not equal\n";
}


void Game::PrintInstancesCntr(const std::string& message)
{
	std::cout << message << " -> Nr of Time objects: " << Time::GetNrInstances() << std::endl;
}