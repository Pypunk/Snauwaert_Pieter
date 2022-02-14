#pragma once
using namespace utils;
class Vehicle;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Ex58 - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Texture g_StreetTexture{};
Texture g_ChickenTexture{};
Point2f g_ChickenPos{};
Texture g_Text{};
Rectf g_DestRect{};
float g_Speed{ 100.f };
const int g_FontSize{ 40 };
enum class GameState
{
	play,
	pause,
	win,
	lose,
	reset
};
GameState g_CurrentState{};
const int g_AmountOfVehicles{ 5 };
Vehicle* g_pVehicles[g_AmountOfVehicles]{};
enum class Direction
{
	left,
	right,
	front
};
Direction g_CurrentDirection{ Direction::front };
// Declare your own functions here
void ResetGame();
void DrawChicken();
void DrawVehicles();
void DrawTexts();
void UpdateVehicles(float elapsedSec);
void UpdateChicken(float elapsedSec);
void PrintInfo();
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
