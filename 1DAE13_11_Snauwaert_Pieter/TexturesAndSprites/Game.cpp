#include "pch.h"
#include "Game.h"
#include "Sprite.h"
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	const float KnightFrameSec{ 1 / 10.f };
	const float TiboFrameSec{ 1 / 15.f };
	g_pSprite[0] = new Sprite{ "Sprites/RunningKnight.png",8,1,KnightFrameSec,5 };
	g_pSprite[1] = new Sprite{ "Sprites/RunningKnight.png",8,1,KnightFrameSec,3 };
	g_pSprite[2] = new Sprite{ "Sprites/RunningKnight.png",8,1,KnightFrameSec,2 };
	g_pSprite[3] = new Sprite{ "Sprites/Tibo.png",5,5,TiboFrameSec,0.5f };
	g_pSprite[4] = new Sprite{ "Sprites/Tibo.png",5,5,TiboFrameSec,0.3f };

	TextureFromFile("Resources/DAE.png", g_Texture[0]);
	TextureFromString("Hello", "Resources/DIN-Light.otf", 50, Color4f{ 1,1,0,0 }, g_Texture[1]);
}

void Draw()
{
	ClearBackground(0, 0, 0);

	// Put your own draw statements here
	Point2f position{ 50,g_WindowHeight / 2 };
	for (int i{}; i < g_AmountOfSprites; ++i)
	{
		g_pSprite[i]->Draw(position);
		position.x += 80.f;
	}
	Rectf destRect{ 20.f,80.f,g_Texture[0].width*0.5f,g_Texture[0].height*0.5f };
	for (int i{}; i < 3; ++i)
	{
		DrawTexture(g_Texture[0], destRect);
		destRect.left += g_Texture[0].width*0.5f+20.f;
	}
	destRect.left = 20.f;
	destRect.bottom = 20.f;
	destRect.width = g_Texture[1].width;
	destRect.height = g_Texture[1].height;

	for (int i{}; i < 3; ++i)
	{
		DrawTexture(g_Texture[1], destRect);
		destRect.left += g_Texture[1].width+10.f;
	}
}

void Update(float elapsedSec)
{
	// process input, do physics
	for (int i{}; i < g_AmountOfSprites; ++i)
	{
		g_pSprite[i]->Update(elapsedSec);
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
	for (int i{}; i < g_AmountOfSprites; ++i)
	{
		delete g_pSprite[i];
		g_pSprite[i] = nullptr;
	}
	for (int i{}; i < g_AmountOfTextures; ++i)
	{
		DeleteTexture(g_Texture[i]);
	}
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