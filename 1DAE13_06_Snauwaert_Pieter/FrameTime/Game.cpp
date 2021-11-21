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
	DrawBall();
	DrawFreeFall();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_nrFrame++;
	g_AccumulatedTime += elapsedSec;
	if (!(g_nrFrame % 100))
	{
		std::cout << "Number of frames: " << g_nrFrame << " AccumulatedTime: " << g_AccumulatedTime << " FrameRate: " << g_nrFrame / g_AccumulatedTime << std::endl;
	}
	UpdateBall(elapsedSec);
	UpdateFreeFall(elapsedSec);
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
	case SDLK_s:
		switch (g_CurrentState)
		{
		case FreeFallState::stationary:
			g_CurrentState = FreeFallState::falling;
			break;
		case FreeFallState::falling:
			ResetFreeFall();
			break;
		}
		break;
	}
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
void DrawBall()
{
	SetColor(1, 0, 0, 1);
	FillCircle(g_Ball);
}
void UpdateBall(float elapsedSec)
{
	g_Ball.center.x += g_BallVelocity.x*elapsedSec;
	g_Ball.center.y += g_BallVelocity.y*elapsedSec;
	if (g_Ball.center.x-g_Ball.radius <= 0 || g_Ball.center.x+g_Ball.radius >= g_WindowWidth)
	{
		g_BallVelocity.x *= -1;
	}
	if (g_Ball.center.y-g_Ball.radius <= 0 || g_Ball.center.y+g_Ball.radius >= g_WindowHeight)
	{
		g_BallVelocity.y *= -1;
	}
}
void DrawFreeFall()
{
	SetColor(1, 1, 0, 1);
	FillRect(g_FreeFallRect);
}
void UpdateFreeFall(float elapsedSec)
{
	switch (g_CurrentState)
	{
	case FreeFallState::falling:
		g_FreeFallVelocity += g_Gravity * elapsedSec;
		g_FreeFallRect.bottom += g_FreeFallVelocity * elapsedSec;
		break;
	}
	if (g_FreeFallRect.bottom + g_FreeFallRect.height < 0)
	{
		ResetFreeFall();
	}
}
void ResetFreeFall()
{
	g_FreeFallRect.bottom = g_WindowHeight - g_FreeFallRect.height;
	g_CurrentState = FreeFallState::stationary;
	g_FreeFallVelocity = 0;
}
#pragma endregion ownDefinitions