#include "pch.h"
#include "Game.h"
#include "utils.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Vertices.push_back(Point2f{ utils::GetRand(0.f,m_Window.width),utils::GetRand(0.f,m_Window.height)});
	m_Vertices.push_back(Point2f{ utils::GetRand(0.f,m_Window.width),utils::GetRand(0.f,m_Window.height)});
	m_Vertices.push_back(Point2f{ utils::GetRand(0.f,m_Window.width),utils::GetRand(0.f,m_Window.height)});
	m_Vertices.push_back(Point2f{ utils::GetRand(0.f,m_Window.width),utils::GetRand(0.f,m_Window.height)});
	m_Vertices.push_back(Point2f{ utils::GetRand(0.f,m_Window.width),utils::GetRand(0.f,m_Window.height)});
	m_Vertices.push_back(Point2f{ utils::GetRand(0.f,m_Window.width),utils::GetRand(0.f,m_Window.height)});
}

void Game::Cleanup( )
{
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
	ClearBackground();
	utils::SetColor(Color4f{ 0,0,0,1 });
	utils::FillPolygon(m_Vertices);

	Point2f p1{ m_Window.width / 2.f,m_Window.height / 2.f }, p2{ m_MousePos };
	utils::HitInfo hit{};

	utils::SetColor(Color4f{ 1,1,0,1 });
	utils::DrawLine(p1, p2);

	if (utils::Raycast(m_Vertices, p1, p2, hit))
	{
		utils::DrawCircle(hit.intersectPoint, 5.f);

		utils::SetColor(Color4f{ 0,1,0,1 });
		DrawVector(hit.intersectPoint, hit.normal*30);

		Vector2f v1{ p1,p2 };
		v1 *= hit.lambda;
		Vector2f reflection{ v1.Reflect(hit.normal)};
		utils::SetColor(Color4f{ 0,0,1,1 });
		DrawVector(hit.intersectPoint, reflection * (1 - hit.lambda));
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
	m_MousePos.x = float(e.x);
	m_MousePos.y = float(e.y);
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

void Game::DrawVector(const Point2f& pos, const Vector2f& v) const
{
	utils::DrawLine(pos.x, pos.y, pos.x + v.x, pos.y + v.y);
}
