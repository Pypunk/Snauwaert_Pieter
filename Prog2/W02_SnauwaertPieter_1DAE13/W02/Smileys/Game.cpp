#include "pch.h"
#include "Game.h"
#include "Smiley.h"
#include "utils.h"
#include <iostream>

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
	Point2f position{};
	for (int i{}; i < m_AmountOfSmileys; ++i)
	{
		m_pSmileys.push_back(new Smiley{position});
		position.x += 50.f;
		position.y = utils::GetRand(0.f, m_Window.height);
	}
}

void Game::Cleanup( )
{
	for (Smiley* i : m_pSmileys)
	{
		delete i;
		i = nullptr;
	}
}

void Game::Update( float elapsedSec )
{
	Rectf boundingRect{ 0,0,m_Window.width,m_Window.height };
	Rectf safeRect{ 50,50,m_Window.width - 100,m_Window.height - 100 };
	for (int i{}; i < m_pSmileys.size(); ++i)
	{
		m_pSmileys[i]->Update(elapsedSec, boundingRect, safeRect);
	}
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
	DrawSmileys();
	Rectf safeRect{ 50,50,m_Window.width - 100,m_Window.height - 100 };
	utils::DrawRect(safeRect);
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
	Point2f mousePos{ float(e.x),float(e.y) };
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		for (Smiley* i : m_pSmileys)
		{
			i->HitTest(mousePos);
		}
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

void Game::DrawSmileys() const
{
	for (Smiley* i : m_pSmileys)
	{
		i->Draw();
	}
}
