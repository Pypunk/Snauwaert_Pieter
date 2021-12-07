#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfCells{25};
const int g_Rows{ 5 };
const int g_Cols{ 5 };
const int g_AmountOfCogs{ 10 };
const float g_CellSize{ 50 };
int g_SelectedIndex{};
Point2f g_MousePos{};
Cell g_Cells[g_AmountOfCells];
Texture g_Cog{};
Cell g_SelectedCell{};

// Declare your own functions here
void SetCurrentStates(Cell* pCells, const int size);
void DrawCell(Cell pCell);
bool CheckCellPositionX(int currentIndex, int secondIndex);
bool CheckCellPositionY(int currentIndex, int secondIndex);
bool IsNotConnected(int index);
void CheckAndMoveCell(int currentIndex, int secondIndex);
bool CheckNextCellX(int index, int previousIndex);
bool CheckNextCellY(int index, int previousIndex);
void CheckStates();
void UnCheckAllCells();

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
