#pragma once
class Texture;
class Sprite
{
public:
	Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale);
	~Sprite();
	void Update(float elapsedSec);
	void Draw(const Point2f& pos);
	void Draw(const Rectf& dstRect);
	float GetFrameWith();
	float GetFrameHeight();

	void SetRow(int newRow);
	void Flip(bool isFlipped);
private:
	Texture* m_pTexture;
	int m_Cols;
	int m_CurrentRow;
	int m_Rows;
	float m_FrameSec;
	float m_AccuSec;
	int m_ActFrame;
	float m_Scale;
	bool m_IsFlipped;
};

