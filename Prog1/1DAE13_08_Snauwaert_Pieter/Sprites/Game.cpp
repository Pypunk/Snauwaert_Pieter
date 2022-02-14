#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											

void Start()
{
	// initialize game resources here
	InitKnight();
	InitTibo();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawKnight();
	DrawTibo();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateKnight(elapsedSec);
	UpdateTibo(elapsedSec);
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
	DeleteTexture(g_KnightSprite.texture);
	DeleteTexture(g_TiboSprite.texture);
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
void InitKnight()
{
	bool isCreationOk{};
	isCreationOk = TextureFromFile("Sprites/RunningKnight.png", g_KnightSprite.texture);
	if (!isCreationOk)
	{
		std::cout << "Failed to load image\n";
	}
	g_KnightSprite.cols = 8;
	g_KnightSprite.frames = 8;
	g_KnightSprite.currentFrame = 0;
	g_KnightSprite.accumulatedTime = 0.f;
	g_KnightSprite.frameTime = 1 / 10.f;
}
void UpdateKnight(float elapsedSec)
{
	g_KnightSprite.accumulatedTime += elapsedSec;
	if (g_KnightSprite.accumulatedTime > g_KnightSprite.frameTime)
	{
		++g_KnightSprite.currentFrame %= g_KnightSprite.frames;
		g_KnightSprite.accumulatedTime -= g_KnightSprite.frameTime;
	}
	g_KnightPosition += g_KnightSpeed * elapsedSec;
	g_KnightPosition = float(int(g_KnightPosition) % int(g_WindowWidth));
}
void DrawKnight()
{
	Rectf srcRect{};
	srcRect.width = g_KnightSprite.texture.width / g_KnightSprite.cols;
	srcRect.height = g_KnightSprite.texture.height;
	srcRect.left = g_KnightSprite.currentFrame * srcRect.width;
	srcRect.bottom = srcRect.height;

	const float scale{ 5.f };
	const float border{ 10.f };
	Rectf destRect{};
	destRect.left = g_KnightPosition;
	destRect.bottom = g_WindowHeight - border - (g_KnightSprite.texture.height * scale);
	destRect.width = srcRect.width * scale;
	destRect.height = srcRect.height * scale;
	DrawTexture(g_KnightSprite.texture, destRect, srcRect);
}
void InitTibo()
{
	bool isCreationOk{};
	isCreationOk = TextureFromFile("Sprites/Tibo.png", g_TiboSprite.texture);
	if (!isCreationOk)
	{
		std::cout << "Failed to load image\n";
	}
	g_TiboSprite.cols = 5;
	g_TiboSprite.frames = 25;
	g_TiboSprite.currentFrame = 0;
	g_TiboSprite.accumulatedTime = 0.f;
	g_TiboSprite.frameTime = 1 / 15.f;
}
void UpdateTibo(float elapsedSec)
{
	g_TiboSprite.accumulatedTime += elapsedSec;
	if (g_TiboSprite.accumulatedTime > g_TiboSprite.frameTime)
	{
		++g_TiboSprite.currentFrame %= g_TiboSprite.frames;
		g_TiboSprite.accumulatedTime -= g_TiboSprite.frameTime;
	}
}
void DrawTibo()
{
	Rectf srcRect{};
	srcRect.width = g_TiboSprite.texture.width / g_TiboSprite.cols;
	srcRect.height = g_TiboSprite.texture.height / g_TiboSprite.cols;
	srcRect.left = (g_TiboSprite.currentFrame % g_TiboSprite.cols) * srcRect.width;
	srcRect.bottom = (g_TiboSprite.currentFrame / g_TiboSprite.cols + 1) * srcRect.height;

	const float border{ 10.f };
	const float scale{ 1.f };
	Rectf destRect{};
	destRect.left = 0;
	destRect.bottom = 0;
	destRect.width = srcRect.width * scale;
	destRect.height = srcRect.height * scale;

	DrawTexture(g_TiboSprite.texture, destRect, srcRect);
}
#pragma endregion ownDefinitions