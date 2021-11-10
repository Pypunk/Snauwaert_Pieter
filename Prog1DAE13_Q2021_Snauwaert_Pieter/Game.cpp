#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	PrintLetters();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	SetColor(g_Color);
	FillEllipse(g_Circle);
}

void Update(float elapsedSec)
{
	UpdateCircle();
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
	switch (key)
	{
	case SDLK_UP:
		if (g_CurrentState != CircleState::invisible)
		{
			if (g_Speed < 5)
			{
				g_Speed += 0.4f;
			}
			else
			{
				g_Speed = 5.f;
			}
		}
		std::cout << g_Speed;
		break;
	case SDLK_DOWN:
		if (g_CurrentState != CircleState::invisible)
		{
			if (g_Speed > 0.2f)
			{
				g_Speed -= 0.4f;
			}
			else
			{
				g_Speed = 0.2f;
			}
		}
		break;
		std::cout << g_Speed;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	g_MousePos = Point2f{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (g_CurrentState == CircleState::invisible)
		{
			CreateCircle();
		}
		break;
	default:
		break;
	}
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
void PrintLetters()
{
	int amountPerLine{};
	char letter{ 'a' };
	const char lastLetter{ 'z' };
	std::cout << "How many characters per line? ";
	std::cin >> amountPerLine;
	int counter{};
	while (letter <= lastLetter)
	{
		std::cout << letter;
		letter++;
		counter++;
		if (!(counter % amountPerLine))
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}
int GenerateRandomInt(int min, int max)
{
	return (rand() % int(max)) + min;
}
float GenerateRandomFloat(float min, float max)
{
	return ((rand()%int(max*100))+min*100)/100;
}
void CreateCircle()
{
	g_Circle.radiusX = 0;
	g_Circle.radiusY = 0;
	g_MaxRadius = float(GenerateRandomInt(50,100));
	g_Circle.center = g_MousePos;
	g_CurrentState = CircleState::growing;
	PrintState();
	g_Color = Color4f{ GenerateRandomFloat(0,256)/256,GenerateRandomFloat(0,256)/256,GenerateRandomFloat(0,256)/256,1.f };
}
void UpdateCircle()
{
	switch (g_CurrentState)
	{
	case CircleState::invisible:
		g_Circle.radiusX = 0;
		g_Circle.radiusY = 0;
		break;
	case CircleState::growing:
		g_Circle.radiusX+=g_Speed;
		g_Circle.radiusY+=g_Speed;
		if (g_Circle.radiusX >= g_MaxRadius)
		{
			g_CurrentState = CircleState::shrinking;
			PrintState();
		}
		break;
	case CircleState::shrinking:
		if (g_Circle.radiusX < 6.f)
		{
			g_CurrentState = CircleState::invisible;
			PrintState();
		}
		g_Circle.radiusX-=g_Speed;
		g_Circle.radiusY-=g_Speed;
		break;
	}
	CheckCollision();
}
void CheckCollision()
{
	if (g_Circle.center.y + g_Circle.radiusY > g_WindowHeight
		|| g_Circle.center.y - g_Circle.radiusY < 0
		|| g_Circle.center.x - g_Circle.radiusX < 0
		|| g_Circle.center.x + g_Circle.radiusX > g_WindowWidth)
	{
		std::cout << "Ouch!\n";
		g_Color = Color4f{ 1,0,0,1 };
		g_CurrentState = CircleState::shrinking;
		PrintState();
	}
}
void PrintState()
{
	switch (g_CurrentState)
	{
	case CircleState::invisible:
		std::cout << "Waiting State\n\n";
		break;
	case CircleState::growing:
		std::cout << "Growing State\n";
		std::cout << "The maximum radius is " << g_MaxRadius << std::endl;
		std::cout << " g_Speed = " << g_Speed << std::endl << std::endl;
		break;
	case CircleState::shrinking:
		std::cout << "Shrinking State\n";
		std::cout << "The maximum radius is " << g_MaxRadius << std::endl;
		std::cout << " g_Speed = " << g_Speed << std::endl << std::endl;
		break;
	}
}
#pragma endregion ownDefinitions