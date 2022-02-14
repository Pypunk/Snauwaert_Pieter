#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FrameTime - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_nrFrame{};
float g_AccumulatedTime{};
Point2f g_BallVelocity{ 100.f,80.f };
Circlef g_Ball{ 50.f,50.f,25.f };
float g_Gravity{ -9.81f };
float g_FreeFallVelocity{};
Rectf g_FreeFallRect{50.f,g_WindowHeight-30.f,30.f,30.f};
enum class FreeFallState
{
	falling,
	stationary
};
FreeFallState g_CurrentState{ FreeFallState::stationary };
// Declare your own functions here
void DrawBall();
void UpdateBall(float elapsedSec);
void DrawFreeFall();
void UpdateFreeFall(float elapsedSec);
void ResetFreeFall();
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
