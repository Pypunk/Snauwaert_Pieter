#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MathVector - Snauwaert, Pieter - 1DAE13" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_Angle{45};
const Vector2f g_TestVector{ 100,30 };
const Vector2f g_TestVector2{ 50,50 };
Vector2f g_AdditionVector{};
const Vector2f g_TestSubVector1{ 50,100 };
const Vector2f g_TestSubVector2{ 60,70 };
Vector2f g_SubtractionVector{};
const Vector2f g_Hor{ 80,0 };
const Vector2f g_Ver{ 0,50 };
const Vector2f g_Para{ 0,25 };
Vector2f g_AnimationVector{50,50};
Vector2f g_RotatingVector{};
Vector2f g_Projection{};
// Declare your own functions here
void DrawVectors();
void DoAddition(const Vector2f& v1,const Vector2f& v2);
void DoSubtraction(const Vector2f& v1, const Vector2f& v2);
void DoDotProduct(const Vector2f& v1, const Vector2f& v2, const Vector2f& v3);
void DoCrossProduct(const Vector2f& v1, const Vector2f& v2);
void GetLenght(const Vector2f& v);
void GetScaled(const Vector2f& v);
void GetNormal(const Vector2f& v);
void GetAngle(const Vector2f& v1, const Vector2f& v2);
bool TestAreEqual(const Vector2f& v1, const Vector2f& v2);
void DoAnimationProjection(const Vector2f& v, Vector2f& v2, float angle);
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
