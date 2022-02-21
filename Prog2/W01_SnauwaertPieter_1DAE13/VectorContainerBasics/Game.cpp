#include "pch.h"
#include "Game.h"
#include "Card.h"
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
	int cols{ 13 };
	int rows{ 4 };
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			Card::Suit suit{};
			switch (i)
			{
			case 0:
				suit = Card::Suit::clubs;
				break;
			case 1:
				suit = Card::Suit::diamonds;
				break;
			case 2:
				suit = Card::Suit::hearts;
				break;
			case 3:
				suit = Card::Suit::spades;
				break;
			}
			m_pCards.push_back(new Card{ suit,j+1 });
		}
	}
}

void Game::Cleanup( )
{
	for (Card* i : m_pCards)
	{
		delete i;
		i = nullptr;
		m_pCards.pop_back();
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
	Rectf newRect{ 0,0,m_pCards[0]->GetWidth() / 2.f,m_pCards[0]->GetHeight() / 2.f };
	for (int i{}; i < 4; ++i)
	{
		for (int j{}; j < 13; ++j)
		{
			m_pCards[utils::GetIndex(i, j, 13)]->Draw(newRect);
			newRect.left += m_pCards[0]->GetWidth() / 4.f;
		}
		newRect.bottom += m_pCards[0]->GetHeight() / 2.f;
		newRect.left = 0.f;
	}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	switch ( e.keysym.sym )
	{
	case SDLK_PLUS:
	case SDLK_KP_PLUS:
		m_Numbers.push_back(rand() % 30);
		PrintElements(m_Numbers);
		break;
	case SDLK_MINUS:
	case SDLK_KP_MINUS:
		m_Numbers.pop_back();
		PrintElements(m_Numbers);
		break;
	case SDLK_UP:
		//for (int i : m_Numbers)
		//{
		//	i += 1;
		//}
		for (int i{}; i < m_Numbers.size(); ++i)
		{
			m_Numbers[i] += 1;
		}
		PrintElements(m_Numbers);
		break;
	case SDLK_DOWN:
		//for (int i : m_Numbers)
		//{
		//	i -= 1;
		//}
		for (int i{}; i < m_Numbers.size(); ++i)
		{
			m_Numbers[i] -= 1;
		}
		PrintElements(m_Numbers);
		break;
	case SDLK_s:
		Shuffle(m_pCards, int(m_pCards.size()));
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

void Game::PrintElements(std::vector<int>& numbers)
{
	for (int i : numbers)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void Game::Swap(std::vector<Card*>& cardsToSwap, int idx1, int idx2)
{
	Card* tempCard{ cardsToSwap[idx1] };
	cardsToSwap[idx1] = cardsToSwap[idx2];
	cardsToSwap[idx2] = tempCard;
}

void Game::Shuffle(std::vector<Card*>& cardsToShuffle, int amount)
{
	for (int i{}; i < amount; ++i)
	{
		int idx1{ utils::GetRand(0,int(m_pCards.size())) };
		int idx2{ utils::GetRand(0,int(m_pCards.size())) };
		if (idx1 == idx2)
		{
			idx2 = utils::GetRand(0, int(m_pCards.size()));
		}
		Swap(cardsToShuffle, idx1, idx2);
	}
}
