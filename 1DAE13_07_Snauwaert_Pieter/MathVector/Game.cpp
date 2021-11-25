#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	std::cout << "g_TestVector: " << ToString(g_TestVector) << std::endl;
	DoAddition(g_TestVector, g_TestVector2);
	DoSubtraction(g_TestSubVector1, g_TestSubVector2);
	DoDotProduct(g_Hor, g_Ver, g_Para);
	DoCrossProduct(g_Hor, g_Ver);
	GetLenght(g_TestVector);
	GetScaled(g_TestVector);
	GetNormal(g_TestVector);
	const Vector2f angleVector1{ 10,0 };
	const Vector2f angleVector2{ 10,10 };
	GetAngle(angleVector1, angleVector2);
	const Vector2f testEqualVector1{ 10,10 };
	const Vector2f testEqualVector2{ 10.0001f,10.0001f };
	bool test = TestAreEqual(testEqualVector1, testEqualVector2);
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	SetColor(Color4f{});
	DrawVectors();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_Angle += 100 * elapsedSec;
	DoAnimationProjection(g_AnimationVector, g_RotatingVector, g_Angle);
	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawVectors()
{
	DrawVector(g_TestVector);
	DrawVector(g_TestVector2, Point2f{ g_TestVector.x,g_TestVector.y });
	DrawVector(g_AdditionVector);
	DrawVector(g_TestSubVector1, Point2f{ 70,70 });
	DrawVector(g_TestSubVector2, Point2f{ 70,70 });
	DrawVector(g_SubtractionVector, Point2f{ 70 + g_TestSubVector2.x,70 + g_TestSubVector2.y });
	SetColor(1, 0, 0, 1);
	DrawVector(g_Projection, Point2f{ g_WindowWidth / 2,g_WindowHeight / 2 });
	SetColor(0, 0, 0, 1);
	DrawVector(g_RotatingVector, Point2f{ g_WindowWidth / 2,g_WindowHeight / 2 });
}
void DoAddition(const Vector2f& v1, const Vector2f& v2)
{
	g_AdditionVector = Add(v1, v2);
}
void DoSubtraction(const Vector2f& v1, const Vector2f& v2)
{
	g_SubtractionVector = Subtract(v1, v2);
}
void DoDotProduct(const Vector2f& v1, const Vector2f& v2, const Vector2f& v3)
{
	std::cout << "hor:" << ToString(v1) << " ver: " << ToString(v2) << " Dot product: " << Dot(v1, v2) << std::endl;
	std::cout << "ver:" << ToString(v2) << " para: " << ToString(v3) << " Dot product: " << Dot(v2, v3) << std::endl;
}
void DoCrossProduct(const Vector2f& v1, const Vector2f& v2)
{
	std::cout << "hor:" << ToString(v1) << " ver: " << ToString(v2) << " Cross product: " << Cross(v1, v2) << std::endl;
	std::cout << "ver:" << ToString(v2) << " hor: " << ToString(v1) << " Cross product: " << Cross(v2, v1) << std::endl;
}
void GetLenght(const Vector2f& v)
{
	std::cout << "Length of " << ToString(v) << ": " << Length(v) << std::endl;
}
void GetScaled(const Vector2f& v)
{
	std::cout << "Scaled " << ToString(v) << " is " << ToString(Scale(v, 0.1f)) << std::endl;
}
void GetNormal(const Vector2f& v)
{
	std::cout << "Normalized " << ToString(v) << " is " << ToString(Normalize(v)) << std::endl;
}
void GetAngle(const Vector2f& v1, const Vector2f& v2)
{
	std::cout << "Angle Between " << ToString(v1) << " and " << ToString(v2) << ": " << AngleBetween(v1, v2) << " degrees " << ConvertToRadians(AngleBetween(v1, v2)) << " radians\n";
}
bool TestAreEqual(const Vector2f& v1, const Vector2f& v2)
{
	return AreEqual(v1, v2);
}
void DoAnimationProjection(const Vector2f& v, Vector2f& v2, float angle)
{
	g_Projection = CalculateProjection(v,v2, angle);
}
#pragma endregion ownDefinitions