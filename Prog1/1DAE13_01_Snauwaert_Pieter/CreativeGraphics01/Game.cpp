#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(1.f,0.8f,0.7f);

	// Put your own draw statements here
	//head
	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawEllipse(g_WindowWidth / 2, g_WindowHeight / 2, 300.f, 300.f,5.f);
	SetColor(1.f, 1.f, 0.f, 1.f);
	FillEllipse(g_WindowWidth / 2, g_WindowHeight / 2, 300.f, 300.f);
	//eyes
	SetColor(1.f, 1.f, 1.f, 1.f);
	FillEllipse(g_WindowWidth / 3+20.f, (g_WindowHeight / 3) * 2-30.f, 70, 30);
	FillEllipse((g_WindowWidth / 3) * 2-20.f, (g_WindowHeight / 3) * 2-30.f, 70, 30);
	SetColor(0.f, 0.f, 0.f, 1.f);
	FillEllipse((g_WindowWidth / 3) * 2-20.f, (g_WindowHeight / 3) * 2.f-30.f, 30.f, 30.f);
	FillEllipse((g_WindowWidth / 3)+20.f, (g_WindowHeight / 3) * 2-30.f, 30, 30);
	//mouth
	SetColor(1.f, 0.3f, 0.4f, 1.f);
	FillArc(Point2f{ g_WindowWidth/2,g_WindowHeight / 3.f+30.f}, 200.f, 100.f, -g_Pi,0.f);
	SetColor(1.f, 0.3f, 0.4f, 0.7f);
	DrawArc(Point2f{ g_WindowWidth / 2,g_WindowHeight / 3.f+30.f}, 200.f, 100.f, -g_Pi, 0.f,20.f);
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