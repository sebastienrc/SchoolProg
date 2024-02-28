#include "pch.h"
#include "Game.h"
#include "utils.h"
#include "Smiley.h"
#include <iostream>

// Sebastien Rojas Castillo - 1DAE15



Game::Game( const Window& window ) 
	:BaseGame{ window }
,	m_WindowSize	{0,0,1400.f,600.f}
,	m_SafeRect		{100.f,100.f,1200.f,400.f}
,	m_HigestSmileyY	{}
{
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	CreateSmileys();
}

void Game::Cleanup( )
{
	DeleteSmileys();
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

	UpdateSmileys(elapsedSec);
	DetermineHighestSmiley();
}

void Game::Draw( ) const
{
	ClearBackground( );
	utils::SetColor(Color4f{ 0,0,0,1 });
	utils::DrawRect(m_SafeRect);
	DrawSmileys();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
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
	case SDLK_UP:
		IncreaseSmileySpeed();
		break;
	case SDLK_DOWN:
		DecreaseSmileySpeed();
		break;
	case SDLK_DELETE:
		DeleteSleepers();
		break;
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
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
		ClickSmiley(Point2f{ float(e.x),float(e.y) });
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


void Game::CreateSmileys()
{
	int nrOfSmileys{ 10 };

	for (int i{ 0 }; i < nrOfSmileys; i++)
	{
		m_Smileys.push_back(new Smiley{ Point2f{250.f + float(100 * i),250.f} });
	}
}

void Game::DrawSmileys() const
{
	for (size_t i{}; i < m_Smileys.size(); i++)
	{
		if(m_Smileys[i] != nullptr)
		m_Smileys[i]->Draw();
	}
}

void Game::UpdateSmileys(float elapsedSec)
{
	for (size_t i{}; i < m_Smileys.size(); i++)
	{
		if (m_Smileys[i] != nullptr)
		m_Smileys[i]->Update(elapsedSec, m_WindowSize, m_SafeRect);
	}
}

void Game::DeleteSmileys()
{
	for (size_t i{}; i < m_Smileys.size(); i++)
	{
		delete m_Smileys[i];
		m_Smileys[i] = nullptr;
	}

	m_Smileys.clear();

}

void Game::ClickSmiley(const Point2f& pos)
{
	for (size_t i{}; i < m_Smileys.size(); i++)
	{
		if(m_Smileys[i] != nullptr)
			m_Smileys[i]->HitTest(pos);
	}
}

void Game::IncreaseSmileySpeed()
{
	for (size_t i{}; i < m_Smileys.size(); i++)
	{
		if (m_Smileys[i] != nullptr)
		m_Smileys[i]->IncreaseSpeed();
	}
}

void Game::DecreaseSmileySpeed()
{
	for (size_t i{}; i < m_Smileys.size(); i++)
	{
		if (m_Smileys[i] != nullptr)
		m_Smileys[i]->DecreaseSpeed();
	}
}

void Game::DeleteSleepers()
{
	for (size_t i{}; i < m_Smileys.size(); i++)
	{
		if (m_Smileys[i] != nullptr)
		{
			if (m_Smileys[i]->IsSleeping())
			{
				delete m_Smileys[i];
				m_Smileys[i] = nullptr;
			}
		}		
	}
}

void Game::DetermineHighestSmiley()
{
	float highest{};


	for (size_t i{}; i < m_Smileys.size(); i++)
	{
		if (m_Smileys[i] != nullptr)
		{
			if (!m_Smileys[i]->IsSleeping())
			{
				if (m_Smileys[i]->GetPosition().y >= highest)
					highest = m_Smileys[i]->GetPosition().y;


				m_Smileys[i]->SetHighest(m_Smileys[i]->GetPosition().y >= m_HigestSmileyY);				
			}
		}
	}

	m_HigestSmileyY = highest;
}