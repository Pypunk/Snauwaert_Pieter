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
Rectf g_LeftRect{};
Rectf g_RightRect{};
Ellipsef g_Ball{};
float g_XSpeed{};
float g_YSpeed{};
float g_RandomXSpeedStored{};
float g_RandomYSpeedStored{};
float g_CounterPlayer1;
float g_CounterPlayer2{};
// Declare your own functions here
void CreateRects();
void CreateBall();
float GenerateRandomFloat(float min, float max);
bool IsPointInRect(const Point2f& p, const Rectf& r);
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
