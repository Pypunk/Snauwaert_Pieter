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
	ClearBackground();

	// Put your own draw statements here
	TestDrawSquares();
	TestDrawTriangles();
	TestDrawPentagram();
	TestDrawRadiantRect();
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
void DrawSquares(Point2f position, float squareSize, float amount)
{
	float newSize{};
	for (int i{}; i < amount; ++i)
	{
		SetColor(0, 0, 0);
		Rectf rect{ position.x,position.y,newSize,newSize };
		DrawRect(rect);
		position.x += squareSize / amount / 2;
		position.y += squareSize / amount / 2;
		newSize -= squareSize / amount;
	}
}
void TestDrawSquares()
{
	float squareWidth{ 100 };
	float amount{ 11 };
	Point2f position{ 50.f, g_WindowHeight-50.f };
	float prevSquareWidth{};
	DrawSquares(position, squareWidth, amount);
	prevSquareWidth = squareWidth;
	squareWidth = 70.f;
	position.x += squareWidth + 10.f;
	amount = 5;
	DrawSquares(position, squareWidth, amount);
	prevSquareWidth = squareWidth;
	squareWidth = 50.f;
	position.x += squareWidth;
	amount = 4;
	DrawSquares(position, squareWidth, amount);
}
void DrawEguilateralTriangle(Point2f position, float size, bool filled)
{
	if (filled)
	{
		FillTriangle(position, Point2f{ position.x + size,position.y }, Point2f{ position.x + size/2,position.y + size });
	}
	else
	{
		DrawTriangle(position, Point2f{ position.x + size,position.y }, Point2f{ position.x + size/2,position.y + size });
	}
}
void TestDrawTriangles()
{
	float size{ 50.f };
	float offSet{ 10.f };
	Point2f trianglePos{ g_WindowWidth / 2,g_WindowHeight-size-offSet };
	for (int i{}; i < 3; ++i)
	{
		switch (i)
		{
		case 0:
			SetColor(1, 0, 0, 1);
			break;
		case 1:
			SetColor(0, 1, 0, 1);
			break;
		case 2:
			SetColor(0, 0, 1, 1);
			break;
		}
		DrawEguilateralTriangle(trianglePos, size);
		trianglePos.x += offSet;
		trianglePos.y += offSet;
		size -= 20.f;
	}
	size = 25;
	trianglePos = Point2f{ g_WindowWidth / 2+size*2+10.f,g_WindowHeight - size*2 - offSet };
	for (int i{}; i < 3; ++i)
	{
		SetColor(0, 1, 1, 1);
		switch (i)
		{
		case 1:
			trianglePos.x += size / 2;
			trianglePos.y += size;
			SetColor(1, 0, 1, 1);
			break;
		case 2:
			trianglePos.x += size / 2;
			trianglePos.y -= size;
			SetColor(1, 1, 0, 1);
			break;
		}
		DrawEguilateralTriangle(trianglePos, size);
		SetColor(0, 0, 0, 1);
		DrawEguilateralTriangle(trianglePos, size, false);
	}
}
void DrawPentagram(Point2f center, float radius)
{
	std::vector<Point2f> pentaPoints{};
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5) * radius + center.x,sinf(2 * g_Pi / 5) * radius + center.y });
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5 * 3) * radius + center.x,sinf(2 * g_Pi / 5 * 3) * radius + center.y });
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5 * 5) * radius + center.x,sinf(2 * g_Pi / 5 * 5) * radius + center.y });
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5 * 2) * radius + center.x,sinf(2 * g_Pi / 5 * 2) * radius + center.y });
	pentaPoints.push_back(Point2f{ cosf(2 * g_Pi / 5 * 4) * radius + center.x,sinf(2 * g_Pi / 5 * 4) * radius + center.y });
	DrawPolygon(pentaPoints);
}
void TestDrawPentagram()
{
	float radius{ 30.f };
	Point2f center{ g_WindowWidth/2+radius,g_WindowHeight/2+radius };
	SetColor(1, 0, 0, 1);
	DrawPentagram(center, radius);
	
	center.x += radius * 2;
	radius = 20.f;
	SetColor(0, 0, 1, 1);
	DrawPentagram(center, radius);
}
void DrawRadiantRect(Point2f position, float width, float height, Color4f startColor, Color4f endColor)
{
	const float gradientIncrement{ 0.025f };
	for (int i{}; i < width; ++i)
	{
		SetColor(startColor);
		DrawLine(position, Point2f{ position.x,position.y + height });
		if (startColor.r < endColor.r)
		{
			startColor.r += gradientIncrement / width * i;
		}
		else
		{
			startColor.r -= gradientIncrement / width * i;
		}
		if (startColor.g < endColor.g)
		{
			startColor.g += gradientIncrement / width * i;;
		}
		else
		{
			startColor.g -= gradientIncrement / width * i;;
		}
		if (startColor.b < endColor.b)
		{
			startColor.b += gradientIncrement / width * i;;
		}
		else
		{
			startColor.b -= gradientIncrement / width * i;;
		}
		if (startColor.a < endColor.a)
		{
			startColor.a += gradientIncrement / width * i;;
		}
		else
		{
			startColor.a -= gradientIncrement / width * i;;
		}
		position.x++;
	}
}
void TestDrawRadiantRect()
{
	const Color4f black{ 0,0,0,1 };
	const Color4f white{ 1,1,1,1 };
	DrawRadiantRect(Point2f{ 0,0 }, 100.f, 20.f, black, white);
	const Color4f red{ 1,0,0,1 };
	const Color4f purple{ 1,0,1,1 };
	DrawRadiantRect(Point2f{ 0,30.f }, 200.f, 40.f, red, purple);
	const Color4f yellow{ 1,0.7f,0.6f,1 };
	const Color4f orange{ 1,0.7f,0,1 };
	DrawRadiantRect(Point2f{ 0,80.f }, 200.f, 40.f, yellow, orange);
	const Color4f blue{ 0,0,1,1 };
	DrawRadiantRect(Point2f{ 0,130.f }, 300.f, 40.f, blue, red);
}
#pragma endregion ownDefinitions