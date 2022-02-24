#pragma once
class Texture;
class Sprite
{
public:
	Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale);
	~Sprite();
	void Update(float elapsedSec);
	void Draw(const Point2f& pos);
	float GetFrameWith();
	float GetFrameHeight();
	void SetLeft(bool isLeft);
	void SetCurrentRow(int newRow);
	void ToggleOff();
private:
	Texture* m_pTexture;
	int m_Cols;
	int m_Rows;
	int m_CurrentRow;
	float m_FrameSec;
	float m_AccuSec;
	int m_ActFrame;
	float m_Scale;
	bool m_Left;
};

