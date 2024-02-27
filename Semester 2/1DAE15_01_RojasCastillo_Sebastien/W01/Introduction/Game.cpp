#include "pch.h"
#include "Game.h"
#include "Texture.h"
#include <iostream>

//Sebastien Rojas Castillo - 1DAE15

Game::Game( const Window& window ) 
	:BaseGame{ window }
,	m_pTextureImage	{nullptr}
,	m_pTextureText	{nullptr}
{
	Initialize();

}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	Color4f red{ 1.f,0.f,0.f,1.f };
	Color4f yellow{ 1.f,1.f,0.f,1.f };
	Ball* pFirstBall{ new Ball{Point2f{100,100},Vector2f{100,70},red,40} };
	Ball* pSecondBall{ new Ball{Point2f{300,300},Vector2f{200,150},yellow,80} };

	m_pBalls[0] = pFirstBall;
	m_pBalls[1] = pSecondBall;
	m_pTextureImage = new Texture{ "DAE.png" };
	m_pTextureText = new Texture{ "Dae","Impostograph-Regular.ttf",30,Color4f{1,1,1,1 } };
}

void Game::Cleanup( )
{
	for (int i{ 0 }; i < m_NrOfBalls; ++i)
	{
		delete m_pBalls[i];
	}
	m_pTextureImage->~Texture();
	delete m_pTextureImage;
	m_pTextureText->~Texture();
	delete m_pTextureText;

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

	for (int i{ 0 }; i < m_NrOfBalls; ++i)
	{
		m_pBalls[i]->Draw();
	}

	for (int i{ 1 }; i < 4 ; i++)
	{
		m_pTextureImage->Draw(Rectf{ 400.f,120.f * i,50.f * i,100.f },Rectf{0,0,m_pTextureImage->GetWidth(),m_pTextureImage->GetHeight()});
		m_pTextureText->Draw(Point2f{50.f,50.f*i});
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
