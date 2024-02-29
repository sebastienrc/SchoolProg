#pragma once
#include "BaseGame.h"
#include "vector"

// Sebastien Rojas Castillo - 1DAE15


class Enemy;
class Avatar;

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

	std::vector <Enemy*> m_pEnemies;

	Avatar* m_pAvatar;

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;


	void InitializeEnemies();
	void DrawEnemies() const;
	void DeleteEnemies();
	void DoHitEnemies(const Rectf& other);

	void InitializeAvatar();
	void DeleteAvatar();
	void DrawAvatar() const;
	void UpdateAvatar(float elapsedSec,std::vector<Enemy*>& enemies);
};