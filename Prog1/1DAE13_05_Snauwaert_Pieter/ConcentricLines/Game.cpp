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
	ClearBackground(0,0,0);

	// Put your own draw statements here
	DrawLines();
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
	switch (key)
	{
	case SDLK_RIGHT:
		SwitchColor();
		break;
	}
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
	g_MousePos.x = float(e.x); 
	g_MousePos.y = float(g_WindowHeight - e.y);
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
void DrawLines()
{
	switch (Color(g_ColorInt))
	{
	case Color::red:
		g_Color = Color4f{ 1,0,0,1 };
		break;
	case Color::green:
		g_Color = Color4f{ 0,1,0,1 };
		break;
	case Color::blue:
		g_Color = Color4f{ 0,0,1,1 };
		break;
	}
	Point2f leftPoint{};
	Point2f bottomPoint{};
	SetColor(g_Color);
	while (leftPoint.y < g_WindowHeight)
	{
		Point2f temp{ leftPoint.x + g_WindowWidth , leftPoint.y };
		DrawLine(leftPoint, g_MousePos);
		DrawLine(temp, g_MousePos);
		leftPoint.y += 9.f;
	}
	while (bottomPoint.x < g_WindowWidth)
	{
		Point2f temp{ bottomPoint.x,bottomPoint.y + g_WindowHeight };
		DrawLine(bottomPoint, g_MousePos);
		DrawLine(temp, g_MousePos);
		bottomPoint.x += 9.f;
	}
}
void SwitchColor()
{
	g_ColorInt++;
	g_ColorInt = g_ColorInt % 3;
}
#pragma endregion ownDefinitions