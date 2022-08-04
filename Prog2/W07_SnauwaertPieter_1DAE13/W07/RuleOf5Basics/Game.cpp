#include "pch.h"
#include "Game.h"
#include "Container.h"
#include "Sprite.h"
#include <iostream>

Game::Game( const Window& window ) 
	:m_Window{ window }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
	for (Sprite* i : m_Sprites)
	{
		delete i;
	}
}

void Game::Initialize( )
{
	TestContainer();
	TestSpriteClass();
	for (int i{}; i < m_AmountOfSprites; ++i)
	{
		m_Sprites.push_back(new Sprite{ "Resources/Tibo.png",5,5,1.f / utils::GetRand(10,16),1 });
	}
	std::cout << m_Sprites.capacity() << '\n';
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
	for (Sprite* i : m_Sprites)
	{
		i->Update(elapsedSec);
	}
}

void Game::Draw( ) const
{
	ClearBackground( );
	for (Sprite* i : m_Sprites)
	{
		i->Draw(Rectf{ 0,0,i->GetFrameWith(),i->GetFrameHeight() });
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

void Game::TestContainer()
{
	std::cout << "--> Test that demonstrates the need of Move constructor\n";
	Container c1{ CreateContainer(20,10,20) };

	std::cout << "--> Test that demonstrates the need of a Move assignment operator\n";
	c1 = CreateContainer(10, 20, 30);
}

void Game::TestSpriteClass()
{
	std::cout << "\n--> Sprite class: Test rule of 5 started\n";
	{
		Sprite sprite1{ "Resources/RunningKnight.png",8,1,0.08f,1 };
		Sprite sprite2{ "Resources/RunningKnight.png",8,1,0.08f,1 };
		Sprite sprite3{ sprite1 };
		sprite2 = sprite1;
		Sprite sprite4{ CreateSprite("Resources/Tibo.png",5,5,1 / 10.f) };
		sprite1 = CreateSprite("Resources/Tibo.png", 5, 5, 1 / 10.f);
		std::cout << "std::move: ";
		sprite2 = std::move(sprite1);
	}
	std::cout << "\n--> Sprite class : Test rule of 5 ended\n";
}

Container Game::CreateContainer(int nrElements, int min, int max)
{
	Container c{ nrElements };
	for (int i{}; i < nrElements; ++i)
	{
		c.PushBack(utils::GetRand(min, max));
	}
	return c;
}

Sprite Game::CreateSprite(const std::string& filename, int nrCols, int nrRows, float frameSec)
{
	Sprite s{ filename,nrCols,nrRows,frameSec,1 };
	return s;
}
