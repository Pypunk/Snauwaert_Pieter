#include "pch.h"
#include "Game.h"
#include "Character.h"
#include "Level.h"
#include "Camera.h"

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
	m_pCharacter = new Character{ Point2f{m_Window.width / 2.f,m_Window.height / 2.f} };
	m_pLevel = new Level{};
	m_pCamera = new Camera{ m_Window.width,m_Window.height };
	m_pCamera->SetLevelBoundaries(Rectf{ 0,0,m_Window.width * 4,m_Window.height * 4 });
}

void Game::Cleanup( )
{
	delete m_pCharacter;
	m_pCharacter = nullptr;
	delete m_pLevel;
	m_pLevel = nullptr;
	delete m_pCamera;
	m_pCamera = nullptr;
}

void Game::Update( float elapsedSec )
{
	m_ElapsedSec = elapsedSec;
	m_pCharacter->Update(elapsedSec, *m_pLevel);
	m_pLevel->HandleCollision(m_pCharacter->GetShape(), m_pCharacter->GetVelocity());
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
	glPushMatrix();
	m_pCamera->Transform(m_pCharacter->GetShape());
	m_pCharacter->Draw();
	m_pLevel->Draw();
	glPopMatrix();
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
