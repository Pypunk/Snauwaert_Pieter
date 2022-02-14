#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateTextures();
	for (int i{}; i < 2; ++i)
	{
		g_PlayerState[0] = State::GreenO;
	}
}

void Draw()
{
	ClearBackground();
	Rectf destRectBackGround{ 0,0,g_WindowWidth,g_WindowHeight };
	// Put your own draw statements here
	DrawTexture(g_BackGround, destRectBackGround);
	DrawGrid();
	Rectf bottomRect{ 10,10,g_OXOTexture[0].width,g_OXOTexture[0].height };
	for (int i{}; i < 2; ++i)
	{
		DrawAccordingToState(g_PlayerState[i], bottomRect);
		bottomRect.left = g_WindowWidth - bottomRect.width - 10.f;
	}
}

void Update(float elapsedSec)
{
	// process input, do physics
	if (CheckDiagonal() || CheckVertical() || CheckHorizontal())
	{
		if (g_Player1)
		{
			g_PlayerState[1] = State::win;
			g_PlayerState[0] = State::empty;
		}
		else
		{
			g_PlayerState[0] = State::win;
			g_PlayerState[1] = State::empty;
		}
		g_GameEnd = true;
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
	DeleteTexture(g_BackGround);
	for (int i{}; i < g_TextureAmount; ++i)
	{
		DeleteTexture(g_OXOTexture[i]);
	}
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	if (!g_GameEnd)
	{
		switch (key)
		{
		case SDLK_a:
			if (g_Player1)
			{
				g_PlayerState[1] = State::empty;
				g_PlayerState[0] = State::GreenO;
			}
			else
			{
				g_PlayerState[0] = State::empty;
				g_PlayerState[1] = State::GreenO;
			}
			g_IsX = false;
			break;
		case SDLK_l:
			if (g_Player1)
			{
				g_PlayerState[1] = State::empty;
				g_PlayerState[0] = State::GreenX;
			}
			else
			{
				g_PlayerState[0] = State::empty;
				g_PlayerState[1] = State::GreenX;
			}
			g_IsX = true;
			break;
		}
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	g_MousePos = Point2f{ float(e.x), float(g_WindowHeight - e.y) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	if (!g_GameEnd)
	{
		switch (e.button)
		{
		case SDL_BUTTON_LEFT:
		{
			ToggleGrid();
			TogglePlayerState();
			break;
		}
		}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void CreateTextures()
{
	TextureFromFile("Resources/OXO.png", g_BackGround);
	TextureFromFile("Resources/WhiteO.png", g_OXOTexture[0]);
	TextureFromFile("Resources/WhiteX.png", g_OXOTexture[1]);
	TextureFromFile("Resources/GreenO.png", g_OXOTexture[2]);
	TextureFromFile("Resources/GreenX.png", g_OXOTexture[3]);
	TextureFromFile("Resources/FreeCell.png", g_OXOTexture[4]);
	TextureFromFile("Resources/Win.png", g_OXOTexture[5]);
}
void DrawGrid()
{
	Point2f position{ g_WindowWidth / 2 - (g_OXOTexture[4].width / 2 + g_OXOTexture[4].width) ,g_WindowHeight / 2 - (g_OXOTexture[4].height / 2 + g_OXOTexture[4].height) };
	for (int i{}; i < g_Rows; ++i)
	{
		for (int j{}; j < g_Cols; ++j)
		{
			g_GriddCellsDestRect[GetIndex(i, j, g_Cols)] = Rectf{ position.x,position.y,g_OXOTexture[0].width,g_OXOTexture[0].height };
			DrawAccordingToState(g_GridState[GetIndex(i, j, g_Cols)], g_GriddCellsDestRect[GetIndex(i, j, g_Cols)]);
			position.x += g_GriddCellsDestRect[0].width + 5;
		}
		position.x = g_WindowWidth / 2 - (g_OXOTexture[4].width / 2 + g_OXOTexture[4].width);
		position.y += g_GriddCellsDestRect[0].height + 5;
	}
}
void ToggleGrid()
{
	for (int i{}; i < g_Rows * g_Cols; ++i)
	{
		if (IsPointInRect(g_MousePos, g_GriddCellsDestRect[i]) && g_IsX && g_GridState[i] == State::empty)
		{
			g_GridState[i] = State::WhiteX;
			if (g_PlayerState[0] != State::win && g_PlayerState[1] != State::win)
			{
				g_Player1 = !g_Player1;
			}
		}
		else if (IsPointInRect(g_MousePos, g_GriddCellsDestRect[i]) && !g_IsX && g_GridState[i] == State::empty)
		{
			g_GridState[i] = State::WhiteO;
			if (g_PlayerState[0] != State::win && g_PlayerState[1] != State::win)
			{
				g_Player1 = !g_Player1;
			}
		}
	}
}
void TogglePlayerState()
{
	if (g_Player1 && g_IsX)
	{
		g_PlayerState[1] = State::empty;
		g_PlayerState[0] = State::GreenX;
	}
	else if (!g_Player1 && g_IsX)
	{
		g_PlayerState[0] = State::empty;
		g_PlayerState[1] = State::GreenX;
	}
	else if (g_Player1 && !g_IsX)
	{
		g_PlayerState[1] = State::empty;
		g_PlayerState[0] = State::GreenO;
	}
	else if (!g_Player1 && !g_IsX)
	{
		g_PlayerState[0] = State::empty;
		g_PlayerState[1] = State::GreenO;
	}
}
void DrawAccordingToState(const State& currentState, const Rectf& destRect)
{
	switch (currentState)
	{
	case State::WhiteO:
		DrawTexture(g_OXOTexture[0], destRect);
		break;
	case State::WhiteX:
		DrawTexture(g_OXOTexture[1], destRect);
		break;
	case State::GreenO:
		DrawTexture(g_OXOTexture[2], destRect);
		break;
	case State::GreenX:
		DrawTexture(g_OXOTexture[3], destRect);
		break;
	case State::win:
		DrawTexture(g_OXOTexture[5], destRect);
		break;
	case State::empty:
		DrawTexture(g_OXOTexture[4], destRect);
		break;
	}
}
bool CheckHorizontal()
{
	for (int i{}; i < g_Rows; ++i)
	{
		for (int j{}; j < g_Cols; ++j)
		{
			if (g_GridState[GetIndex(i, j, g_Cols)] == State::WhiteO
				&& g_GridState[GetIndex(i, j + 1, g_Cols)] == State::WhiteX
				&& g_GridState[GetIndex(i, j + 2, g_Cols)] == State::WhiteO)
			{
				g_GridState[GetIndex(i, j, g_Cols)] = State::GreenO;
				g_GridState[GetIndex(i, j + 1, g_Cols)] = State::GreenX;
				g_GridState[GetIndex(i, j + 2, g_Cols)] = State::GreenO;
				return true;
			}
		}
	}
	return false;
}
bool CheckVertical()
{
	for (int i{}; i < g_Rows; ++i)
	{
		for (int j{}; j < g_Cols; ++j)
		{
			if (g_GridState[GetIndex(i, j, g_Cols)] == State::WhiteO
				&& g_GridState[GetIndex(i + 1, j, g_Cols)] == State::WhiteX
				&& g_GridState[GetIndex(i + 2, j, g_Cols)] == State::WhiteO)
			{
				g_GridState[GetIndex(i, j, g_Cols)] = State::GreenO;
				g_GridState[GetIndex(i + 1, j, g_Cols)] = State::GreenX;
				g_GridState[GetIndex(i + 2, j, g_Cols)] = State::GreenO;
				return true;
			}
		}
	}
	return false;
}
bool CheckDiagonal()
{
	for (int i{}; i < g_Rows; ++i)
	{
		for (int j{}; j < g_Cols; ++j)
		{
			if (g_GridState[GetIndex(i, j, g_Cols)] == State::WhiteO
				&& g_GridState[GetIndex(i + 1, j + 1, g_Cols)] == State::WhiteX
				&& g_GridState[GetIndex(i + 2, j + 2, g_Cols)] == State::WhiteO)
			{
				{
					g_GridState[GetIndex(i, j, g_Cols)] = State::GreenO;
					g_GridState[GetIndex(i + 1, j + 1, g_Cols)] = State::GreenX;
					g_GridState[GetIndex(i + 2, j + 2, g_Cols)] = State::GreenO;
					return true;
				}
			}
		}
	}
	for (int i{}; i < g_Rows; ++i)
	{
		for (int j{}; j < g_Cols; ++j)
		{
			if (g_GridState[GetIndex(i + 2, j, g_Cols)] == State::WhiteO
				&& g_GridState[GetIndex(i + 1, j + 1, g_Cols)] == State::WhiteX
				&& g_GridState[GetIndex(i, j + 2, g_Cols)] == State::WhiteO)
			{
				{
					g_GridState[GetIndex(i+2, j, g_Cols)] = State::GreenO;
					g_GridState[GetIndex(i + 1, j + 1, g_Cols)] = State::GreenX;
					g_GridState[GetIndex(i, j + 2, g_Cols)] = State::GreenO;
					return true;
				}
			}
		}
	}
	return false;
}
#pragma endregion ownDefinitions