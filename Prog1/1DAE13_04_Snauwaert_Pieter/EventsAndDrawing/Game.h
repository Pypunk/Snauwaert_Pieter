#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EventsAndDrawing - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_MousePos{};
enum class RectState
{
	running,
	stationary
};
RectState g_CurrentRectState{ RectState::stationary };
enum class LineState
{
	moving,
	stationary
};
LineState g_CurrentLineState{ LineState::moving };

bool g_Clicked{};
Rectf g_Rect{};
Rectf g_NewRect{};
Color4f g_Color{};
Point2f g_EndPoint{};
Point2f g_EndPointSpeed{};
Point2f g_StartPoint{};
Point2f g_StartPointSpeed{};
// Declare your own functions here
void CreateRectangle();
void CreateLine();
void UpdateRectangle();
void DrawRectangle();
void UpdateLine();
void DrawMovingLine();
bool IsPointInRect(const Point2f& p,const Rectf& r);
float GenerateRandomFloat(float min, float max);
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
