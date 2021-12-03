#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "OxoGame - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_Rows{ 3 };
const int g_Cols{ 3 };
const int g_TextureAmount{6};
Point2f g_MousePos{};
Texture g_BackGround{};
Texture g_OXOTexture[g_TextureAmount]{};
Rectf g_GriddCellsDestRect[g_Rows * g_Cols]{};
enum class State
{
	empty,
	WhiteO,
	WhiteX,
	GreenO,
	GreenX,
	win
};
State g_PlayerState[2]{};
State g_GridState[g_Rows * g_Cols]{};
bool g_IsX{ false };
bool g_Player1{ true };
bool g_GameEnd{ false };
// Declare your own functions here
void CreateTextures();
void DrawGrid();
void ToggleGrid();
void TogglePlayerState();
void DrawAccordingToState(const State& currentState, const Rectf& destRect);
bool CheckHorizontal();
bool CheckVertical();
bool CheckDiagonal();
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
