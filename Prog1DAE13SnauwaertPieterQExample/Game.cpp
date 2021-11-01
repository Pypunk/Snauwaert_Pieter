#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	Generate();
	PrintRandomNumbers();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawElevator();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_TotalTime += elapsedSec;
	if (1 <= g_TotalTime)
	{
		Generate();
		PrintRandomNumbers();
		g_TotalTime = 0;
	}
	UpdateElevator(elapsedSec);
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

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_n:
		Generate();
		PrintRandomNumbers();
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	g_MousePos = Point2f{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (IsPointInBorder(g_MousePos, g_ElevatorRect))
		{
			switch (g_CurrentState)
			{
			case elevatorState::moving:
				g_CurrentState = elevatorState::stationary;
				break;
			case elevatorState::stationary:
				g_CurrentState = elevatorState::moving;
				break;
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
void Generate()
{
	g_Even = rand() % 10;
	if (g_Even % 2)
	{
		g_Even++;
		if (g_Even > 9)
		{
			g_Even -= 2;
		}
	}
	g_Odd = rand() % 10;
	if (!(g_Odd % 2))
	{
		g_Odd++;
	}
	g_Any = rand() % 10;
}
void PrintRandomNumbers()
{
	std::cout << "Even: " << g_Even << ", odd: " << g_Odd << ", any: " << g_Any << std::endl;
}
void DrawElevator()
{
	SetColor(0,0,1);
	FillRect(g_ElevatorRect);
	SetColor(g_Color);
	FillRect(Rectf{ g_ElevatorRect.left + g_PixelSize,g_ElevatorRect.bottom + g_PixelSize,g_ElevatorRect.width - g_PixelSize*2,g_ElevatorRect.height - g_PixelSize*2 });
}
void UpdateElevator(float elapsedSec)
{
	if (g_CurrentState == elevatorState::moving)
	{
		g_ElevatorRect.bottom += g_Speed * elapsedSec;
		if (g_Speed < 0)
		{
			g_Color = Color4f{ 0,1,0,1 };
		}
		else if (g_Speed > 0)
		{
			g_Color = Color4f{ 1,0,0,1 };
		}
		if (g_ElevatorRect.bottom + g_ElevatorRect.height > g_WindowHeight - g_Border || g_ElevatorRect.bottom < g_Border)
		{
			g_Speed = -g_Speed;
		}
	}
	else
	{
		g_Color = Color4f{ 0,0,0,0.5f };
	}
}
bool IsPointInBorder(const Point2f p, const Rectf r)
{
	return (p.x <= r.left + g_PixelSize && p.x >= r.left && p.y <= r.bottom + r.height && p.y >= r.bottom)
		|| (p.x >= r.left + r.width - g_PixelSize && p.x <= r.left + r.width && p.y <= r.bottom + r.height && p.y >= r.bottom)
		|| (p.x >= r.left && p.x <= r.left + r.width && p.y <= r.bottom + g_PixelSize && p.y >= r.bottom)
		|| (p.x >= r.left && p.x <= r.left + r.width && p.y >= r.bottom + r.height - g_PixelSize && p.y <= r.bottom + r.height);
}
#pragma endregion ownDefinitions