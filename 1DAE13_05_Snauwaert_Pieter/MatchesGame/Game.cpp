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
	DrawMatches();
	DrawMatchesPlayers();

}

void Update(float elapsedSec)
{
	if (g_Player == PlayerState::cpuPlayer)
	{
		UpdateAmounts();
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
	if (g_Amount > 0)
	{
		switch (key)
		{
		case SDLK_1:
			g_PlayerAmountIn = 1;
			UpdateAmounts();
			if (g_Amount > 0)
			{
				g_Player = PlayerState::cpuPlayer;
			}
			break;
		case SDLK_2:
			g_PlayerAmountIn = 2;
			UpdateAmounts();
			if (g_Amount > 0)
			{
				g_Player = PlayerState::cpuPlayer;
			}			break;
		case SDLK_3:
			g_PlayerAmountIn = 3;
			UpdateAmounts();
			if (g_Amount > 0)
			{
				g_Player = PlayerState::cpuPlayer;
			}			break;
		}
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
void DrawMatches()
{
	const float height{ 50.f };
	const float width{ 5.f };
	Point2f position{ 40.f,g_WindowHeight - (height+10.f) };
	float xOffSet{};
	for (int i{}; i < g_Amount; ++i)
	{
		SetColor(1, 0, 0);
		FillRect(position.x+xOffSet, position.y, width, height);
		SetColor(1, 1, 0);
		FillRect(position.x+xOffSet, position.y + height - height / 4, width, height / 4);
		xOffSet += width * 2;
	}
}
void DrawMatchesPlayers()
{
	const float height{ 50.f };
	const float width{ 5.f };
	Point2f position{ 40.f,40.f };
	float xOffSet{};
	for (int i{}; i < g_PlayerAmount; ++i)
	{
		SetColor(1, 0, 0);
		FillRect(position.x + xOffSet, position.y, width, height);
		SetColor(1, 1, 0);
		FillRect(position.x + xOffSet, position.y + height - height / 4, width, height / 4);
		xOffSet += width * 2;
	}
	xOffSet = 0;
	position.x = g_WindowWidth / 2;
	for (int i{}; i < g_CpuAmount; ++i)
	{
		SetColor(1, 0, 0);
		FillRect(position.x + xOffSet, position.y, width, height);
		SetColor(1, 1, 0);
		FillRect(position.x + xOffSet, position.y + height - height / 4, width, height / 4);
		xOffSet += width * 2;
	}
}
void UpdateAmounts()
{
	int cpuAmountIn{};
	switch (g_Player)
	{
	case PlayerState::player:
		g_PlayerAmountString += std::to_string(g_PlayerAmountIn) + " ";
		g_PlayerAmount += g_PlayerAmountIn;
		g_Amount -= g_PlayerAmountIn;
		g_PlayerAmountIn = 0;
		g_LastPlayer = PlayerState::cpuPlayer;
		break;
	case PlayerState::cpuPlayer:
		cpuAmountIn = GenerateRandomInt(1, 3);
		g_cpuAmountString += std::to_string(cpuAmountIn) + " ";
		g_CpuAmount += cpuAmountIn;
		g_Amount -= cpuAmountIn;
		g_Player = PlayerState::player;
		g_LastPlayer = PlayerState::player;
		break;
	}
	std::cout << g_Amount << std::endl;
	CheckWin();
}
void CheckWin()
{
	if (g_Amount <= 0)
	{
		std::cout << "Pc moves: " << g_cpuAmountString << std::endl;
		std::cout << "Your moves: " << g_PlayerAmountString << std::endl;
		switch (g_LastPlayer)
		{
		case PlayerState::player:
			std::cout << "You Won";
			break;
		case PlayerState::cpuPlayer:
			std::cout << "You lose";
			break;
		}

	}
}
int GenerateRandomInt(int min, int max)
{
	return (rand() % (int)max) + min;
}

#pragma endregion ownDefinitions