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
	ClearBackground(0,0,0);
	// Put your own draw statements here
	DrawYellowRect();
	DrawRedBar();
}

void Update(float elapsedSec)
{
	g_NrFrames++;
	g_YellowWidth = float(int(g_YellowWidth + 1) % int(g_WindowWidth-20*2));
	g_IsThirtyFrames = !(int(g_NrFrames) % 30);
	g_RedWidth = float(int(g_RedWidth + g_IsThirtyFrames * 15)%int(g_WindowWidth-20*2));
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
void DrawYellowRect()
{
	float border{ 20 };
	float height{ 100 };
	float width{ g_WindowWidth - border * 2 };
	//float yellowWidth{ float(int(g_NrFrames) % int(width)) };
	Rectf yellowBar{ border,g_WindowHeight - border - height,g_YellowWidth,height };
	SetColor(1, 1, 0);
	FillRect(yellowBar);
	SetColor(1, 1, 1);
	DrawRect(border, g_WindowHeight - border-height, width, height,3.f);
}
void DrawRedBar()
{
	float border{ 20 };
	float height{ 100 };
	float width{ g_WindowWidth - border * 2 };
	SetColor(g_RedColor);
	Rectf redBar{ border,border,g_RedWidth,height };
	FillRect(redBar);
	SetColor(1, 1, 1);
	DrawRect(border,border,width,height, 3.f);
}
#pragma endregion ownDefinitions