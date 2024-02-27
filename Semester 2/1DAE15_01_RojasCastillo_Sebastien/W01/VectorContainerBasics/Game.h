#pragma once
#include "BaseGame.h"
#include "vector"

//Sebastien Rojas Castillo - 1DAE15
class Card;

class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;
	void ShowMenu() const;

	std::vector<int> m_MyNumbers;

	void AddNumber();
	void RemoveNumber();
	void IncrementNumbers();
	void DecrementNumbers();
	void PrintNumbers() const;

	std::vector<Card*> m_pCards;
	float m_CardsScale;
	void InitCards();
	void DrawCards() const;
	void ShuffleCards();
	void DeleteCards();




	

};