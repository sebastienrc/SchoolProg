#include "pch.h"
#include "Game.h"
#include "TrafficLight.h"

//Sebastien Rojas Castillo - 1DAE15

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
	for (int row{ 0 }; row < 2; row++)
	{
		for (int i{ 0 }; i < 5; i++)
		{
			m_Light.push_back(new TrafficLight{ Point2f{10 + float(90 * i),10 + float(250 * row)}});
		}
	}
	
}

void Game::Cleanup( )
{

	DeleteTrafficLights();

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

	for (size_t i{ 0 }; i < m_Light.size(); i++)
	{
		m_Light[i]->Update(elapsedSec);
	}


}

void Game::Draw( ) const
{
	ClearBackground( );
	for (size_t i{ 0 }; i < m_Light.size(); i++)
	{
		m_Light[i]->Draw();
	}
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
		//std::cout << " left button " << std::endl;
		ClickTrafficLights(Point2f{ float(e.x),float(e.y)});
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
	glClearColor( 0.3f, 0.3f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::DeleteTrafficLights()
{

	for (size_t i{ 0 }; i < m_Light.size(); i++)
	{
		delete m_Light[i];
		m_Light[i] = nullptr;
	}

	m_Light.clear();

}

void Game::ClickTrafficLights(Point2f mousePos)
{
	for (size_t i{ 0 }; i < m_Light.size(); i++)
	{
		
		m_Light[i]->DoHitTest(mousePos);
	}
}
