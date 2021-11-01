#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	GenerateRect();
}

void Draw()
{
	ClearBackground();
	SetColor(g_Color);
	FillRect(g_Bomb);
	// Put your own draw statements here
	if (g_Clicked)
	{
		g_Color = Color4f{ 0,0,0,0.5f };
		CreateExplosion();
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if (g_Clicked)
	{
		g_NrFrames++;
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
	mousePos.x = float(e.x);
	mousePos.y = float(g_WindowHeight - e.y);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		if (IsPointInRect(mousePos, g_Bomb))
		{
			g_Clicked = true;
		}
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
void GenerateRect()
{
	g_Color = Color4f{ 0,0,0,1 };
	const float width{ 50.f };
	g_Bomb.left = g_WindowWidth/2 - width / 2;
	g_Bomb.bottom = g_WindowHeight/2 - width / 2;
	g_Bomb.height = width;
	g_Bomb.width = width;
}
bool IsPointInRect(const Point2f& p, const Rectf& r)
{
	return (p.x >= r.left && p.x <= r.left + r.width &&
		p.y >= r.bottom && p.y <= r.bottom + r.height);
}
void CreateExplosion()
{
	const float width{ 50.f };
	const Rectf ExplosionRectTopLeft{ g_Bomb.left - g_NrFrames,g_Bomb.bottom + g_NrFrames,width,width };
	const Rectf ExplosionRectBottomLeft{ g_Bomb.left - g_NrFrames,g_Bomb.bottom - g_NrFrames,width,width };
	const Rectf ExplosionRectTopRight{ g_Bomb.left + g_NrFrames,g_Bomb.bottom + g_NrFrames,width,width };
	const Rectf ExplosionRectBottomRight{ g_Bomb.left + g_NrFrames,g_Bomb.bottom - g_NrFrames,width,width };
	SetColor(1, 0, 0, 1);
	FillRect(ExplosionRectTopLeft);
	FillRect(ExplosionRectBottomLeft);
	FillRect(ExplosionRectTopRight);
	FillRect(ExplosionRectBottomRight);
	if (ExplosionRectBottomRight.bottom+ExplosionRectBottomRight.height <= 0)
	{
		g_Clicked = false;
		g_NrFrames = 0;
		GenerateRect();
	}
}
#pragma endregion ownDefinitions