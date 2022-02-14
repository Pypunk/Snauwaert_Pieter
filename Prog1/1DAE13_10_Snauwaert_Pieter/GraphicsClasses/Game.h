#pragma once
using namespace utils;
class Fraction;
class Light;
class DaeEllipse;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "GraphicsClasses - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_FractionsAmount{ 6 };
const int g_LightsAmount{ 8 };
const int g_DaeEllipseAmount{ 3 };
Fraction* g_pFractions[g_FractionsAmount]{ nullptr };
Light* g_pLights[g_LightsAmount]{ nullptr };
DaeEllipse* g_pDaeEllipse[g_DaeEllipseAmount]{ nullptr };
Point2f g_MousePos;
int g_AmountOfOnLights{};
// Declare your own functions here
void InitializeFractions();
void PrintFractionsSum();
void DrawFractions();
void DeleteFractions();
void InitializeLights();
void DrawLights();
void DeleteLights();
void HitLights(const Point2f& p);
void InitializeDaeEllipses();
void DrawDaeEllipses();
void ActivateDaeEllipses(const Point2f p);
void DeleteDaeEllipses();
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
