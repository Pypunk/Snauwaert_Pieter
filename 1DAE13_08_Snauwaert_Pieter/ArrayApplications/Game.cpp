#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	for (int i{}; i < g_StatsAmount; ++i)
	{
		TextureFromString(std::to_string(i + 1), "Resources/DIN-Light.otf", 15, g_Yellow, g_StatsText[i]);
	}
	InitialisePentagrams();
	const float cellSize{ 50.f };
	const int rows{ 3 };
	const int cols{ 4 };
	CreateGrid(g_Grid, cols, rows, cellSize);
}

void Draw()
{
	ClearBackground(0, 0, 0);

	
	DrawGrid();
	DrawClickedPoints();
	DrawRandStats();
	DrawMouseTrace();
	DrawPentagrams();
}

void Update(float elapsedSec)
{
	UpdateRandStats();
	UpdatePentagrams(elapsedSec);
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
	for (int i{}; i < g_StatsAmount; ++i)
	{
		DeleteTexture(g_StatsText[i]);
		DeleteTexture(g_StatsTextAmount[i]);
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
	AddMousePos();
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
		for (int i{}; i < g_CellsAmount; ++i)
		{
			if (IsPointInRect(g_MousePos, g_Grid[i]))
			{
				g_IsCellSelected[i] = !g_IsCellSelected[i];
				break;
			}
		}
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawClickedPoints()
{
	if (g_CurrentIndexClickedPoints > 0)
	{
		SetColor(1, 1, 1, 1);
		DrawPolygon(g_ClickedPoints, g_ClickedPointsAmount, false);
		for (int i{}; i < g_ClickedPointsAmount; ++i)
		{
			SetColor(1, 0, 0, 1);
			FillCircle(g_ClickedPoints[i], 10);
		}
	}
}
void AddClickedPoint()
{
	g_ClickedPoints[g_CurrentIndexClickedPoints] = g_MousePos;
	g_CurrentIndexClickedPoints++;
	if (g_CurrentIndexClickedPoints > g_ClickedPointsAmount)
	{
		g_CurrentIndexClickedPoints = g_ClickedPointsAmount;
		for (int i{}; i < g_ClickedPointsAmount; ++i)
		{
			g_ClickedPoints[i] = g_ClickedPoints[i+1];
		}
	}
}
void InitialisePentagrams()
{
	for (int i{ 0 }; i < g_AmountOfPentagrams; i++)
	{
		AngleSpeed pentagram{ 0, GetRandFloat(0.2f, 1.1f) };
		g_Pentagrams[i] = pentagram;
	}
}
void UpdatePentagrams(float elapsedSec)
{
	for (int i{ 0 }; i < 1; ++i)
	{
		g_Pentagrams[i].angle += g_Pentagrams[i].speed * elapsedSec;
	}
}
void DrawPentagrams()
{
	for (int i{ 0 }; i < 1; ++i)
	{
		DrawRotatingPentagram(g_PentagramCenter, g_PentaRadius, g_Pentagrams[i]);
	}
}
void AddMousePos()
{
	g_TracedPoints[g_CurrentIndexTracedPoints] = g_MousePos;
	g_CurrentIndexTracedPoints++;
	if (g_CurrentIndexTracedPoints > g_TraceAmount - 1)
	{
		g_CurrentIndexTracedPoints = g_TraceAmount - 1;
		for (int i{}; i < g_TraceAmount-1; ++i)
		{
			g_TracedPoints[i] = g_TracedPoints[i+1];
		}
	}
}
void DrawMouseTrace()
{
	const float radius{ 0 };
	const float maxRadius{ 20.f };
	const float radiusShift{ maxRadius / g_TraceAmount };
	const float transShift{ 1.f / g_TraceAmount };
	Color4f blueish{ 0.0f, 0.5f, 0.42f, 0.0f };
	const int size = sizeof(g_TracedPoints) / sizeof(Point2f);
	for (int i{}; i < size; ++i)
	{
		SetColor(blueish);
		blueish.a += transShift;
		FillCircle(g_TracedPoints[i], radius + (i * radiusShift));
	}
}
void UpdateRandStats()
{
	int randomNr{ GetRandInt(1,g_StatsAmount) };
	switch (randomNr)
	{
	case 1:
		g_Stats[0]++;
		DeleteTexture(g_StatsTextAmount[0]);
		TextureFromString(std::to_string(g_Stats[0]), "Resources/DIN-Light.otf", 15, g_Yellow, g_StatsTextAmount[0]);
		break;
	case 2:
		g_Stats[1]++;
		DeleteTexture(g_StatsTextAmount[1]);
		TextureFromString(std::to_string(g_Stats[1]), "Resources/DIN-Light.otf", 15, g_Yellow, g_StatsTextAmount[1]);
		break;
	case 3:
		g_Stats[2]++;
		DeleteTexture(g_StatsTextAmount[2]);
		TextureFromString(std::to_string(g_Stats[2]), "Resources/DIN-Light.otf", 15, g_Yellow, g_StatsTextAmount[2]);
		break;
	case 4:
		g_Stats[3]++;
		DeleteTexture(g_StatsTextAmount[3]);
		TextureFromString(std::to_string(g_Stats[3]), "Resources/DIN-Light.otf", 15, g_Yellow, g_StatsTextAmount[3]);
		break;
	case 5:
		g_Stats[4]++;
		DeleteTexture(g_StatsTextAmount[4]);
		TextureFromString(std::to_string(g_Stats[4]), "Resources/DIN-Light.otf", 15, g_Yellow, g_StatsTextAmount[4]);
		break;
	case 6:
		g_Stats[5]++;
		DeleteTexture(g_StatsTextAmount[5]);
		TextureFromString(std::to_string(g_Stats[5]), "Resources/DIN-Light.otf", 15, g_Yellow, g_StatsTextAmount[5]);
		break;
	}
}
void DrawRandStats()
{
	Point2f position{ 0,g_WindowHeight - g_StatsText[0].height - 10.f };
	const float offset{ 10.f };
	for (int i{}; i < g_StatsAmount; ++i)
	{
		DrawTexture(g_StatsText[i], position);
		DrawTexture(g_StatsTextAmount[i], Point2f{ float(position.x + g_StatsText[i].width+offset+g_Stats[i]),position.y });
		Point2f rectPos{ position.x + g_StatsText[i].width + offset,position.y };
		SetColor(g_Yellow);
		FillRect(rectPos, float(g_Stats[i]), g_StatsText[i].height);
		SetColor(1, 1, 1, 1);
		DrawRect(rectPos, float(g_Stats[i]), g_StatsText[i].height);
		position.y -= g_StatsText[0].height + offset;
	}
}
void DrawGrid()
{
	const int rows{ 3 };
	const int cols{ 4 };
	const float cellSize{ 50.f };
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			if (!g_IsCellSelected[GetIndex(i, j, cols)])
			{
				SetColor(0, 0, 0, 0);
				FillRect(g_Grid[GetIndex(i, j, cols)]);
				SetColor(1, 1, 1, 1);
				DrawRect(g_Grid[GetIndex(i, j, cols)]);
			}
			else
			{
				SetColor(g_Yellow);
				FillRect(g_Grid[GetIndex(i, j, cols)]);
				SetColor(1, 1, 1, 1);
				DrawRect(g_Grid[GetIndex(i, j, cols)]);
			}
		}
	}
}
#pragma endregion ownDefinitions