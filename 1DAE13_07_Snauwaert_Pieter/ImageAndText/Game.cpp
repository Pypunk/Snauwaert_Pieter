#include "pch.h"
#include "Game.h"
#include <iostream>
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	bool successfull{ TextureFromFile("Resources/DAE.png", g_DAELogo) };
	if (!successfull)std::cout << "Loading png failed\n";

	successfull = TextureFromString("Hello Darkness My Old Friend", "Resources/DIN-Light.otf", 28, Color4f{ 1,0,0,1 }, g_SomeText);
	if (!successfull)std::cout << "Loading text failed\n";
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	Point2f position{ 10,10 };
	DrawTexture(g_DAELogo, position);
	position.y = 150.f;
	DrawTexture(g_SomeText, position);

	Rectf destinationRect{};
	destinationRect.bottom = 250.f;
	destinationRect.left = 10.f;
	destinationRect.width = 150.f;
	destinationRect.height = 15.f;
	DrawTexture(g_DAELogo, destinationRect);

	destinationRect.bottom = 250.f;
	destinationRect.left = 210.f;
	destinationRect.width = g_DAELogo.width/2;
	destinationRect.height = g_DAELogo.height/2;
	DrawTexture(g_DAELogo, destinationRect);
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
	DeleteTexture(g_DAELogo);
	DeleteTexture(g_SomeText);
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

#pragma endregion ownDefinitions