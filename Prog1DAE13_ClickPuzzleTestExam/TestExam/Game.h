#pragma once
using namespace utils;
class Tile;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 400 };
float g_WindowHeight{ 400 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfTiles{ 4 };
Tile* g_pTiles[g_AmountOfTiles]{ nullptr };
int g_CurrentAnimalFrame{ };
Texture g_AnimalName{};
Rectf g_AnimalNamePos{};
bool g_IsSolved;
Rectf g_SrcRect{};
Rectf g_Border{};
// Declare your own functions here
void CreateTiles(float size);
void DeleteTiles();
void DrawTiles();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
