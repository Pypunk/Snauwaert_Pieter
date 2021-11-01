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
	DrawMouseRect();
	// Put your own draw statements here

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
	std::cout << "SDL_KEYDOWN\n\n";
}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_LEFT:
		std::cout << "SDL_KEYUP\n";
		std::cout << "Left arrow key is released\n\n";
		break;
	case SDLK_RIGHT:
		std::cout << "SDL_KEYUP\n";
		std::cout << "Right arrow key is released\n\n";
		break;
	case SDLK_UP:
		std::cout << "SDL_KEYUP\n";
		std::cout << "Up arrow key is released\n\n";
		break;
	case SDLK_DOWN:
		std::cout << "SDL_KEYUP\n";
		std::cout << "Down arrow key is released\n\n";
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	g_MousePos.x = float(e.x);
	g_MousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "SDL_MOUSEBUTTONDOWN\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		std::cout << "[";
		std::cout << g_MousePos.x << ", ";
		std::cout << g_MousePos.y << "]" << std::endl;
		std::cout << "Left mouse button went down\n\n";
		break;
	case SDL_BUTTON_RIGHT:
		std::cout << "[";
		std::cout << g_MousePos.x << ", ";
		std::cout << g_MousePos.y << "]" << std::endl;
		std::cout << "Right mouse button went down\n\n";
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "[";
		std::cout << g_MousePos.x << ", ";
		std::cout << g_MousePos.y << "]" << std::endl;
		std::cout << "Middle mouse button went down\n\n";
		break;
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "SDL_MOUSEBUTTONUP\n\n";
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
void DrawMouseRect()
{
	const float width{ 10.f };
	Rectf mouseRect{ g_MousePos.x,g_MousePos.y,width,width };
	SetColor(1, 0, 0);
	FillRect(mouseRect);
}
#pragma endregion ownDefinitions