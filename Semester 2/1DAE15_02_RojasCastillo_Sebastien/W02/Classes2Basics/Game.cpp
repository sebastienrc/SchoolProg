#include "pch.h"
#include "Game.h"

#include "Square.h"
#include "Time.h"
#include "Container.h"

#include <iostream>
#include <sstream>

Game::Game( const Window& window ) 
	:BaseGame{ window }
,	m_Squares{}
{
	Initialize();
	TestSquares();
	//CompareTimes(m_Time[0],m_Time[0]);
	//CompareTimes(m_Time[0], m_Time[1]);
	
	std::stringstream buffer;
	
	for (int i{ 0 }; i < 5; i++)
	{
		if(m_Time.size() == NULL)
			PrintInstancesCntr("Before creating the Time object");

		m_Time.push_back(new Time{ 40,40,7 });

		buffer << "After creating ";
		buffer << Time::GetNrInstances();
		buffer << " objects ";
		PrintInstancesCntr(buffer.str());
		buffer.str(std::string());
	}

	TestContainer();

}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Squares.push_back(new Square { 10 });
	m_Squares.push_back(new Square{ 20,30,10 });

	
}

void Game::Cleanup( )
{

	for (size_t i{ 0 }; i < m_Squares.size(); i++)
	{
		delete m_Squares[i];
		m_Squares[i] = nullptr;
	}

	m_Squares.clear();

	std::stringstream buffer;


	for (size_t i{ 0 }; i < m_Time.size(); i++)
	{

		delete m_Time[i];
		m_Time[i] = nullptr;

		if (i + 1 == m_Time.size())
			PrintInstancesCntr("After deleting all instances");
		else
		{
			buffer << "After deleting " << i + 1;
			buffer << " instance";
			PrintInstancesCntr(buffer.str());
			buffer.str(std::string());
		}
	}

	m_Time.clear();

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


void Game::TestContainer()
{
	std::cout << "\n-- Container tests --\n";
	// Define a Container object
	const int cap{ 5 };
	std::cout << "Create container with capacity of " << cap << " elements\n";
	Container* pContainer{ new Container{cap} };
	PrintContainer(pContainer);

	// Add some values to the container
	int actNr{ 0 };
	std::cout << "\nPush back of " << (cap - 1) << " elements\n";
	for (int idx{ 1 }; idx < cap; ++idx)
	{
		pContainer->PushBack(rand() % 21);
		++actNr;
	}
	PrintContainer(pContainer);

	std::cout << "\nChange the value of the elements (using Set)\n";
	for (int idx{ 0 }; idx < actNr; ++idx)
	{
		pContainer->Set(idx, rand() % 21);
	}
	PrintContainer(pContainer);

	std::cout << "\nPush back another " << (cap - 1) << " elements\n";
	for (int i{ 1 }; i < cap; ++i)
	{
		pContainer->PushBack(rand() % 21);
		++actNr;
	}
	PrintContainer(pContainer);
	delete pContainer;
}

void Game::PrintContainer(const Container* pContainer)
{
	std::cout << "-- Print container --\n";
	std::cout << "   Capacity: " << pContainer->Capacity() << std::endl;
	std::cout << "   Size: " << pContainer->Size() << std::endl;
	std::cout << "   Get the elements (using Get and Size)\n   ";
	for (int idx{ 0 }; idx < pContainer->Size(); ++idx)
	{
		std::cout << pContainer->Get(idx) << " ";
	}
	std::cout << std::endl;
}

