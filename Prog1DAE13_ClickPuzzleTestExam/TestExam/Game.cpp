#include "pch.h"
#include "Game.h"
#include "Tile.h"
//Basic game functions
#pragma region gameFunctions											

void Start()
{
	// initialize game resources here
	const float size{ 128.f };
	CreateTiles(size);
	TextureFromFile("Resources/Names.png", g_AnimalName);
	g_AnimalNamePos = Rectf{ g_WindowWidth / 2.f - size,g_WindowHeight/2.f-size-30.f,size * 2.f,g_AnimalName.height / 6.f };
	g_Border = Rectf{ g_AnimalNamePos.left,g_AnimalNamePos.bottom + 30.f,size * 2.f,size * 2.f };
}

void Draw()
{
	ClearBackground(0, 0, 0);

	// Put your own draw statements here
	DrawTiles();
	g_SrcRect.width = g_AnimalName.width;
	g_SrcRect.height = g_AnimalName.height/6;
	g_SrcRect.bottom = g_SrcRect.height*g_CurrentAnimalFrame;
	g_SrcRect.left = 0.f;
	SetColor(1, 0, 0, 1);
	DrawRect(g_Border, 2.f);
	if (g_IsSolved)
	{
		DrawTexture(g_AnimalName, g_AnimalNamePos, g_SrcRect);
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if (g_pTiles[0]->GetCurrentAnimal() == g_pTiles[1]->GetCurrentAnimal()
		&& g_pTiles[1]->GetCurrentAnimal() == g_pTiles[2]->GetCurrentAnimal()
		&& g_pTiles[2]->GetCurrentAnimal() == g_pTiles[3]->GetCurrentAnimal())
	{
		g_CurrentAnimalFrame = g_pTiles[0]->GetCurrentAnimal() + 1;
		g_IsSolved = true;
		for (int i{}; i < g_AmountOfTiles; ++i)
		{
			g_pTiles[i]->Deactivate();
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
	DeleteTiles();
	DeleteTexture(g_AnimalName);
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
	case SDLK_r:
		for (int i{}; i < g_AmountOfTiles; ++i)
		{
			g_pTiles[i]->Randomize();
			g_IsSolved = false;
		}
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	for (int i{}; i < g_AmountOfTiles; ++i)
	{
		g_pTiles[i]->CheckActivation(mousePos);
	}
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	if (!g_IsSolved)
	{
		switch (e.button)
		{
		case SDL_BUTTON_LEFT:
			for (int i{}; i < g_AmountOfTiles; ++i)
			{
				g_pTiles[i]->CheckHit(mousePos);
			}
			break;
		}
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
void CreateTiles(float size)
{
	std::string path{};
	std::string jString{};
	Rectf positionRect{ g_WindowWidth / 2.f - size,g_WindowHeight / 2.f,size,size };
	for (int i{}; i < g_AmountOfTiles / 2; ++i)
	{
		for (int j{}; j < g_AmountOfTiles / 2; ++j)
		{
			jString = std::to_string(j);
			path = "Resources/Tiles" + std::to_string(i) + jString + ".png";
			g_pTiles[GetIndex(i, j, 2)] = new Tile(positionRect, path, 6);
			positionRect.left += size;
			g_pTiles[GetIndex(i, j, 2)]->Randomize();
		}
		positionRect.left = g_WindowWidth / 2.f - size;
		positionRect.bottom -= size;
	}
}
void DeleteTiles()
{
	for (int i{}; i < g_AmountOfTiles; ++i)
	{
		delete g_pTiles[i];
		g_pTiles[i] = nullptr;
	}
}
void DrawTiles()
{
	for (int i{}; i < g_AmountOfTiles; ++i)
	{
		g_pTiles[i]->Draw();
	}
}
#pragma endregion ownDefinitions