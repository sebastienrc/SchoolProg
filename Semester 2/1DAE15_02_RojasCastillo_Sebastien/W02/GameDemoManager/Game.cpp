#include "pch.h"
#include "Game.h"
#include "PowerUpManager.h"
#include "utils.h"
#include <iostream>

Game::Game( const Window& window ) 
	:BaseGame{ window }
,	m_MouseCursor{0,0,10.f,10.f}
,	m_TestPowerUpManager{ new PowerUpManager{} }
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_TestPowerUpManager->AddItem(Point2f{ 150.f, 150.f }, PowerUp::Type::green);
	m_TestPowerUpManager->AddItem(200.f, 300.f, PowerUp::Type::green);
	m_TestPowerUpManager->AddItem(500.f, 350.f, PowerUp::Type::brown);
	m_TestPowerUpManager->AddItem(700.f, 200.f, PowerUp::Type::brown);
}

void Game::Cleanup( )
{
	delete m_TestPowerUpManager;
	m_TestPowerUpManager = nullptr;

	
}

void Game::Update( float elapsedSec )
{
	m_TestPowerUpManager->Update(elapsedSec);

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
	ClearBackground();
	m_TestPowerUpManager->Draw();
	utils::SetColor(Color4f{ 1,0,0,1 });
	utils::FillRect(m_MouseCursor);

	
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
	m_MouseCursor.bottom	= e.y;
	m_MouseCursor.left		= e.x;
	//std::cout << "X: " << m_MouseCursor.left << " Y: " << m_MouseCursor.bottom << std::endl;
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
		
		m_TestPowerUpManager->RemoveItem(m_TestPowerUpManager->IsHit(m_MouseCursor));
		std::cout << "Manager size: " << m_TestPowerUpManager->Size() << std::endl;
		
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
