#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_TestCircle = Circlef{ Point2f{float(rand() % int(g_WindowWidth)),float(rand() % int(g_WindowHeight))},50 };
	const float width{ 120.f };
	g_TestRect = Rectf{ float(rand() % int(g_WindowWidth-width*2)),float(rand() % int(g_WindowWidth-width*2)),width,width/2 };
}

void Draw()
{
	ClearBackground();
	// Put your own draw statements here
	SetColor(1, 1, 1, 1);
	FillCircle(g_TestCircle);
	FillRect(g_TestRect);
	if (IsPointInCircle(g_MousePos, g_TestCircle))
	{
		SetColor(1, 0, 0, 1);
		DrawCircle(g_TestCircle,2.f);
	}
	if (IsPointInRect(g_MousePos, g_TestRect))
	{
		SetColor(1, 0, 0, 1);
		DrawRect(g_TestRect, 2.f);
	}
	if (IsOverlapping(g_TestRect, g_MouseRect))
	{
		SetColor(1, 0, 0, 0.5);
		FillRect(g_MouseRect);
	}
	else
	{
		SetColor(0, 1, 0, 0.5);
		FillRect(g_MouseRect);
	}
	if (IsOverLapping(g_MouseCircle, g_TestCircle))
	{
		SetColor(1, 0, 0, 0.5);
		FillCircle(g_MouseCircle);
	}
	else
	{
		SetColor(0, 1, 0, 0.5);
		FillCircle(g_MouseCircle);
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 
	const float width{ 20.f };
	g_MouseRect = Rectf{ g_MousePos.x-width*2,g_MousePos.y-width/2,width*2,width };
	g_MouseCircle = Circlef{ g_MousePos.x + width,g_MousePos.y,width };
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
	g_MousePos = Point2f{ float(e.x), float(g_WindowHeight - e.y) };
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