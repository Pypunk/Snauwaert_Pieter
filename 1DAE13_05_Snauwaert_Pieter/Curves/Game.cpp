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
	ClearBackground(0.1f, 0.1f, 0.5f);

	// Put your own draw statements here
	DrawCircle();
	DrawCrosier();

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
void DrawCircle()
{
	SetColor(1, 0, 0);
	float scaleX{ 100 };
	float scaleY{ 150 };
	const Point2f center{ 150,g_WindowHeight / 2 };
	const float points{ 10.f };
	const float step{ 360 / points * g_Pi / 180 };
	for (float angle{}; angle < g_Pi * 2; angle += step)
	{
		float posY{ sinf(angle) * scaleY + center.y };
		float posY2{ sinf((angle + step)) * scaleY + center.y };
		float PosX{ cosf(angle) * scaleX + center.x };
		float PosX2{ cosf(angle + step) * scaleX + center.x };
		DrawLine(PosX, posY, PosX2, posY2);
	}
}
void DrawCrosier()
{
	SetColor(0, 1, 1);
	const Point2f center{ 350,g_WindowHeight / 2 };
	const float step{ 0.572958f * g_Pi / 180 };
	float r{};
	float a{};
	const float windings{ 8 };
	for (float angle{}; angle < windings * (g_Pi * 2) + (g_Pi / 2); angle += step)
	{
		a = g_WindowWidth / 4;
		float posY{ sinf(angle) * r + center.y };
		float posY2{ sinf((angle + step)) * r + center.y };
		float PosX{ cosf(angle) * r + center.x };
		float PosX2{ cosf(angle + step) * r + center.x };
		r = a / sqrtf(angle);
		DrawLine(PosX, posY, PosX2, posY2);
	}
}
#pragma endregion ownDefinitions