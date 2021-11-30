#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	for (int i{}; i < statsAmount; ++i)
	{
		TextureFromString(std::to_string(i + 1), "Resources/DIN-Light.otf", 15, yellow, statsText[i]);
	}
}

void Draw()
{
	ClearBackground(0, 0, 0);
	DrawClickedPoints();
	DrawRandStats();
}

void Update(float elapsedSec)
{
	UpdateRandStats();
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
	for (int i{}; i < statsAmount; ++i)
	{
		DeleteTexture(statsText[i]);
	}
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
	g_MousePos = Point2f{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		AddClickedPoint();
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawClickedPoints()
{
	if (currentIndexClickedPoints > 0)
	{
		SetColor(1, 1, 1, 1);
		DrawPolygon(clickedPoints, clickedPointsAmount, false);
		for (int i{}; i < clickedPointsAmount; ++i)
		{
			SetColor(1, 0, 0, 1);
			FillCircle(clickedPoints[i], 10);
		}
	}
}
void AddClickedPoint()
{
	clickedPoints[currentIndexClickedPoints] = g_MousePos;
	currentIndexClickedPoints++;
	if (currentIndexClickedPoints > clickedPointsAmount)
	{
		currentIndexClickedPoints = clickedPointsAmount;
		const int size{ sizeof(clickedPoints) / sizeof(Point2f)-1 };
		for (int i{}; i <= size; ++i)
		{
			clickedPoints[i] = clickedPoints[i + 1];
		}
	}
}
void UpdateRandStats()
{
	int randomNr{ GetRandInt(1,statsAmount) };
	switch (randomNr)
	{
	case 1:
		stats[0]++;
		break;
	case 2:
		stats[1]++;
		break;
	case 3:
		stats[2]++;
		break;
	case 4:
		stats[3]++;
		break;
	case 5:
		stats[4]++;
		break;
	case 6:
		stats[5]++;
		break;
	}
}
void DrawRandStats()
{
	Point2f position{ 0,g_WindowHeight - statsText[0].height - 10.f };
	for (int i{}; i < statsAmount; ++i)
	{
		DrawTexture(statsText[i], position);
		Point2f rectPos{ position.x + statsText[i].width + 10,position.y };
		SetColor(yellow);
		FillRect(rectPos, stats[i], statsText[i].height);
		SetColor(1, 1, 1, 1);
		DrawRect(rectPos, stats[i], statsText[i].height);
		position.y -= statsText[0].height + 10;
	}
}
#pragma endregion ownDefinitions