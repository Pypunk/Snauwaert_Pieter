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
	DrawHouse();
	DrawFlag();
	DrawCheckerPattern();
	DrawColorBand();
	DrawPentagram();
	DrawColumnGraph();
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
void DrawHouse()
{
	float width{300.f};
	float height{100.f};
	Point2f position{ 20.f,g_WindowHeight - 20.f };
	SetColor(1.f, 0.f, 0.f, 1.f);
	FillRect(position.x, position.y - height*2, width, height);
	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawRect(position.x, position.y - height * 2, width, height);
	SetColor(1.f, 0.f, 0.f, 1.f);
	FillTriangle(Point2f{ position.x,position.y - height }, Point2f{ position.x + width / 2,position.y }, Point2f{position.x+width,position.y-height});
	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawTriangle(Point2f{ position.x, position.y - height }, Point2f{ position.x + width / 2, position.y }, Point2f{ position.x + width, position.y - height });
}

void DrawFlag()
{
	float width{ 100.f };
	float height{ 200.f };
	Point2f position{ 20.f, 300.f };
	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(position.x, position.y, width, height);
	SetColor(1.f, 1.f, 0.f, 1.f);
	FillRect(position.x + width, position.y, width, height);
	SetColor(1.f, 0.f, 0.f, 1.f);
	FillRect(position.x + width * 2, position.y, width, height);
	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawRect(position.x, position.y, width * 3, height);
}

void DrawCheckerPattern()
{
	float size{ 50.f };
	Point2f position{ 20.f,50.f };
	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawRect(position.x, position.y, size * 3, size * 3);
	FillRect(position.x + size, position.y + size * 2, size, size);
	FillRect(position.x, position.y + size, size, size);
	FillRect(position.x + size * 2, position.y + size, size, size);
	FillRect(position.x + size, position.y, size, size);
	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(position.x, position.y + size*2, size, size);
	FillRect(position.x + size*2, position.y + size * 2, size, size);
	FillRect(position.x + size, position.y + size, size, size);
	FillRect(position.x, position.y, size, size);
	FillRect(position.x + size * 2, position.y, size, size);
}

void DrawColorBand()
{
	float width{ 50.f };
	float height{ 200.f };
	Point2f position{ 500.f,580 };
	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(position.x, position.y, width, height);
	SetColor(1.f, 0.f, 0.f, 1.f);
	FillRect(position.x + width, position.y, width, height);
	SetColor(0.f, 1.f, 0.f, 1.f);
	FillRect(position.x + width * 2, position.y, width, height);
	SetColor(0.f, 0.f, 1.f, 1.f);
	FillRect(position.x + width * 3, position.y, width, height);
	SetColor(1.f, 0.f, 1.f, 1.f);
	FillRect(position.x + width * 4, position.y, width, height);
	SetColor(1.f, 1.f, 0.f, 1.f);
	FillRect(position.x + width * 5, position.y, width, height);
	SetColor(0.f, 1.f, 0.f, 1.f);
	FillRect(position.x + width * 6, position.y, width, height);
	SetColor(0.f, 1.f, 1.f, 1.f);
	FillRect(position.x + width * 7, position.y, width, height);
	SetColor(1.f, 1.f, 1.f, 1.f);
	FillRect(position.x + width * 8, position.y, width, height);
	SetColor(0.f, 0.f, 0.f, 0.7f);
	FillRect(position.x, position.y, width*9, height/2.f);
	SetColor(1.f, 1.f, 0.f, 1.f);
	DrawRect(position.x, position.y, width * 9, height, 5.f);
}

void DrawPentagram()
{
	Point2f center{ 550.f,400.f };
	float radius{ 70.f };
	std::vector<Point2f> pentaPoints{};
	pentaPoints.push_back(Point2f{ cos(2 * float(M_PI / 5)) * radius + center.x,sin(2 * float(M_PI / 5)) * radius + center.y });
	pentaPoints.push_back(Point2f{ cos(2 * float(M_PI / 5 * 3)) * radius + center.x,sin(2 * float(M_PI / 5 * 3)) * radius + center.y });
	pentaPoints.push_back(Point2f{ cos(2 * float(M_PI / 5 * 5)) * radius + center.x,sin(2 * float(M_PI / 5 * 5)) * radius + center.y });
	pentaPoints.push_back(Point2f{ cos(2 * float(M_PI / 5*2)) * radius + center.x,sin(2 * float(M_PI / 5*2)) * radius + center.y });
	pentaPoints.push_back(Point2f{ cos(2 * float(M_PI / 5*4)) * radius + center.x,sin(2 * float(M_PI / 5*4)) * radius + center.y });
	SetColor(1.f, 0.f, 1.f, 1.f);
	DrawPolygon(pentaPoints);
}

void DrawColumnGraph()
{
	float width{ 50.f };
	float percentage{};
	Point2f position{ g_WindowWidth / 2 ,20.f};
	std::cout << "% people playing games\n";
	std::cout << "In the range [0, 20]? ";
	std::cin >> percentage;
	SetColor(0.3882f, 0.8352f, 0.7843f, 1.f);
	FillRect(position.x, position.y, width, percentage);
	std::cout << "In the range [21, 40]? ";
	std::cin >> percentage;
	SetColor(0.3882f, 0.6352f, 0.9843f, 1.f);
	FillRect(position.x + width, position.y, width, percentage);
	std::cout << "In the range [41, 60]? ";
	std::cin >> percentage;
	SetColor(0.f, 0.768f, 1.f, 1.f);
	FillRect(position.x + width * 2, position.y, width, percentage);
	std::cout << "Older than 60? ";
	std::cin >> percentage;
	SetColor(0.3882f, 0.6352f, 0.9843f, 1.f);
	FillRect(position.x + width * 3, position.y, width, percentage);
}

#pragma endregion ownDefinitions
