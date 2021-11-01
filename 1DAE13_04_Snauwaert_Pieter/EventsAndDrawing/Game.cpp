#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateRectangle();
	CreateLine();
}

void Draw()
{
	ClearBackground(0.f,0.5f,1.f);
	// Put your own draw statements here
	DrawRectangle();
	DrawMovingLine();
}

void Update(float elapsedSec)
{
	switch (g_CurrentRectState)
	{
	case RectState::running:
		UpdateRectangle();
		break;
	}
	UpdateLine();
	// process input, do physics 
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
	switch (key)
	{
	case SDLK_r:
		switch (g_CurrentRectState)
		{
		case RectState::stationary:
			g_CurrentRectState = RectState::running;
			break;
		case RectState::running:
			g_CurrentRectState = RectState::stationary;
			break;
		}
		break;
	case SDLK_l:
		switch (g_CurrentLineState)
		{
		case LineState::moving:
			g_CurrentLineState = LineState::stationary;
			break;
		case LineState::stationary:
			g_CurrentLineState = LineState::moving;
			break;
		}
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
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (IsPointInRect(g_MousePos, g_Rect) || IsPointInRect(g_MousePos,g_NewRect))
		{
			if (g_Clicked)
			{
				g_Clicked = false;
				CreateRectangle();
			}
			else
			{
				g_Clicked = true;
			}
		}
		break;
	}
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
void CreateRectangle()
{
	const float border{ 50 };
	const float minWidth{ 60 };
	const float minHeight{ 40 };
	const float minX{ border };
	const float maxX{ g_WindowWidth - minWidth - border };
	const float minY{ border };
	const float maxY{ g_WindowHeight - minHeight - border };
	const float randLeft{ GenerateRandomFloat(minX, maxX - minX) };
	const float randBottom{ GenerateRandomFloat(minY, maxY - minY) };
	const float maxWidth{ maxX - randLeft };
	const float maxHeight{ maxY - randBottom };
	const float randWidth{ GenerateRandomFloat(minWidth, maxWidth) };
	const float randHeight{ GenerateRandomFloat(minHeight, maxHeight) };
	g_Rect = Rectf{ randLeft, randBottom, randWidth, randHeight };
	g_NewRect.width = 0.f;
	g_NewRect.height = g_Rect.height;
	g_NewRect.bottom = g_Rect.bottom;
}
void CreateLine()
{
	const float border{ 50 };
	g_StartPoint.x = GenerateRandomFloat(0, g_WindowWidth);
	g_EndPoint.x = GenerateRandomFloat(0, g_WindowWidth);
	g_StartPoint.y = GenerateRandomFloat(0, g_WindowHeight);
	g_EndPoint.y = GenerateRandomFloat(0, g_WindowHeight);
	g_StartPointSpeed = Point2f{ GenerateRandomFloat(1,2),GenerateRandomFloat(1,2) };
	g_EndPointSpeed = Point2f{ GenerateRandomFloat(1,2),GenerateRandomFloat(1,2) };
}
void UpdateRectangle()
{
	g_Rect.left = float(int(g_Rect.left + 1) % int(g_WindowWidth));
	if (g_Rect.left + g_Rect.width >= g_WindowWidth)
	{
		g_NewRect.width++;
	}
	else
	{
		g_NewRect.width = 0;
	}
}
void UpdateLine()
{
	if (g_CurrentLineState == LineState::moving)
	{
		g_EndPoint.x += g_EndPointSpeed.x;
		g_EndPoint.y += g_EndPointSpeed.y;
		g_StartPoint.x += g_StartPointSpeed.x;
		g_StartPoint.y += g_StartPointSpeed.y;
		if (g_EndPoint.x <= 0 || g_WindowWidth <= g_EndPoint.x)
		{
			g_EndPointSpeed.x *= -1;
		}
		if (g_EndPoint.y <= 0 || g_WindowHeight <= g_EndPoint.y)
		{
			g_EndPointSpeed.y *= -1;
		}
		if (g_StartPoint.x <= 0 || g_WindowWidth <= g_StartPoint.x)
		{
			g_StartPointSpeed.x *= -1;
		}
		if (g_StartPoint.y <= 0 || g_WindowHeight <= g_StartPoint.y)
		{
			g_StartPointSpeed.y *= -1;
		}
	}
}
void DrawMovingLine()
{
	SetColor(1, 1, 1);
	DrawLine(g_StartPoint, g_EndPoint);
}
void DrawRectangle()
{
	if (g_Clicked)
	{
		g_Color = Color4f{ 0,1,0,0.8f };
	}
	else
	{
		g_Color = Color4f{ 0,0,0,0.8f };
	}
	SetColor(g_Color);
	FillRect(g_Rect);
	FillRect(g_NewRect);
}
bool IsPointInRect(const Point2f& p, const Rectf& r)
{
	return (p.x >= r.left && p.x <= r.left + r.width &&
		p.y >= r.bottom && p.y <= r.bottom + r.height);
}
float GenerateRandomFloat(float min, float max)
{
	return float((rand() % (int)max) + min);
}
#pragma endregion ownDefinitions