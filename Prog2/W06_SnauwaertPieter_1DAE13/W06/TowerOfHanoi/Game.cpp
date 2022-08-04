#include "pch.h"
#include "Game.h"
#include "Tower.h"
#include "Disk.h"

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
	int amountOfTowers{ 3 };
	Point2f position{25.f,0.f};
	for (int i{}; i < amountOfTowers; ++i)
	{
		m_pTowers.push_back(new Tower{ position,250.f });
		position.x += m_pTowers[0]->GetSize()+25.f;
	}
	const int amountOfDisks{ 3 };
	float width{ 200.f };
	const float height{ 25.f };
	position = Point2f{ m_pTowers[0]->GetBottomRect().left + 25.f,m_pTowers[0]->GetBottomRect().bottom + 25.f };
	for (int i{}; i < amountOfDisks; ++i)
	{
		m_pDisks.push_back(new Disk{ position,width,height });
		width -= 50.f;
		position.x += 25.f;
		position.y += 25.f;
	}
}

void Game::Cleanup( )
{
	for (Tower* i : m_pTowers)
	{
		delete i;
	}
	for (Disk* i : m_pDisks)
	{
		delete i;
	}
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
	for (Tower* i : m_pTowers)
	{
		i->Draw();
	}
	for (Disk* i : m_pDisks)
	{
		i->Draw(Color4f{ 1,0,0,1 }, m_MousePos);
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
	m_MousePos = Point2f{ float(e.x),float(e.y) };
	for (Tower* i : m_pTowers)
	{
		i->IsMouseOnTop(m_MousePos);
	}
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		for (Disk* i : m_pDisks)
		{
			i->ToggleClicked(m_MousePos);
		}
		break;
	}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		for (Tower* it : m_pTowers)
		{
			for (int i{}; i < m_pDisks.size(); ++i)
			{
				m_pDisks[i]->Release(it);
			}
		}
		break;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
