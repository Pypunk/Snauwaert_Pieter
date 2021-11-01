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
int g_Min{1};
int g_Max{2};
float g_D1{};
float g_D2{};
float g_D3{};
float g_D4{};
float g_D5{};
float g_D6{};
float g_DoubleD2;
float g_DoubleD3;
float g_DoubleD4;
float g_DoubleD5;
float g_DoubleD6;
float g_DoubleD7;
float g_DoubleD8;
float g_DoubleD9;
float g_DoubleD10;
float g_DoubleD11;
float g_DoubleD12;
// Declare your own functions here
void DrawDiceThrows();
void DrawDoubleDiceThrows();
void Update1Dice(int dice);
void Update2Dice(int dice1, int dice2);
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
