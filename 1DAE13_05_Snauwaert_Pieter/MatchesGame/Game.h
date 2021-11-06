#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MatchesGame - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_Amount{21};
int g_PlayerAmount{};
int g_PlayerAmountIn{};
int g_CpuAmount{};
enum class PlayerState
{
	player,
	cpuPlayer
};
PlayerState g_Player{ PlayerState::player };
PlayerState g_LastPlayer{};
std::string g_PlayerAmountString{};
std::string g_cpuAmountString{};
std::string g_WinString{};
// Declare your own functions here
void DrawMatches();
void DrawMatchesPlayers();
void UpdateAmounts();
void CheckWin();
void ResetGame();
int GenerateRandomInt(int min, int max);
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
