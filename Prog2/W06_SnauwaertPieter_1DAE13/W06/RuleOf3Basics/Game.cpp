#include "pch.h"
#include "Game.h"
#include "Container.h"
#include "Texture.h"
#include <iostream>

Texture Game::m_StatDaeTexture{ "Resources/DAE.png" };

Game::Game( const Window& window ) 
	:m_Window{ window}
	,m_DaeTexture{"Resources/DAE.png"}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	TestContainer();
	//m_StatDaeTexture = m_DaeTexture;
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
	ClearBackground( );
	m_StatDaeTexture.Draw();
	m_DaeTexture.Draw();
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

void Game::AddValues(Container& container, int howMany, int min, int max) const
{
	for (int i{}; i < howMany; ++i)
	{
		int value{ rand() % (max - min + 1) + min };
		container.PushBack(value);
	}
}

void Game::TestContainer() const
{
	Container c1{};
	AddValues(c1, 3, 1, 20);
	std::cout << c1[0] << "\n";

	Container c2{ c1 };
	c1[0] = 20;
	
	Container c3{ 3 };
	AddValues(c3, 3, 10, 20);
	c3 = c1;

	c3 = c3;

	c3 = 4;

	Container c4 = c3;

	c4 = c2;

	c4 = CreateMultiplied(c1, 2);

	AddValues(c4, 3, 20, 30);
}

Container Game::CreateMultiplied(Container c, int factor) const
{
	for (int i{}; i < c.Size(); ++i)
	{
		c[i] *= factor;
	}
	return c;
}
