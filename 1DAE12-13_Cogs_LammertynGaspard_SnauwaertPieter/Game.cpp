#include "pch.h"
#include "Game.h"
#include<iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	const float offset{ 250 };
	Point2f Position{ g_WindowWidth / 2 - offset,g_WindowHeight / 2 - offset };
	CreateGrid(Position, g_Cells, g_Cols, g_Rows, g_CellSize);
	SetCurrentStates(g_Cells, g_AmountOfCells);
	InitStartAndEndSprite();
	InitWinText();
}

void Draw()
{
	//Color brown
	ClearBackground(70 / 255.f, 47 / 255.f, 34 / 255.f);

	// Put your own draw statements here
	DrawCells();

	if (g_IsFinished) {
		DrawOuterCogsSprites();
		DrawWinText();
	}
	else
	{
		DrawStaticStartAndEndCog();
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 

	if (g_IsFinished) {
		UpdateStartAndEndSprite(elapsedSec);
		UpdateInnerCogsSprite(elapsedSec);
	}

}

void End()
{
	// free game resources here
	DeleteTexture(g_Cog);
	DeleteTexture(g_StartEndCogSprite.texture);
	DeleteTexture(g_InnerCogSprite.texture);
	DeleteTexture(g_WinText);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	if (g_IsFinished)
	{
		return;
	}

	bool isValidPos{};
	switch (key)
	{
	case SDLK_LEFT:
		isValidPos = CheckCellPositionX(g_SelectedIndex, g_SelectedIndex - 1);
		if (!isValidPos) break;
		g_SelectedCell.direction = Direction::left;
		CheckAndMoveCell(g_SelectedIndex, g_SelectedIndex - 1);
		break;
	case SDLK_RIGHT:
		isValidPos = CheckCellPositionX(g_SelectedIndex, g_SelectedIndex + 1);
		if (!isValidPos) break;
		g_SelectedCell.direction = Direction::right;
		CheckAndMoveCell(g_SelectedIndex, g_SelectedIndex + 1);
		break;
	case SDLK_DOWN:
		isValidPos = CheckCellPositionY(g_SelectedIndex, g_SelectedIndex - 5);
		if (!isValidPos) break;
		g_SelectedCell.direction = Direction::down;
		CheckAndMoveCell(g_SelectedIndex, g_SelectedIndex - 5);
		break;
	case SDLK_UP:
		isValidPos = CheckCellPositionY(g_SelectedIndex, g_SelectedIndex + 5);
		if (!isValidPos) break;
		CheckCellPositionY(g_SelectedIndex, g_SelectedIndex + 5);
		g_SelectedCell.direction = Direction::up;
		CheckAndMoveCell(g_SelectedIndex, g_SelectedIndex + 5);
		break;
	case SDLK_i:
		PrintInformation();
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
	if (g_IsFinished)
	{
		return;
	}
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		for (int i{}; i < g_AmountOfCells; ++i)
		{
			const bool pointInRect{ IsPointInRect(g_MousePos, g_Cells[i].rect) };
			if (pointInRect && g_Cells[i].state != RectState::empty) {
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
		pCells[i].state = RectState::noCog;
	}
	pCells[GetRandInt(0, size - 1)].state = RectState::empty;

	for (int i{}; i < g_AmountOfCogs; ++i)
	{
		int rndInt{ GetRandInt(0, size - 1) };
		while (g_Cells[rndInt].state == RectState::empty ||
			g_Cells[rndInt].state == RectState::cog) {
			rndInt = GetRandInt(0, size - 1);
		}
		pCells[rndInt].state = RectState::cog;
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

	if (cell2.state != RectState::empty)
	{
		return;
	}

	g_Cells[currentIndex].state = cell2.state;
	g_Cells[secondIndex].state = cell1.state;
	CheckStates();
}
void CheckStates()
{
	int cogsIndexes[g_AmountOfCogs]{};
	int connectedCogsIndexes[g_AmountOfCogs]{};
	int currentValidCogs{};
	FilterOutCogs(cogsIndexes, connectedCogsIndexes, currentValidCogs);

	UnCheckAllCells();

	int currentConnectedCogs{ ReturnCurrentCogsAmount() };

	UnCheckAllCells();

	if (currentConnectedCogs >= g_AmountOfCells - 1) {
		if (g_Cells[0].state == utils::RectState::cog && g_Cells[g_AmountOfCells - 1].state == utils::RectState::cog)
		{
			SetInnerCogsMovement();
			g_IsFinished = true;
		}
	}
}

void UnCheckAllCells()
{
	for (int i{}; i < g_AmountOfCells; ++i) {
		if (g_Cells[i].checked) {
			g_Cells[i].checked = false;
		}
	}
}


void FilterOutCogs(int* cogsIndexes, int* connectedCogsIndexes, int& currentValidCogs)
{
	int currentIndex{};
	for (int i{}; i < g_AmountOfCells; ++i)
	{
		const Cell currentCell{ g_Cells[i] };
		if (currentCell.state == utils::RectState::cog)
		{
			cogsIndexes[currentIndex] = i;
			++currentIndex;
		}
	}

	for (int i{}; i < g_AmountOfCogs; ++i) {
		bool isNotValid{ IsNotConnected(cogsIndexes[i]) };
		if (!isNotValid) {
			connectedCogsIndexes[i] = cogsIndexes[i];
			++currentValidCogs;
		}
	}
}

int ReturnCurrentCogsAmount()
{
	int currentCheckIndex{ 0 };
	Cell cellToCheck{ g_Cells[0] };
	for (int i{}; i < g_AmountOfCogs; ++i)
	{
		bool resultXRight{ CheckNextCellX(currentCheckIndex, currentCheckIndex + 1) };
		bool resultYUp{ CheckNextCellY(currentCheckIndex,currentCheckIndex + 5) };
		if (resultXRight)
		{
			currentCheckIndex++;
			cellToCheck = g_Cells[currentCheckIndex];
		}
		if (resultYUp)
		{
			currentCheckIndex += 5;
			cellToCheck = g_Cells[currentCheckIndex];
		}
	}
	return currentCheckIndex;
}

void PrintInformation()
{
	std::cout << "--- Cogs ---\n\n";
	std::cout << "In the middle of the screen, you have a grid. It's randomly filled with cogs.\n";
	std::cout << "Connect the cogs from the bottom left to the top right corner.\n";
	std::cout << "You can do this by moving cells to the only empty spot.\n\n";
	std::cout << "--- Controls ---\n\n";
	std::cout << "Click on a cell to select it.\n";
	std::cout << "Press the Arrow keys to move the selected cell.\n\n";
	std::cout << "Made by Gaspard Lammertyn and Pieter Snauwaert.\n";
}

bool IsNotConnected(int index) {


	bool resultXLeft{ CheckNextCellX(index, index - 1) };
	bool resultXRight{ CheckNextCellX(index, index + 1) };
	bool resultYUp{ CheckNextCellY(index,index + 5) };
	bool resultYDown{ CheckNextCellY(index,index - 5) };


	bool result{ !resultXLeft && !resultXRight && !resultYUp && !resultYDown };
	return result;
}

bool CheckNextCellX(int index, int previousIndex)
{
	bool isValidPos{ CheckCellPositionX(index,previousIndex) };
	if (!isValidPos)
	{
		return false;
	}

	const Cell cell1{ g_Cells[index] };
	const Cell cell2{ g_Cells[previousIndex] };

	if (cell1.checked)
	{
		return false;
	}

	if (cell1.state == cell2.state && cell1.state == RectState::cog)
	{
		g_Cells[index].checked = true;
		return true;
	}
	return false;
}
bool CheckNextCellY(int index, int previousIndex)
{
	bool isValidPos{ CheckCellPositionY(index,previousIndex) };
	if (!isValidPos)
	{
		return false;
	}
	const Cell cell1{ g_Cells[index] };
	const Cell cell2{ g_Cells[previousIndex] };

	if (cell1.checked)
	{
		return false;
	}

	if (cell1.state == cell2.state && cell1.state == RectState::cog)
	{
		g_Cells[index].checked = true;
		return true;
	}
	return false;
}

void InitStartAndEndSprite()
{
	bool isCogCreated{ TextureFromFile("Resources/Cog.png", g_Cog) };
	bool isStartAndEndCreated{ TextureFromFile("Resources/SilverCog.png", g_StartTexture) };
	bool isStartAndEndSpriteCreated{ TextureFromFile("Resources/CogAnimSilver.png", g_StartEndCogSprite.texture) };
	bool isInnerCogSpriteCreated{ TextureFromFile("Resources/CogAnim.png", g_InnerCogSprite.texture) };

	if (!isCogCreated) std::cout << "Texture Cog.png could not be loaded\n";

	if (!isStartAndEndCreated) std::cout << "Texture SilverCog.png could not be loaded\n";

	if (!isStartAndEndSpriteCreated) std::cout << "Texture CogAnimSilver.png could not be loaded\n";

	if (!isInnerCogSpriteCreated) std::cout << "Texture CogAnim.png could not be loaded\n";

	SetSpriteProperties();
}

void UpdateStartAndEndSprite(float elapsedSec) {
	g_StartEndCogSprite.accumulatedTime += elapsedSec;

	if (g_StartEndCogSprite.accumulatedTime >= elapsedSec)
	{
		++g_StartEndCogSprite.currentFrame %= g_StartEndCogSprite.frames;
		g_StartEndCogSprite.accumulatedTime -= g_StartEndCogSprite.frameTime;
	}
}

void UpdateInnerCogsSprite(float elapsedSec) {
	g_InnerCogSprite.accumulatedTime += elapsedSec;

	if (g_InnerCogSprite.accumulatedTime >= elapsedSec)
	{
		++g_InnerCogSprite.currentFrame %= g_InnerCogSprite.frames;
		g_InnerCogSprite.accumulatedTime -= g_InnerCogSprite.frameTime;
	}
}

void DrawStaticStartAndEndCog()
{
	Rectf destRect{};
	destRect = g_Cells[0].rect;
	destRect.left -= g_Cells[0].rect.width;
	DrawTexture(g_StartTexture, destRect);
	destRect = g_Cells[g_AmountOfCells - 1].rect;
	destRect.left += g_Cells[g_AmountOfCells - 1].rect.width;
	DrawTexture(g_StartTexture, destRect);
}

void DrawInnerCogSprite(const Cell& cell)
{
	Rectf srcRect{};
	const int row{ g_InnerCogSprite.currentFrame / g_InnerCogSprite.cols };
	srcRect.width = g_InnerCogSprite.texture.width / g_InnerCogSprite.cols;
	srcRect.height = float(g_InnerCogSprite.texture.height / (g_InnerCogSprite.frames / g_InnerCogSprite.cols));
	srcRect.left = float(g_InnerCogSprite.currentFrame % g_InnerCogSprite.cols) * srcRect.width;
	srcRect.bottom = float(row + 1) * srcRect.height;

	Rectf destRect{};
	destRect = cell.rect;
	DrawTexture(g_InnerCogSprite.texture, destRect, srcRect);
}

void DrawInnerCogSpriteReverse(const Cell& cell)
{
	Rectf srcRect{};
	const int row{ (g_StartEndCogSprite.frames - 1 - g_StartEndCogSprite.currentFrame) / g_StartEndCogSprite.cols };
	srcRect.width = g_StartEndCogSprite.texture.width / g_StartEndCogSprite.cols;
	srcRect.height = float(g_StartEndCogSprite.texture.height / (g_StartEndCogSprite.frames / g_StartEndCogSprite.cols));
	srcRect.left = float(g_StartEndCogSprite.currentFrame % g_StartEndCogSprite.cols) * srcRect.width;
	srcRect.bottom = float(row + 1) * srcRect.height;

	Rectf destRect{};
	destRect = cell.rect;
	DrawTexture(g_InnerCogSprite.texture, destRect, srcRect);
}

void DrawStartSprite()
{
	Rectf srcRect{};
	const int row{ g_StartEndCogSprite.currentFrame / g_StartEndCogSprite.cols };
	srcRect.width = g_StartEndCogSprite.texture.width / g_StartEndCogSprite.cols;
	srcRect.height = float(g_StartEndCogSprite.texture.height / (g_StartEndCogSprite.frames / g_StartEndCogSprite.cols));
	srcRect.left = float(g_StartEndCogSprite.currentFrame % g_StartEndCogSprite.cols) * srcRect.width;
	srcRect.bottom = float(row + 1) * srcRect.height;

	Rectf destRect{};
	destRect = g_Cells[0].rect;
	destRect.left -= g_Cells[0].rect.width;
	DrawTexture(g_StartEndCogSprite.texture, destRect, srcRect);
}

void DrawEndSprite()
{
	Rectf srcRect{};
	const int row{ g_StartEndCogSprite.currentFrame / g_StartEndCogSprite.cols };
	srcRect.width = g_StartEndCogSprite.texture.width / g_StartEndCogSprite.cols;
	srcRect.height = float(g_StartEndCogSprite.texture.height / (g_StartEndCogSprite.frames / g_StartEndCogSprite.cols));
	srcRect.left = float(g_StartEndCogSprite.currentFrame % g_StartEndCogSprite.cols) * srcRect.width;
	srcRect.bottom = float(row + 1) * srcRect.height;

	Rectf destRect{};
	destRect = g_Cells[g_AmountOfCells - 1].rect;
	destRect.left += g_Cells[g_AmountOfCells - 1].rect.width;
	DrawTexture(g_StartEndCogSprite.texture, destRect, srcRect);
}

void DrawStartSpriteReverse()
{
	Rectf srcRect{};
	const int row{ (g_StartEndCogSprite.frames - 1 - g_StartEndCogSprite.currentFrame) / g_StartEndCogSprite.cols };
	srcRect.width = g_StartEndCogSprite.texture.width / g_StartEndCogSprite.cols;
	srcRect.height = float(g_StartEndCogSprite.texture.height / (g_StartEndCogSprite.frames / g_StartEndCogSprite.cols));
	srcRect.left = float(g_StartEndCogSprite.currentFrame % g_StartEndCogSprite.cols) * srcRect.width;
	srcRect.bottom = float(row + 1) * srcRect.height;

	Rectf destRect{};
	destRect = g_Cells[0].rect;
	destRect.left -= g_Cells[0].rect.width;
	DrawTexture(g_StartEndCogSprite.texture, destRect, srcRect);
}

void DrawEndSpriteReverse()
{
	Rectf srcRect{};
	const int row{ (g_StartEndCogSprite.frames - 1 - g_StartEndCogSprite.currentFrame) / g_StartEndCogSprite.cols };
	srcRect.width = g_StartEndCogSprite.texture.width / g_StartEndCogSprite.cols;
	srcRect.height = float(g_StartEndCogSprite.texture.height / (g_StartEndCogSprite.frames / g_StartEndCogSprite.cols));
	srcRect.left = float(g_StartEndCogSprite.currentFrame % g_StartEndCogSprite.cols) * srcRect.width;
	srcRect.bottom = float(row + 1) * srcRect.height;

	Rectf destRect{};
	destRect = g_Cells[g_AmountOfCells - 1].rect;
	destRect.left += g_Cells[g_AmountOfCells - 1].rect.width;
	DrawTexture(g_StartEndCogSprite.texture, destRect, srcRect);
}

void UpdateCogsBasedOnState() {
	UpdateOuterCogsBasedOnState();
}

void UpdateOuterCogsBasedOnState() {
	if (g_Cells[0].movingState == MovingState::forwards) {
		DrawStartSprite();
	}

	if (g_Cells[0].movingState == MovingState::backwards) {
		DrawStartSpriteReverse();
	}

	if (g_Cells[g_AmountOfCells - 1].movingState == MovingState::forwards) {
		DrawEndSprite();
	}

	if (g_Cells[g_AmountOfCells - 1].movingState == MovingState::backwards) {
		DrawEndSpriteReverse();
	}
}

void SetInnerCogsMovement()
{
	int cogsIndexes[g_AmountOfCogs]{};
	int filteredCogs[g_AmountOfCogs]{};
	int currentValidCogs{};
	FilterOutCogs(cogsIndexes, filteredCogs, currentValidCogs);
	for (int i{}; i < currentValidCogs; ++i)
	{
		const bool mustMoveForward{ (i + 1) % 2 == 0 };
		if (mustMoveForward) {
			g_Cells[cogsIndexes[i]].movingState = MovingState::forwards;
		}
		else
		{
			g_Cells[cogsIndexes[i]].movingState = MovingState::backwards;
		}
	}
}

void DrawOuterCogsSprites()
{
	if (g_Cells[0].movingState == MovingState::forwards)
	{
		DrawStartSpriteReverse();
	}
	else
	{
		DrawStartSprite();
	}

	if (g_Cells[g_AmountOfCells - 1].movingState == MovingState::forwards)
	{
		DrawEndSpriteReverse();
	}
	else
	{
		DrawEndSprite();
	}
}

void DrawInnerCogSprites()
{
	for (int i{}; i < g_AmountOfCells; ++i)
	{
		const Cell cell{ g_Cells[i] };
		if (cell.state != RectState::cog) {
			return;
		}
		if (cell.movingState == MovingState::forwards)
		{
			DrawInnerCogSprite(cell);
		}
		if (cell.movingState == MovingState::backwards)
		{
			DrawInnerCogSpriteReverse(cell);
		}
	}
}

void DrawWinText()
{
	Rectf destRect{};
	destRect.height = g_WinText.height;
	destRect.width = g_WinText.width;
	destRect.left = (g_WindowWidth / 2) - (destRect.width / 2);
	destRect.bottom = g_WindowHeight - (g_WinText.height) - (g_WinText.height / 2);

	DrawTexture(g_WinText, destRect);
}

void InitWinText()
{
	const Color4f white{ 1,1,1,1 };
	bool isSuccessfull{ TextureFromString("YOU WIN!! GG!!","Resources/RobotoSlab-ExtraBold.ttf", 50, white,g_WinText)};
	if (!isSuccessfull) {
		std::cout << "Can not load RobotoSlab-ExtraBold.ttf as font\n";
	}
}

void DrawCells()
{
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
			if (g_IsFinished) DrawInnerCogSprite(g_Cells[i]);
			else DrawTexture(g_Cog, g_Cells[i].rect);
			break;
		}
	}
}

void SetSpriteProperties()
{
	g_StartEndCogSprite.frames = 16;
	g_StartEndCogSprite.currentFrame = 0;
	g_StartEndCogSprite.cols = 8;
	g_StartEndCogSprite.frameTime = 1 / 7.f;

	g_InnerCogSprite.frames = 16;
	g_InnerCogSprite.currentFrame = 0;
	g_InnerCogSprite.cols = 8;
	g_InnerCogSprite.frameTime = 1 / 7.f;
}
#pragma endregion ownDefinitions