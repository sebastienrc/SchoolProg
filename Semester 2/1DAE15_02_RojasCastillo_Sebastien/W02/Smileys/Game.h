#pragma once

#include "vector"
class Smiley;
// Sebastien Rojas Castillo - 1DAE15



#include "BaseGame.h"
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

	std::vector <Smiley*> m_Smileys;
	Rectf m_WindowSize;
	Rectf m_SafeRect;
	float m_HigestSmileyY;



	void CreateSmileys();
	void DrawSmileys() const;
	void DeleteSmileys();
	void DeleteSleepers();

	void UpdateSmileys(float elapsedSec);
	void ClickSmiley(const Point2f& pos);

	void IncreaseSmileySpeed();
	void DecreaseSmileySpeed();
	
	void DetermineHighestSmiley();
};