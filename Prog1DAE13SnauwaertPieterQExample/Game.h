#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Prog1QExample - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_Even{}, g_Odd{}, g_Any{};
float g_TotalTime{};
const float g_PixelSize{ 10.f };
const float g_Border{ 30.f };
Color4f g_Color{};
Rectf g_ElevatorRect{ g_WindowWidth - 40.f - 30.f,30.f ,40.f,60.f };
float g_Speed{ 100.f };
Point2f g_MousePos{};
enum class elevatorState
{
	moving,
	stationary
};
elevatorState g_CurrentState{ elevatorState::moving };
// Declare your own functions here
void Generate();
void PrintRandomNumbers();
void DrawElevator();
void UpdateElevator(float elapsedSec);
bool IsPointInBorder(const Point2f p, const Rectf r);
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
