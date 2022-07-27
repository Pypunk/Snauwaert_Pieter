#include "pch.h"
#include "Game.h"
#include "utils.h"
#include <iostream>
#include "Matrix2x3.h"
#include "Texture.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	, m_Angle{}
	, m_Scale{1.f}
	, m_Position{}
	,m_Texture{"Resources/Images/Diamond.png"}
	,m_Selected{false}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
   	const float size{ 48.f };
	m_Vertices.push_back(Point2f{ size / 2.f,0.f });
	m_Vertices.push_back(Point2f{ size,size / 2.f });
	m_Vertices.push_back(Point2f{ size / 2.f,size });
	m_Vertices.push_back(Point2f{ 0,size / 2.f });
	PrintKeyInfo();
	for (int i{}; i < 4; ++i)
	{
		m_TransVertices[i] = Point2f{};
	}
}

void Game::Cleanup( )
{
}

void Game::Update(float elapsedSec)
{
	// Check keyboard state
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_A])
	{
		m_Angle -= 60.f * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_D])
	{
		m_Angle += 60.f * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_W])
	{
		m_Scale *= 1 + 3.f * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_S])
	{
		m_Scale /= 1 + 3.f * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_UP])
	{
		m_Position.y += 120.f * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_DOWN])
	{
		m_Position.y -= 120.f * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_LEFT])
	{
		m_Position.x -= 120.f * elapsedSec;
	}
	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_Position.x += 120.f * elapsedSec;
	}
	const float size{ 48.f };
	Matrix2x3 TranslateMat{};
	TranslateMat.SetAsTranslate(m_Position.x, m_Position.y);
	Matrix2x3 RotMat{};
	RotMat.SetAsRotate(m_Angle);
	Matrix2x3 ScaleMat{};
	ScaleMat.SetAsScale(m_Scale);
	Matrix2x3 originMat{};
	originMat.SetAsTranslate(-size / 2.f, -size / 2.f);
	Matrix2x3 TRSMat{ originMat.Inverse() * TranslateMat * RotMat * ScaleMat * originMat };
	TRSMat.Transform(m_Vertices, m_TransVertices);
}

void Game::Draw( ) const
{
	const float size{ 48.f };
	ClearBackground( );
	if (m_Selected)
	{
		utils::SetColor(Color4f{ 1,0,0,1 });
	}
	else
	{
		utils::SetColor(Color4f{ 0,0,1,1 });
	}
	m_Texture.Draw();
	utils::DrawPolygon(m_Vertices,true,3.f);
	glPushMatrix();
	glTranslatef(size / 2.f, size / 2.f, 1.f);
	glTranslatef(m_Position.x, m_Position.y, 0.f);
	glRotatef(m_Angle, 0.f, 0.f, 1.f);
	glScalef(m_Scale, m_Scale, 1.f);
	glTranslatef(-size / 2.f, -size / 2.f, 0.f);
	m_Texture.Draw();
	glPopMatrix();
	utils::DrawPolygon(m_TransVertices, 4, true, 3.f);
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
		if (utils::IsPointInPolygon(mousePos, m_TransVertices, size_t(4)))
		{
			m_Selected = !m_Selected;
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

void Game::PrintKeyInfo() const
{
	std::cout << "a: Rotate ccw\n";
	std::cout << "d: Rotate cw\n";
	std::cout << "w: Zoom in\n";
	std::cout << "s: Zoom out\n";
	std::cout << "Arrows: Translate\n";
}
