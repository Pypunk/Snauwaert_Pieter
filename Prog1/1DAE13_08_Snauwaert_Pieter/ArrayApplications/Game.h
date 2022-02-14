#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ArrayApplications - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 350 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_ClickedPointsAmount{ 5 };
const int g_TraceAmount{ 11 };
const int g_StatsAmount{ 6 };
const int g_AmountOfPentagrams{ 5 };
const float g_PentaRadius{ 50 };
const int g_CellsAmount{ 12 };

int g_CurrentIndexClickedPoints{};
int g_CurrentIndexTracedPoints{};
int g_Stats[g_StatsAmount]{};
bool g_IsCellSelected[g_CellsAmount];

const Point2f g_PentagramCenter{ g_WindowWidth / 2,g_WindowHeight / 2 };
const Color4f g_Yellow{ 1,1,0,1 };\

Point2f g_MousePos{};
AngleSpeed g_Pentagrams[g_AmountOfPentagrams]{};
Point2f g_ClickedPoints[g_ClickedPointsAmount]{};
Point2f g_TracedPoints[g_TraceAmount]{};
Texture g_StatsText[g_StatsAmount]{};
Texture g_StatsTextAmount[g_StatsAmount];
Rectf g_Grid[g_CellsAmount];

// Declare your own functions here
void DrawClickedPoints();
void AddClickedPoint();
void InitialisePentagrams();
void UpdatePentagrams(float elapsedSec);
void DrawPentagrams();
void AddMousePos();
void DrawMouseTrace();
void UpdateRandStats();
void DrawRandStats();
void DrawGrid();
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
