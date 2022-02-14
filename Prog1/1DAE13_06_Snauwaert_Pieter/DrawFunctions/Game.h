#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DrawFunctions - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here
void DrawSquares(Point2f position, float squareSize, float amount);
void TestDrawSquares();
void DrawEguilateralTriangle(Point2f position, float size, bool isFilled = true);
void TestDrawTriangles();
void DrawPentagram(Point2f center, float radius);
void TestDrawPentagram();
void DrawRadiantRect(Point2f position, float width, float height, Color4f startColor, Color4f endColor);
void TestDrawRadiantRect();
void DrawDotGrid(Point2f position, float radius, float offSet, float cols, float rows);
void TestDrawDotGrid();
float ConvertToRadians(float degrees);
Point2f CreateCoordinatesFromRads(float radius, float radians, Point2f offset);
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
