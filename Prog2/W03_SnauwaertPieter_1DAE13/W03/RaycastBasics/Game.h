#pragma once
#include "Vector2f.h"
#include <vector>
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
	const Window m_Window;
	std::vector<Point2f> m_Vertices;
	Point2f m_MousePos;
	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;

	void DrawVector(const Point2f& pos, const Vector2f& v) const;
};