#include "pch.h"
#include "Game.h"
#include "TrafficLight.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize()
{
	Point2f position{ 10.f,10.f };
	const float spacing{ 10.f };
	for (int i{}; i < 6; ++i)
	{
		for (int j{}; j < 2; ++j)
		{
			m_TrafficLights.push_back(new TrafficLight{ position });
			position.y += m_TrafficLights[0]->GetHeight()+spacing;
		}
		position.y = 10.f;
		position.x += m_TrafficLights[0]->GetWidth()+spacing;
	}
}

void Game::Cleanup( )
{
	for (TrafficLight* i : m_TrafficLights)
	{
		delete i;
		i = nullptr;
	}
}

void Game::Update( float elapsedSec )
{
	for (TrafficLight* i : m_TrafficLights)
	{
		i->Update(elapsedSec);
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
	for (TrafficLight* i : m_TrafficLights)
	{
		i->Draw();
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
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	Point2f mousePos{ float(e.x),float(e.y)};
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		for (TrafficLight* i : m_TrafficLights)
		{
			i->DoHitTest(mousePos);
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
