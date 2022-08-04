#include "pch.h"
#include "Game.h"
#include "Ball.h"
#include "Texture.h"
#include "utils.h"
#include <iostream>
#include <vector>
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
	for (int i{}; i < m_NumBalls; ++i)
	{
		m_pBallPointers[i] = new Ball{ Point2f{utils::GetRand(0.f,m_Window.width),100.f},Vector2f{100.f,100.f},Color4f{1,0,0,1},40 };
	}
	m_pDAETexture = new Texture{ "Resources/DAE.png" };
	if (!m_pDAETexture->IsCreationOk())
	{
		std::cout << "Texture not loaded correctly!\n";
	}
	VectorTest();
}

void Game::Cleanup( )
{
	for (const Ball* i : m_pBallPointers)
	{
		delete i; 
		i = nullptr;
	}
	delete m_pDAETexture;
	m_pDAETexture = nullptr;
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
	for (Ball* i : m_pBallPointers)
	{
		i->Update(elapsedSec, Rectf{ 0,0,m_Window.width,m_Window.height });
	}
}

void Game::Draw( ) const
{
	ClearBackground( );
	for (Ball* i : m_pBallPointers)
	{
		i->Draw();
	}
	m_pDAETexture->Draw(Point2f{});
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	switch ( e.keysym.sym )
	{
	case SDLK_SPACE:
		//std::cout << "Left arrow key released\n";
		break;
	}
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

void Game::VectorTest()
{
	std::vector<int> numbers{ 4,8,4,5,2,1,4,6,9 };
	numbers.push_back(rand());

	for (const int i : numbers)
	{
		std::cout << i << "\n";
	}
	numbers.pop_back();
	for (const int i : numbers)
	{
		std::cout << i << "\n";
	}
}
