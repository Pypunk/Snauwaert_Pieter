#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	float border{60.f};
	for (int i{}; i < g_PlanetAmount; i++)
	{
		g_planetPoints.push_back(Point2f{ float(rand() % int(g_WindowWidth-border)),float(rand() % int(g_WindowHeight-border)) });
		g_planetColors.push_back(Color4f{ float(rand() % 100), float(rand() % 100), float(rand() % 100), float(rand() % 100) });
	}
	float index{1};
	for (Point2f i : g_planetPoints)
	{
		std::cout << "Planet " << index << ": ";
		std::cout << "X value: " << i.x << " Y value: " << i.y << std::endl;
		index++;
	}
}

void Draw()
{
	ClearBackground(0,0,0.2f);

	// Put your own draw statements here
	DrawPlanets();
	DrawSpaceShip();
	DrawStars();
}

void Update(float elapsedSec)
{
	UpdateSpaceShip();
	float border{ 60.f };
	g_NrFrames++;
	if (!(g_NrFrames%int(g_WindowWidth)))
	{
		for (int i{}; i < g_PlanetAmount; i++)
		{
			g_planetPoints[i] = Point2f{ float(rand() % int(g_WindowWidth - border)),float(rand() % int(g_WindowHeight - border)) };
			g_planetColors[i] = Color4f{ float(rand() % 100), float(rand() % 100), float(rand() % 100), float(rand() % 100) };
		}
	}
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
void DrawSpaceShip()
{
	SetColor(1, 1, 1, 0.5);
	FillEllipse(g_SpaceShip);
	SetColor(0, 0, 0);
	DrawEllipse(g_SpaceShip);
	SetColor(0, 1, 1);
	FillArc(g_SpaceShip.center, 25.f, 25.f, 0, g_Pi);
	SetColor(0, 0, 0);
	DrawArc(g_SpaceShip.center, 25.f, 25.f, 0, g_Pi);
}
void UpdateSpaceShip()
{
	g_Angle += g_Pi / 100;
	g_SpaceShip.center.y = g_WindowHeight / 2 + 30 * cosf(g_Angle);
	g_SpaceShip.center.x = float(int(g_SpaceShip.center.x + 1) % int(g_WindowWidth));
}
void DrawStars()
{
	std::vector<Point2f> pentaPoints{};
	Point2f center{ float(rand()%int(g_WindowWidth)),float(rand()%int(g_WindowHeight)) };
	float radius{ 5.f };
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5) * radius + center.x,sinf(2 * g_Pi / 5) * radius + center.y });
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5 * 3) * radius + center.x,sinf(2 * g_Pi / 5 * 3) * radius + center.y });
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5 * 5) * radius + center.x,sinf(2 * g_Pi / 5 * 5) * radius + center.y });
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5 * 2) * radius + center.x,sinf(2 * g_Pi / 5 * 2) * radius + center.y });
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5 * 4) * radius + center.x,sinf(2 * g_Pi / 5 * 4) * radius + center.y });
	SetColor(1,1,1);
	DrawPolygon(pentaPoints);
}
void DrawPlanets()
{
	for (int i{}; i < g_PlanetAmount; i++)
	{
		SetColor(g_planetColors[i].r/100.f,g_planetColors[i].g/100.f,g_planetColors[i].b/100.f);
		FillEllipse(g_planetPoints[i], 60, 60);
		SetColor(1, 1, 1);
		DrawEllipse(g_planetPoints[i], 60, 60, 2.f);
	}
}
#pragma endregion ownDefinitions