#pragma once
#include <vector>
class Texture;
class Diamond
{
public:
	Diamond(float windowWidth, float windowHeight);
	~Diamond();

	void Update(float elapsedSec);
	void Draw() const;
	void Select(const Point2f& mousePos);
	void Reset();
private:
	float m_Angle;
	float m_Scale;
	Point2f m_Position;
	Point2f m_ResetPosition;
	bool m_Selected;
	std::vector<Point2f> m_Vertices;
	std::vector<Point2f> m_TransVertices;
	Texture* m_pTexture;
};

