#include "pch.h"
#include "Game.h"
#include<iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	const float offset{ 125 };
	Point2f Position{ g_WindowWidth / 2 - offset,g_WindowHeight / 2 - offset };
	CreateGrid(Position, g_Cells, g_Cols, g_Rows, g_CellSize);
	SetCurrentStates(g_Cells, g_AmountOfCells);
	TextureFromFile("Resources/Cog.png", g_Cog);
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	for (int i{}; i < g_AmountOfCells; ++i)
	{
		switch (g_Cells[i].state)
		{
		case RectState::empty:
			break;
		case RectState::noCog:
			DrawCell(g_Cells[i]);
			break;
		case RectState::cog:
			DrawCell(g_Cells[i]);
			DrawTexture(g_Cog, g_Cells[i].rect);
			break;
		}
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_LEFT] )
	//{
	//	std::cout << "Left arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
	DeleteTexture(g_Cog);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	bool isValidPos{};
	switch (key)
	{
	case SDLK_LEFT:
		isValidPos = CheckCellPositionX(g_SelectedIndex, g_SelectedIndex - 1);
		if (!isValidPos) break;
		g_SelectedCell.direction = utils::Direction::left;
		CheckAndMoveCell(g_SelectedIndex, g_SelectedIndex - 1);
		break;
	case SDLK_RIGHT:
		isValidPos = CheckCellPositionX(g_SelectedIndex, g_SelectedIndex + 1);
		if (!isValidPos) break;
		g_SelectedCell.direction = utils::Direction::right;
		CheckAndMoveCell(g_SelectedIndex, g_SelectedIndex + 1);
		break;
	case SDLK_DOWN:
		isValidPos = CheckCellPositionY(g_SelectedIndex, g_SelectedIndex - 5);
		if (!isValidPos) break;
		g_SelectedCell.direction = utils::Direction::down;
		CheckAndMoveCell(g_SelectedIndex, g_SelectedIndex - 5);
		break;
	case SDLK_UP:
		isValidPos = CheckCellPositionY(g_SelectedIndex, g_SelectedIndex + 5);
		if (!isValidPos) break;
		CheckCellPositionY(g_SelectedIndex, g_SelectedIndex + 5);
		g_SelectedCell.direction = utils::Direction::up;
		CheckAndMoveCell(g_SelectedIndex, g_SelectedIndex + 5);
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
	g_MousePos = Point2f{ float(e.x), float(g_WindowHeight - e.y) };
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
		for (int i{}; i < g_AmountOfCells; ++i)
		{
			const bool pointInRect{ IsPointInRect(g_MousePos, g_Cells[i].rect) };
			if (pointInRect && g_Cells[i].state != utils::RectState::empty) {
				g_SelectedCell = g_Cells[i];
				g_SelectedIndex = i;
			}
		}
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void SetCurrentStates(Cell* pCells, const int size)
{
	for (int i{}; i < size; ++i)
	{
		pCells[i].state = utils::RectState::noCog;
	}
	pCells[GetRandInt(0, size - 1)].state = utils::RectState::empty;

	for (int i{}; i < g_AmountOfCogs; ++i)
	{
		int rndInt{ GetRandInt(0, size - 1) };
		while (g_Cells[rndInt].state == utils::RectState::empty ||
			g_Cells[rndInt].state == utils::RectState::cog) {
			rndInt = GetRandInt(0, size - 1);
		}
		pCells[rndInt].state = utils::RectState::cog;
	}
}
void DrawCell(Cell pCell)
{
	const Color4f white{ 1,1,1,1 };
	const Color4f black{ 0,0,0,1 };
	SetColor(white);
	FillRect(pCell.rect);
	SetColor(black);
	DrawRect(pCell.rect);
}
bool CheckCellPositionX(int currentIndex, int secondIndex)
{
	if (currentIndex == 0 && (secondIndex < 0 || secondIndex > g_AmountOfCells - 1))
	{
		return false;
	}
	int row1{ GetRowIndex(currentIndex,g_Cols) };
	int row2{ GetRowIndex(secondIndex,g_Cols) };
	if (row1 != row2)
	{
		return false;
	}
	return true;
}
bool CheckCellPositionY(int currentIndex, int secondIndex)
{
	if (currentIndex == 0 && (secondIndex < 0 || secondIndex > g_AmountOfCells - 1))
	{
		return false;
	}
	int col1{ GetColIndex(currentIndex,g_Cols) };
	int col2{ GetColIndex(secondIndex,g_Cols) };
	if (col1 != col2)
	{
		return false;
	}

	return true;
}

void CheckAndMoveCell(int currentIndex, int secondIndex) {
	const Cell cell1{ g_Cells[currentIndex] };
	const Cell cell2{ g_Cells[secondIndex] };

	if (cell2.state != utils::RectState::empty)
	{
		return;
	}

	g_Cells[currentIndex].state = cell2.state;
	g_Cells[secondIndex].state = cell1.state;
	CheckStates();
}
void CheckStates()
{
	for (int i{}; i < g_Rows; ++i)
	{
		for (int j{}; j < g_Cols; ++j)
		{
			int index{ GetIndex(i,j,g_Cols) };
			bool result{ CheckNextCellX(index, index - 1, index) };
		}
	}
}

bool CheckNextCellX(int index, int previousIndex, int& changableIndex)
{
	bool isValidPos{ CheckCellPositionX(index,previousIndex) };
	if (!isValidPos)
	{
		return false;
	}

	const Cell cell1{ g_Cells[index] };
	const Cell cell2{ g_Cells[previousIndex] };
	if (cell1.state == cell2.state && cell1.state == RectState::cog)
	{
		changableIndex = previousIndex;
		return true;
	}
	return false;
}
#pragma endregion ownDefinitions