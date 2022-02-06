#include "pch.h"
#include "Game.h"
#include "Vehicle.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	TextureFromFile("Resources/street.PNG", g_StreetTexture);
	g_ChickenPos = Point2f{ g_WindowWidth / 2,g_WindowHeight - 20.f };
	TextureFromFile("Resources/chicken.bmp", g_ChickenTexture);
	float yPos{43.f};
	for (int i{}; i < g_AmountOfVehicles; ++i)
	{
		g_pVehicles[i] = new Vehicle{ GetRand(1,g_AmountOfVehicles) };
		g_pVehicles[i]->SetYPos(yPos);
		yPos += 45.f;
	}
	g_DestRect.bottom = g_ChickenPos.y;
	g_DestRect.left = g_ChickenPos.x;
	g_CurrentState = GameState::reset;
	PrintInfo();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	const Point2f streetPos{ 0,0 };
	DrawTexture(g_StreetTexture, streetPos);
	DrawChicken();
	DrawVehicles();
	DrawTexts();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateVehicles(elapsedSec);
	UpdateChicken(elapsedSec);
}

void End()
{
	// free game resources here
	DeleteTexture(g_StreetTexture);
	DeleteTexture(g_Text);
	DeleteTexture(g_ChickenTexture);
	for (int i{}; i < g_AmountOfVehicles; ++i)
	{
		delete g_pVehicles[i];
		g_pVehicles[i] = nullptr;
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
	case SDLK_r:
		ResetGame();
		g_CurrentState = GameState::play;
		break;
	case SDLK_p:
		if (g_CurrentState == GameState::play)
		{
			DeleteTexture(g_Text);
			TextureFromString("Pause", "Resources/consola.ttf", g_FontSize, Color4f{ 1,1,1,1 }, g_Text);
			g_CurrentState = GameState::pause;
		}
		else if (g_CurrentState == GameState::pause)
		{
			g_CurrentState = GameState::play;
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
void ResetGame()
{
	g_CurrentState = GameState::reset;
	g_ChickenPos = Point2f{ g_WindowWidth / 2,g_WindowHeight - 20.f };
	g_Speed = 100.f;
	for (int i{}; i < g_AmountOfVehicles; ++i)
	{
		g_pVehicles[i]->Reset();
		g_pVehicles[i]->SetActive(true);
	}
	g_DestRect.bottom = g_ChickenPos.y;
	g_DestRect.left = g_ChickenPos.x;
}
void DrawChicken()
{
	int texturePos{ 0 };
	switch (g_CurrentDirection)
	{
	case Direction::left:
		texturePos = 1;
		break;
	case Direction::right:
		texturePos = 2;
		break;
	case Direction::front:
		texturePos = 0;
		break;
	}
	Rectf srcRect{};
	srcRect.width = g_ChickenTexture.width / 3.f;
	srcRect.height = g_ChickenTexture.height;
	srcRect.bottom = srcRect.height;
	srcRect.left = srcRect.width * texturePos;

	const float scale{ 0.5f };
	g_DestRect.width = srcRect.width * scale;
	g_DestRect.height = srcRect.height * scale;
	g_DestRect.bottom = g_ChickenPos.y;
	g_DestRect.left = g_ChickenPos.x;
	DrawTexture(g_ChickenTexture, g_DestRect, srcRect);
}
void DrawVehicles()
{
	for (int i{}; i < g_AmountOfVehicles; ++i)
	{
		g_pVehicles[i]->Draw();
	}
}
void DrawTexts()
{
	if (g_CurrentState != GameState::play)
	{
		Point2f position{ g_WindowWidth / 2.f - g_Text.width / 2.f,g_WindowHeight / 2.f - g_Text.height / 2.f };
		Rectf rect{ position.x,position.y,g_Text.width,g_Text.height };
		SetColor(0, 0, 0, 0.5f);
		FillRect(rect);
		DrawTexture(g_Text, rect);
	}
}
void UpdateVehicles(float elapsedSec)
{
	for (int i{}; i < g_AmountOfVehicles; ++i)
	{
		g_pVehicles[i]->Update(elapsedSec, g_WindowWidth);
		if (g_pVehicles[i]->IsIntersecting(GetMiddle(g_DestRect)))
		{
			g_CurrentState = GameState::lose;
			DeleteTexture(g_Text);
			TextureFromString("The chicken died!", "Resources/consola.ttf", g_FontSize, Color4f{ 1,1,1,1 }, g_Text);
			g_pVehicles[i]->SetActive(false);
		}
	}
}
void UpdateChicken(float elapsedSec)
{
	if (g_CurrentState != GameState::lose)
	{
		const Uint8* pStates = SDL_GetKeyboardState(nullptr);
		if (g_CurrentState != GameState::win)
		{
			if (pStates[SDL_SCANCODE_RIGHT])
			{
				g_ChickenPos.x += g_Speed * elapsedSec;
				g_CurrentDirection = Direction::right;
			}
			if (pStates[SDL_SCANCODE_LEFT])
			{
				g_ChickenPos.x -= g_Speed * elapsedSec;
				g_CurrentDirection = Direction::left;
			}
			if (pStates[SDL_SCANCODE_DOWN])
			{
				g_ChickenPos.y -= g_Speed * elapsedSec;
				g_CurrentDirection = Direction::front;
			}
		}
	}
	if (GetMiddle(g_DestRect).y < 21.5f)
	{
		g_CurrentState = GameState::win;
		DeleteTexture(g_Text);
		TextureFromString("The chicken survived!", "Resources/consola.ttf", g_FontSize, Color4f{ 1,1,1,1 }, g_Text);
	}
}
void PrintInfo()
{
	std::cout << "-Chicken Game-\n";
	std::cout << "Press the arrow keys to move the chicken, we cant move back up the road\n";
	std::cout << "Press the r key to start or restart the game\n";
	std::cout << "Have fun!\n";
}
#pragma endregion ownDefinitions