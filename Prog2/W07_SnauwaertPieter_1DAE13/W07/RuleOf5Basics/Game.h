#pragma once
#include "Container.h"
#include "Sprite.h"
class Game final
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( ) const;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	const int m_AmountOfSprites{ 12 };
	const Window m_Window;
	std::vector<Sprite*> m_Sprites;
	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;

	void TestContainer();
	void TestSpriteClass();
	Container CreateContainer(int nrElements, int min, int max);
	Sprite CreateSprite(const std::string& filename, int nrCols, int nrRows, float frameSec);
};