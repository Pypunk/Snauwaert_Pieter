#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Prog1DAE13_Q2021_Snauwaert_Pieter" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_MousePos{};
Ellipsef g_Circle{};
Color4f g_Color{};
float g_MaxRadius{};
float g_Speed{0.2f};
enum class CircleState
{
	invisible,
	growing,
	shrinking
};
CircleState g_CurrentState{ CircleState::invisible };
// Declare your own functions here
void PrintLetters();
int GenerateRandomInt(int min, int max);
float GenerateRandomFloat(float min, float max);
void CreateCircle();
void UpdateCircle();
void CheckCollision();
void PrintState();
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
