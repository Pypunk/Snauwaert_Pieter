#include "pch.h"
#include "Game.h"
#include "utils.h"
#include <iostream>
#include "Enemy.h"
#include "Avatar.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	, m_pAvatar{ new Avatar{Point2f{m_Window.width / 2.f,60.f},50.f,50.f} }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	const float width{ 25.f };
	const float height{ 25.f };
	Point2f center{ width,m_Window.height+height*5.f };
	const int cols{ 10 };
	const int rows{ 10 };
	for (int i{}; i < 10; ++i)
	{
		for (int j{}; j < 10; ++j)
		{
			m_pEnemies[utils::GetIndex(j, i, 10)] = new Enemy{ center,width,height };
			center.y -= height * 2.f;
		}
		center.y = m_Window.height+height*5.f;
		center.x += width * 2.f;
	}
	m_pAvatar->SetBoundaries(Rectf{ 0,0,m_Window.width,m_Window.height });
}

void Game::Cleanup( )
{
	for (Enemy* i : m_pEnemies)
	{
		delete i;
		i = nullptr;
	}
	delete m_pAvatar;
	m_pAvatar = nullptr;
}

void Game::Update( float elapsedSec )
{
	for (Enemy* i : m_pEnemies)
	{
		i->Update(elapsedSec);
	}
	m_pAvatar->Update(elapsedSec,m_pEnemies,m_AmountOfEnemies);
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
	for (int i{}; i < m_AmountOfEnemies; ++i)
	{
		m_pEnemies[i]->Draw();
	}
	m_pAvatar->Draw();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
	m_pAvatar->ProcessKeyDownEvent(e);
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
	Point2f mousePos{ float(e.x),float(e.y) };
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		break;
	}
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
