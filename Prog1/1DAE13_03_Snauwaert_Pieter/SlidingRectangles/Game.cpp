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
	ClearBackground();

	// Put your own draw statements here

	DrawGreenRect();
	DrawRedRect();
	DrawYellowRect();
	DrawBlueRect();
}

void Update(float elapsedSec)
{
	g_NrFrames++;
	g_GreenRect.left = float(int(g_NrFrames) % int(g_WindowWidth))-g_GreenRect.width;
	g_GreenRect.bottom = float(g_WindowHeight-float(int(g_NrFrames)%int(g_WindowHeight)));
	g_RedRect.left = float(int(g_NrFrames) % int(g_WindowWidth))-g_RedRect.width;
	g_RedRect.bottom = float(int(g_NrFrames) % int(g_WindowHeight))-g_RedRect.height;
	g_YellowRect.left = float(g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth)));
	g_YellowRect.bottom = float(float(int(g_NrFrames) % int(g_WindowHeight)))-g_YellowRect.height;
	g_BlueRect.left = float(g_WindowWidth - float(int(g_NrFrames) % int(g_WindowWidth)));
	g_BlueRect.bottom = float(g_WindowHeight - float(int(g_NrFrames)%int(g_WindowHeight)));
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
void DrawGreenRect()
{
	SetColor(0, 1, 0, 0.7f);
	FillRect(g_GreenRect);
	SetColor(0, 0, 0);
	DrawRect(g_GreenRect);
}
void DrawRedRect()
{
	SetColor(1, 0, 0, 0.7f);
	FillRect(g_RedRect);
	SetColor(0, 0, 0);
	DrawRect(g_RedRect);
}
void DrawYellowRect()
{
	SetColor(1, 1, 0, 0.7f);
	FillRect(g_YellowRect);
	SetColor(0, 0, 0);
	DrawRect(g_YellowRect);
}
void DrawBlueRect()
{
	SetColor(0, 0, 1, 0.7f);
	FillRect(g_BlueRect);
	SetColor(0, 0, 0);
	DrawRect(g_BlueRect);
}
#pragma endregion ownDefinitions