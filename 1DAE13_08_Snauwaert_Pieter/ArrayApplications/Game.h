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
const int clickedPointsAmount{ 10 };
Point2f clickedPoints[clickedPointsAmount]{};
int currentIndexClickedPoints{};
Point2f g_MousePos{};
const int statsAmount{ 6 };
Texture statsText[statsAmount]{};
float stats[statsAmount]{};
const Color4f yellow{ 1,1,0,1 };
// Declare your own functions here
void DrawClickedPoints();
void AddClickedPoint();
void UpdateRandStats();
void DrawRandStats();
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
