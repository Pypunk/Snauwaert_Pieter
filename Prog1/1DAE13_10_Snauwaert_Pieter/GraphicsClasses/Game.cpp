#include "pch.h"
#include <iostream>
#include "Game.h"
#include "Fraction.h"
#include "Light.h"
#include "DaeEllipse.h"
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitializeFractions();
	std::cout << "The sum of all the fraction values is: ";
	PrintFractionsSum();
	std::cout << std::endl;
	InitializeLights();
	InitializeDaeEllipses();
}

void Draw()
{
	ClearBackground(0, 0, 0);

	// Put your own draw statements here
	DrawFractions();
	DrawLights();
	DrawDaeEllipses();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	ActivateDaeEllipses(g_MousePos);
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
	DeleteFractions();
	DeleteLights();
	DeleteDaeEllipses();
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
	g_MousePos = Point2f{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		HitLights(g_MousePos);
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
void InitializeFractions()
{
	g_pFractions[0] = new Fraction{ 3,5 };
	g_pFractions[1] = new Fraction{ 2,5 };
	g_pFractions[2] = new Fraction{ 2,3 };
	g_pFractions[3] = new Fraction{ 2,4 };
	g_pFractions[4] = new Fraction{ 1,4 };
	g_pFractions[5] = new Fraction{ 1,3 };
}
void PrintFractionsSum()
{
	float sum{};
	for (int i{}; i < g_FractionsAmount; ++i)
	{
		sum += g_pFractions[i]->GetValue();
	}
	std::cout << sum;
}
void DrawFractions()
{
	const float size{ 25.f };
	Point2f position{ 10,size * g_FractionsAmount + 5.f };
	for (int i{}; i < g_FractionsAmount; ++i)
	{
		g_pFractions[i]->Draw(position, size);
		position.y -= size + 5;
	}
}
void DeleteFractions()
{
	for (int i{}; i < g_FractionsAmount; ++i)
	{
		delete g_pFractions[i];
		g_pFractions[i] = nullptr;
	}
}
void InitializeLights()
{
	const int cols{ 4 };
	const int rows{ 2 };
	Rectf posRect{ 150,10,50,30 };
	float minSize{ 20.f };
	float maxSize{ 50.f };
	for (int i{}; i < cols; ++i)
	{
		for (int j{}; j < rows; ++j)
		{
			posRect.width = GetRand(minSize, maxSize);
			g_pLights[GetIndex(j, i, 4)] = new Light{ posRect,GetRandColor() };
			posRect.left += posRect.width+5;
		}
		posRect.left = 150.f;
		posRect.bottom += posRect.height+5;
	}
}
void DrawLights()
{
	for (int i{}; i < g_LightsAmount; ++i)
	{
		g_pLights[i]->Draw();
	}
}
void DeleteLights()
{
	for (int i{}; i < g_LightsAmount; ++i)
	{
		delete g_pLights[i];
		g_pLights[i] = nullptr;
	}
}
void HitLights(const Point2f& p)
{
	for (int i{}; i < g_LightsAmount; ++i)
	{
		if (!g_pLights[i]->IsOn())
		{
			if (g_pLights[i]->IsHit(p))
			{
				++g_AmountOfOnLights;
				std::cout << g_AmountOfOnLights << " lights are on\n";
			}
		}
	}
}
void InitializeDaeEllipses()
{
	for (int i{}; i < g_DaeEllipseAmount; ++i)
	{
		Point2f position{ GetRand(0.f,g_WindowWidth),GetRand(0.f,g_WindowHeight) };
		g_pDaeEllipse[i] = new DaeEllipse{ position,GetRand(10.f,100.f),GetRand(10.f,100.f),GetRandColor() };
	}
}
void DrawDaeEllipses()
{
	for (int i{}; i < g_DaeEllipseAmount; ++i)
	{
		g_pDaeEllipse[i]->Draw();
	}
}
void ActivateDaeEllipses(const Point2f p)
{
	for (int i{}; i < g_DaeEllipseAmount; ++i)
	{
		g_pDaeEllipse[i]->ActivateTest(p);
	}
}
void DeleteDaeEllipses()
{
	for (int i{}; i < g_DaeEllipseAmount; ++i)
	{
		delete g_pDaeEllipse[i];
		g_pDaeEllipse[i] = nullptr;
	}
}
#pragma endregion ownDefinitions