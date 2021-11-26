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
	Point2f origin{ 0,0 };
	DrawSierpinskiTriangle(origin, g_WindowWidth);
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
void DrawEquilateralTriangle(Point2f& position, float size, bool isFilled)
{
	Point2f position2{ CreateCoordinatesFromRads(size, ConvertToRadians(60.0f), position) };
	Point2f position3{ Point2f{ position.x + size, position.y } };
	if (isFilled)
		FillTriangle(position, position2, position3);
	else
		DrawTriangle(position, position2, position3);
}

void DrawSierpinskiTriangle(Point2f& position, float size)
{
	if (size >= 10.0f) 
	{
		DrawEquilateralTriangle(position, size, false);
		SetColor(1, 0, 0, 1);
		DrawSierpinskiTriangle(position, size / 2);
		Point2f position2{ CreateCoordinatesFromRads(size / 2, ConvertToRadians(60.0f), position) };
		SetColor(0, 1, 0, 1);
		DrawSierpinskiTriangle(position2, size / 2);
		Point2f position3{ position.x + size / 2, position.y };
		SetColor(0, 0, 1, 1);
		DrawSierpinskiTriangle(position3, size / 2);
	}
}
#pragma endregion ownDefinitions