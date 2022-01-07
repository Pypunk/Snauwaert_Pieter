#pragma once
using namespace utils;
class Tile 
{
public:
	Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals );
	~Tile();
	void Draw();
	void CheckActivation(const Point2f& pos);
	bool CheckHit(const Point2f& pos);
	int GetCurrentAnimal( );
	void Deactivate();
	void Randomize( );

private:
	Rectf m_Shape;
	Texture m_Texture;
	int m_AmountOfAnimals;
	bool m_IsActive;
	int m_CurrentAnimal;
	Rectf m_HitRegionLeft;
	Rectf m_HitRegionRight;
};
