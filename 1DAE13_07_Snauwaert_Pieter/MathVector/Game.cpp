#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	std::cout << ToString(testVector) << std::endl;
	additionVector = Add(testVector, testVector2);
	subtractionVector = Subtract(testSubVector1, testSubVector2);
	const Vector2f hor{ 80,0 };
	const Vector2f ver{ 0,50 };
	const Vector2f para{ 0,25 };
	std::cout << "hor:" << ToString(hor) << " ver: " << ToString(ver) << " Dot product: " << Dot(hor, ver) << std::endl;
	std::cout << "ver:" << ToString(ver) << " para: " << ToString(para) << " Dot product: " << Dot(ver, para) << std::endl;
	std::cout << "hor:" << ToString(hor) << " ver: " << ToString(ver) << " Cross product: " << Cross(hor, ver) << std::endl;
	std::cout << "ver:" << ToString(ver) << " hor: " << ToString(hor) << " Cross product: " << Cross(ver, hor) << std::endl;
	std::cout << "Length of " << ToString(testVector) << ": " << Length(testVector) << std::endl;
	std::cout << "Scaled " << ToString(testVector) << " is " << ToString(Scale(testVector, 0.1f)) << std::endl;
	std::cout << "Normalized " << ToString(testVector) << " is " << ToString(Normalize(testVector)) << std::endl;
	std::cout << "Angle Between " << ToString(Vector2f{ 10,0 }) << " and " << ToString(Vector2f{ 10,10 }) << ": " << AngleBetween(Vector2f{10,0}, Vector2f{10,10}) << " degrees " << ConvertToRadians(AngleBetween(Vector2f{ 10,0 }, Vector2f{ 10,10 })) << " radians\n";
	Vector2f v1{ 10,10 };
	Vector2f v2{ 10,10 };
	std::cout << std::boolalpha << AreEqual(v1, v2);
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	SetColor(Color4f{});
	DrawVector(testVector);
	DrawVector(testVector2, Point2f{ testVector.x,testVector.y });
	DrawVector(additionVector);
	DrawVector(testSubVector1, Point2f{ 70,70 });
	DrawVector(testSubVector2, Point2f{ 70,70 });
	DrawVector(subtractionVector, Point2f{ 70+testSubVector2.x,70+testSubVector2.y });
}

void Update(float elapsedSec)
{
	// process input, do physics 

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

#pragma endregion ownDefinitions