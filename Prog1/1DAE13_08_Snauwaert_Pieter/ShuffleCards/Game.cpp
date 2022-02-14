#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	const int rows{ 4 };
	const int cols{ g_CardsAmount / rows };
	std::string cardString{};
	std::string jString{};
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			if (j + 1 < 10)
			{
				jString = std::to_string(0) + std::to_string(j + 1);
			}
			else
			{
				jString = std::to_string(j + 1);
			}
			cardString = "Resources/" + std::to_string(i+1) + jString + ".png";
			TextureFromFile(cardString, g_Cards[GetIndex(i, j, cols)]);
		}
	}
}

void Draw()
{
	ClearBackground();
	const int rows{ 4 };
	const int cols{ g_CardsAmount / rows };
	Rectf destRect{ 0,g_WindowHeight-g_Cards[0].height/3,g_Cards[0].width/3,g_Cards[0].height / 3 };
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			DrawTexture(g_Cards[GetIndex(i, j, cols)], destRect);
			destRect.left += destRect.width;
		}
		destRect.left = 0;
		destRect.bottom -= destRect.height;
	}
	// Put your own draw statements here
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
	const int rows{ 4 };
	const int cols{ g_CardsAmount / rows };
	for (int i{}; i < rows; ++i)
	{
		for (int j{}; j < cols; ++j)
		{
			DeleteTexture(g_Cards[i]);
		}
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
	switch (key)
	{
	case SDLK_s:
		Shuffle(g_Cards, sizeof(g_Cards) / sizeof(Texture), g_CardsAmount);
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
void Shuffle(Texture* pTextures, int size, int amount)
{
	for (int i{}; i < amount; ++i)
	{
		int idx1{ GetRandInt(1,size) };
		int idx2{ GetRandInt(1,size) };
		if (idx1 == idx2)
		{
			idx2 = GetRandInt(1, size);
		}
		Swap(pTextures, idx1, idx2);
	}
}
void Swap(Texture* pTextures, int idx1, int idx2)
{
	const Texture temp{ pTextures[idx1 - 1] };
	pTextures[idx1 - 1] = pTextures[idx2 - 1];
	pTextures[idx2 - 1] = temp;
}
#pragma endregion ownDefinitions