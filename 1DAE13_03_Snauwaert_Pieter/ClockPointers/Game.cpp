#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBigArm();
	DrawSmallArm();
}

void Update(float elapsedSec)
{
	g_Angle+=(360.f/g_NrFrames)*(g_Pi/180.f);
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
void DrawBigArm()
{
	float Radius{ 150.f };
	float InnerRadius{ Radius / 2 };
	float topAngle{ g_Angle - InnerRadius/2 };
	float lowerAngle{ g_Angle + InnerRadius/2 };
	Point2f Endl{ g_Center.x - Radius * cosf(g_Angle),g_Center.y + Radius * sinf(g_Angle) };
	Point2f Mid1{ g_Center.x - InnerRadius * cosf(topAngle),g_Center.y + InnerRadius * sinf(topAngle) };
	Point2f Mid2{ g_Center.x - InnerRadius * cosf(lowerAngle),g_Center.y + InnerRadius * sinf(lowerAngle) };
	DrawLine(g_Center, Mid1, 5.f);
	DrawLine(Mid1, Endl, 5.f);
	DrawLine(Endl, Mid2, 5.f);
	DrawLine(Mid2, g_Center, 5.f);
};
void DrawSmallArm()
{
	float Devision{ 12.f };
	float Radius{ 100.f };
	float InnerRadius{ Radius/2 };
	float topAngle{ g_Angle + InnerRadius/Devision };
	float lowerAngle{ g_Angle - InnerRadius/Devision };
	Point2f Endl{ g_Center.x - Radius * cosf(g_Angle / Devision),g_Center.y + Radius * sinf(g_Angle/Devision) };
	Point2f Mid1{ g_Center.x - InnerRadius * cosf(topAngle / Devision),g_Center.y + InnerRadius * sinf(topAngle / Devision) };
	Point2f Mid2{ g_Center.x - InnerRadius * cosf(lowerAngle / Devision),g_Center.y + InnerRadius * sinf(lowerAngle / Devision) };
	DrawLine(g_Center,Mid1,5.f);
	DrawLine(Mid1, Endl, 5.f);
	DrawLine(Endl, Mid2, 5.f);
	DrawLine(Mid2, g_Center, 5.f);
}
#pragma endregion ownDefinitions