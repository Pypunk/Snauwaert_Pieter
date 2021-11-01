#include "pch.h"
#include "Game.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.1f, 0.1f, 0.5f);

	// Put your own draw statements here
	DrawDiceThrows();
	DrawDoubleDiceThrows();
}

void Update(float elapsedSec)
{
	int randDice{ GenerateRandomInt(1,6) };
	int randDice2{ GenerateRandomInt(1,6) };
	Update1Dice(randDice);
	Update2Dice(randDice,randDice2);
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
void DrawDiceThrows()
{
	Point2f position{};
	float yPos{};
	float whiteSpace{ 5.f };
	float height{ 23.f };
	float width{};
	for (int i{}; i < 6; i++)
	{
		SetColor(1, 0.3f, 0.3f);
		Rectf rect{};
		switch (i)
		{
		case 0:
			width = g_D1;
			yPos = whiteSpace;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 1:
			width = g_D2;
			yPos = height + whiteSpace * 2;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 2:
			width = g_D3;
			yPos = height * 2 + whiteSpace * 3;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 3:
			width = g_D4;
			yPos = height * 3 + whiteSpace * 4;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 4:
			width = g_D5;
			yPos = height * 4 + whiteSpace * 5;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 5:
			width = g_D6;
			yPos = height * 5 + whiteSpace * 6;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		}
		FillRect(rect);
		SetColor(0, 0, 0);
		DrawRect(rect);
	}

}
void DrawDoubleDiceThrows()
{
	Point2f position{0,g_WindowHeight/2-80.f};
	float yPos{};
	float whiteSpace{ 5.f };
	float height{ 23.f };
	float width{};
	for (int i{}; i < 11; i++)
	{
		SetColor(0.8f, 0.4f, 0.8f);
		Rectf rect{};
		switch (i)
		{
		case 0:
			width = g_DoubleD2;
			yPos = whiteSpace;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 1:
			width = g_DoubleD3;
			yPos = height + whiteSpace * 2;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 2:
			width = g_DoubleD4;
			yPos = height * 2 + whiteSpace * 3;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 3:
			width = g_DoubleD5;
			yPos = height * 3 + whiteSpace * 4;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 4:
			width = g_DoubleD6;
			yPos = height * 4 + whiteSpace * 5;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 5:
			width = g_DoubleD7;
			yPos = height * 5 + whiteSpace * 6;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 6:
			width = g_DoubleD8;
			yPos = height * 6 + whiteSpace * 7;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 7:
			width = g_DoubleD9;
			yPos = height * 7 + whiteSpace * 8;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 8:
			width = g_DoubleD10;
			yPos = height * 8 + whiteSpace * 9;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 9:
			width = g_DoubleD11;
			yPos = height * 9 + whiteSpace * 10;
			rect = Rectf{ position.x,position.y + yPos,width,height };
			break;
		case 10:
			width = g_DoubleD12;
			yPos = height * 10 + whiteSpace * 11;
			rect = Rectf{ position.x,position.y + yPos,width,height };
		}
		FillRect(rect);
		SetColor(0, 0, 0);
		DrawRect(rect);
	}
}
void Update1Dice(int dice)
{
	switch (dice)
	{
	case 1:
		g_D1++;
		break;
	case 2:
		g_D2++;
		break;
	case 3:
		g_D3++;
		break;
	case 4:
		g_D4++;
		break;
	case 5:
		g_D5++;
		break;
	case 6:
		g_D6++;
		break;
	}
}
void Update2Dice(int dice1, int dice2)
{
	int total{ dice1 + dice2 };
	switch (total)
	{
	case 2:
		g_DoubleD2++;
		break;
	case 3:
		g_DoubleD3++;
		break;
	case 4:
		g_DoubleD4++;
		break;
	case 5:
		g_DoubleD5++;
		break;
	case 6:
		g_DoubleD6++;
		break;
	case 7:
		g_DoubleD7++;
		break;
	case 8:
		g_DoubleD8++;
		break;
	case 9:
		g_DoubleD9++;
		break;
	case 10:
		g_DoubleD10++;
		break;
	case 11:
		g_DoubleD11++;
		break;
	case 12:
		g_DoubleD12++;
		break;
	}
}
// Define your own functions here
int GenerateRandomInt(int min, int max)
{
	return (rand() % (int)max) + min;
}
#pragma endregion ownDefinitions