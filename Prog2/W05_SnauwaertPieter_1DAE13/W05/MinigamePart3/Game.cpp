#include "pch.h"
#include <iostream>
#include "Game.h"
#include "utils.h"
#include "Camera.h"
#include "HUD.h"

Game::Game( const Window& window )
	:m_Window{ window }
	, m_Camera{ new Camera{m_Window.width,m_Window.height} }
	,m_ReachedEnd{false}
{	 
	Initialize( );
	m_pHUD = new HUD{ Point2f{0,m_Window.height},int(m_PowerUpManager.Size()) };
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	AddPowerUps( );
	m_Camera->SetLevelBoundaries(Rectf{ 0,-0,846.f,500.f });
}

void Game::Cleanup( )
{
	delete m_Camera;
	delete m_pHUD;
}

void Game::Update( float elapsedSec )
{
	if (!m_ReachedEnd)
	{
		// Update game objects
		m_PowerUpManager.Update(elapsedSec);
		m_Avatar.Update(elapsedSec, m_Level);
		// Do collision
		DoCollisionTests();
		m_ReachedEnd = m_Level.HasReachedEnd(m_Avatar.GetShape());
	}
}

void Game::Draw( ) const
{
	ClearBackground( );
	
	glPushMatrix();
	m_Camera->Transform(m_Avatar.GetShape());
	m_Level.DrawBackground( );
	m_PowerUpManager.Draw( );
	m_Avatar.Draw();
	m_Level.DrawForeground();
	glPopMatrix();
	m_pHUD->Draw();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::AddPowerUps( )
{
	m_PowerUpManager.AddItem( Point2f{ 185.0f, 500 - 183.0f }, PowerUp::Type::brown );
	m_PowerUpManager.AddItem( Point2f{ 435.0f, 500 - 133.0f }, PowerUp::Type::green );
	m_PowerUpManager.AddItem( Point2f{ 685.0f, 500 - 183.0f }, PowerUp::Type::brown );
}

void Game::DoCollisionTests( )
{
	if ( m_PowerUpManager.HitItem( m_Avatar.GetShape( ) ) )
	{
		m_Avatar.PowerUpHit( );
		m_pHUD->PowerUpHit();
	}
}

