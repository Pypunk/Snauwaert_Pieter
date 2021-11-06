#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateRects();
	CreateBall();
}

void Draw()
{
	ClearBackground(0,0,0);

	// Put your own draw statements here
	FillRect(g_LeftRect);
	FillRect(g_RightRect);
	FillEllipse(g_Ball);
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_Ball.center.x += g_XSpeed * elapsedSec;
	g_Ball.center.y += g_YSpeed * elapsedSec;
	if (!IsPointInRect(g_Ball.center, Rectf{0,0,g_WindowWidth,g_WindowHeight}))
	{
		g_YSpeed = -g_YSpeed;
	}
	if (IsPointInRect(g_Ball.center,g_LeftRect))
	{
		g_XSpeed = GenerateRandomFloat(100, 200);
	}
	if (IsPointInRect(g_Ball.center, g_RightRect))
	{
		g_XSpeed = -GenerateRandomFloat(100, 200);
	}
	if (g_Ball.center.x < 0)
	{
		g_CounterPlayer2++;
		std::cout << "Player2: " << g_CounterPlayer2 << std::endl;
		CreateBall();
	}
	if (g_Ball.center.x > g_WindowWidth)
	{
		g_CounterPlayer1++;
		std::cout << "Player1: " << g_CounterPlayer1 << std::endl;
		CreateBall();
	}
	// e.g. Check keyboard state
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

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	float g_RectSpeed{ 20.f };
	switch (key)
	{
	case SDLK_w:
		if (g_LeftRect.bottom+g_LeftRect.height <= g_WindowHeight)
		{
			g_LeftRect.bottom += g_RectSpeed;
		}
		break;
	case SDLK_s:
		if (g_LeftRect.bottom > 0)
		{
			g_LeftRect.bottom -= g_RectSpeed;
		}
		break;
	case SDLK_UP:
		if (g_RightRect.bottom + g_RightRect.height <= g_WindowHeight)
		{
			g_RightRect.bottom += g_RectSpeed;
		}
		break;
	case SDLK_DOWN:
		if (g_RightRect.bottom > 0)
		{
			g_RightRect.bottom -= g_RectSpeed;
		}
		break;
	case SDLK_r:
		CreateBall();
		break;
	default:
		break;
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void CreateRects()
{
	g_LeftRect = Rectf{ 50.f,g_WindowWidth / 2 - 100.f,20.f,100.f };
	g_RightRect = Rectf{ g_WindowWidth - 70.f,g_WindowWidth / 2 - 100.f,20.f,100.f };
}
void CreateBall()
{
	g_Ball = Ellipsef(Point2f{ GenerateRandomFloat(50,g_WindowWidth-50),GenerateRandomFloat(50,g_WindowHeight-100) }, 10, 10);
	g_XSpeed = GenerateRandomFloat(100, 200);
	g_YSpeed = GenerateRandomFloat(100, 200);
}
float GenerateRandomFloat(float min, float max)
{
	return ((rand() % (int)max*100) + min*100)/100.f;
}
bool IsPointInRect(const Point2f& p, const Rectf& r)
{
	return (p.x >= r.left && p.x <= r.left + r.width &&
		p.y >= r.bottom && p.y <= r.bottom + r.height);
}
#pragma endregion ownDefinitions