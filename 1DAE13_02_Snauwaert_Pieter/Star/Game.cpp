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
	DrawStar();

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
void DrawStar()
{
	float outerRadius{ 200.f };
	Point2f center{ g_WindowWidth / 2,g_WindowHeight / 2 };

	Point2f outerPoint{ cosf(2 * float(M_PI / 4)) * outerRadius + center.x,sinf(2 * float(M_PI / 4)) * outerRadius + center.y };
	Point2f outerPoint2{ cosf(2 * float(M_PI / 4*2)) * outerRadius + center.x,sinf(2 * float(M_PI / 4*2)) * outerRadius + center.y };
	Point2f outerPoint3{ cosf(2 * float(M_PI / 4*3)) * outerRadius + center.x,sinf(2 * float(M_PI / 4*3)) * outerRadius + center.y };
	Point2f outerPoint4{ cosf(2 * float(M_PI / 4 * 4)) * outerRadius + center.x,sinf(2 * float(M_PI / 4 * 4)) * outerRadius + center.y };

	Point2f outerPoint5{ cosf(float(M_PI / 4)) * (outerRadius * (2.f / 3.f))+center.x,sinf(float(M_PI / 4)) * (outerRadius * (2.f / 3.f))+center.y };
	Point2f outerPoint6{ cosf(float(3*M_PI / 4)) * (outerRadius * (2.f / 3.f))+center.x,sinf(float(3*M_PI / 4)) * (outerRadius * (2.f / 3.f))+center.y };
	Point2f outerPoint7{ cosf(float(5*M_PI / 4)) * (outerRadius * (2.f / 3.f))+center.x,sinf(float(5*M_PI / 4)) * (outerRadius * (2.f / 3.f))+center.y };
	Point2f outerPoint8{ cosf(float(7*M_PI / 4)) * (outerRadius * (2.f / 3.f))+center.x,sinf(float(7*M_PI / 4)) * (outerRadius * (2.f / 3.f))+center.y };

	Point2f innerPoint{ cosf(float(M_PI / 6)) * (outerRadius * (1.f / 3.f)) + center.x,sinf(float(M_PI / 6)) * (outerRadius * (1.f / 3.f)) + center.y };
	Point2f innerPoint2{ cosf(float(2 * M_PI / 3)) * (outerRadius * (1.f / 3.f)) + center.x,sinf(float(2 * M_PI / 3)) * (outerRadius * (1.f / 3.f)) + center.y };
	Point2f innerPoint3{ cosf(float(7 * M_PI / 6)) * (outerRadius * (1.f / 3.f)) + center.x,sinf(float(7 * M_PI / 6)) * (outerRadius * (1.f / 3.f)) + center.y };
	Point2f innerPoint4{ cosf(float(5 * M_PI / 3)) * (outerRadius * (1.f / 3.f)) + center.x,sinf(float(5 * M_PI / 3)) * (outerRadius * (1.f / 3.f)) + center.y };

	Point2f innerPoint5{ cosf(float(M_PI / 3)) * (outerRadius * (1.f / 3.f)) + center.x,sinf(float(M_PI / 3)) * (outerRadius * (1.f / 3.f)) + center.y };
	Point2f innerPoint6{ cosf(float(5 * M_PI / 6)) * (outerRadius * (1.f / 3.f)) + center.x,sinf(float(5 * M_PI / 6)) * (outerRadius * (1.f / 3.f)) + center.y };
	Point2f innerPoint7{ cosf(float(4 * M_PI / 3)) * (outerRadius * (1.f / 3.f)) + center.x,sinf(float(4 * M_PI / 3)) * (outerRadius * (1.f / 3.f)) + center.y };
	Point2f innerPoint8{ cosf(float(11 * M_PI / 6)) * (outerRadius * (1.f / 3.f)) + center.x,sinf(float(11 * M_PI / 6)) * (outerRadius * (1.f / 3.f)) + center.y };

	SetColor(1.f, 0.f, 0.f, 1.f);
	DrawLine(outerPoint, innerPoint5);
	DrawLine(innerPoint5, outerPoint5);
	DrawLine(outerPoint5, innerPoint);
	DrawLine(innerPoint, outerPoint4);
	DrawLine(outerPoint4, innerPoint8);
	DrawLine(innerPoint8, outerPoint8);
	DrawLine(outerPoint8, innerPoint4);
	DrawLine(innerPoint4, outerPoint3);
	DrawLine(outerPoint3, innerPoint7);
	DrawLine(innerPoint7, outerPoint7);
	DrawLine(outerPoint7, innerPoint3);
	DrawLine(innerPoint3, outerPoint2);
	DrawLine(outerPoint2, innerPoint6);
	DrawLine(innerPoint6, outerPoint6);
	DrawLine(outerPoint6, innerPoint2);
	DrawLine(innerPoint2, outerPoint);
}
#pragma endregion ownDefinitions