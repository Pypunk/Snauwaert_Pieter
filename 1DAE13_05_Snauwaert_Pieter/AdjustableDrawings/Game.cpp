#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0,0,0);

	// Put your own draw statements here
	DrawSquares();
	DrawSteps();
	DrawSpiral();
	DrawSpinningLines();
}

void Update(float elapsedSec)
{
	const int max{ 20 };
	const int min{ 5 };
	if (g_Amount > max)
	{
		g_Amount = 5;
	}
	if (g_Amount < min)
	{
		g_Amount = 20;
	}
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
	case SDLK_UP:
		g_Amount++;
		std::cout << g_Amount << std::endl;
		break;
	case SDLK_DOWN:
		g_Amount--;
		std::cout << g_Amount << std::endl;
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
void DrawSquares()
{
	float newWidth{200.f};
	const float width{newWidth};
	Point2f position{25.f,25.f};
	for (int i{}; i < g_Amount; ++i)
	{
		SetColor(0, 1, 0);
		Rectf rect{ position.x,position.y,newWidth,newWidth };
		position.x += width/g_Amount/2;
		position.y += width/g_Amount/2;
		newWidth -= width/g_Amount;
		DrawRect(rect);
	}
}
void DrawSteps()
{
	Point2f position{25.f,g_WindowHeight/2};
	float width{ 200.f };
	for (int i{}; i < g_Amount; ++i)
	{
		if (!(i % 2))
		{
			SetColor(1,0,0);
		}
		else
		{
			SetColor(0, 0, 1);
		}
		DrawLine(position.x, position.y, position.x + width / g_Amount, position.y,2.f);
		DrawLine(position.x + width / g_Amount, position.y, position.x + width / g_Amount, position.y + width / g_Amount,2.f);
		position.x += width / g_Amount;
		position.y += width / g_Amount;
	}
}
void DrawSpiral()
{
	float newWidth{ 200.f };
	const float width{ newWidth };
	Point2f position{ g_WindowWidth/2+25.f,25.f };
	for (int i{}; i < g_Amount; ++i)
	{
		SetColor(0, 0, 1);
		DrawLine(position.x, position.y, position.x+newWidth, position.y);
		DrawLine(position.x + newWidth, position.y, position.x + newWidth, position.y + newWidth);
		DrawLine(position.x + newWidth, position.y + newWidth, position.x + width / g_Amount/2, position.y + newWidth);
		DrawLine(position.x + width / g_Amount/2, position.y + newWidth, position.x + width / g_Amount/2, position.y + width / g_Amount/2);
		position.x += width / g_Amount / 2;
		position.y += width / g_Amount / 2;
		newWidth -= width / g_Amount;
	}
}
void DrawSpinningLines()
{
	float newWidth{ 200.f };
	Point2f position{ g_WindowWidth / 2 + 25.f,g_WindowHeight / 2 + 25.f };
	for (int i{}; i < g_Amount; ++i)
	{
		SetColor(1, 0, 0);
		DrawLine(position.x + newWidth / g_Amount * i, position.y, position.x + newWidth, position.y + newWidth / g_Amount * i);
		SetColor(0, 1, 0);
		DrawLine(position.x + newWidth, position.y + newWidth / g_Amount * i, position.x + newWidth - newWidth / g_Amount * i, position.y + newWidth);
		SetColor(0, 0, 1);
		DrawLine(position.x + newWidth-newWidth/g_Amount*i, position.y + newWidth, position.x, position.y+newWidth-newWidth/g_Amount*i);
		SetColor(1, 1, 0);
		DrawLine(position.x, position.y + newWidth - newWidth / g_Amount * i, position.x + newWidth / g_Amount * i, position.y);
	}
}
#pragma endregion ownDefinitions