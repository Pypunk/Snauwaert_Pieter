#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_NrFrames{};
Rectf g_GreenRect{ 0,g_WindowHeight - 100,100,100 };
Rectf g_RedRect{ 0,0,100,100 };
Rectf g_YellowRect{ g_WindowWidth - 100,0,100,100 };
Rectf g_BlueRect{ g_WindowWidth - 100,g_WindowHeight - 100,100,100 };
// Declare your own functions here
void DrawGreenRect();
void DrawRedRect();
void DrawYellowRect();
void DrawBlueRect();
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
