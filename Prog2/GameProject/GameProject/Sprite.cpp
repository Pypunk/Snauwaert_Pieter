#include "pch.h"
#include "Sprite.h"
#include "utils.h"
#include "Texture.h"

Sprite::Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale)
	:m_Cols{nrCols}
	,m_Rows{nrRows}
	,m_FrameSec{frameSec}
	,m_Scale{scale}
	,m_AccuSec{0}
	,m_ActFrame{0}
	,m_Left{false}
	,m_CurrentRow{1}
{
	m_pTexture = new Texture{ filename };
}

Sprite::~Sprite()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void Sprite::Update(float elapsedSec)
{
	m_AccuSec += elapsedSec;
	if (m_AccuSec > m_FrameSec)
	{
		++m_ActFrame %= (m_Cols*m_Rows);
		m_AccuSec -= m_FrameSec;
	}
}

void Sprite::Draw(const Point2f& pos)
{
	Rectf srcRect{};
	srcRect.width = GetFrameWith();
	srcRect.height = GetFrameHeight();
	srcRect.left = m_ActFrame * srcRect.width;
	srcRect.bottom = srcRect.height*m_CurrentRow;

	Rectf destRect{};
	destRect.bottom = pos.y;
	destRect.left = pos.x;
	destRect.width = srcRect.width * m_Scale;
	destRect.height = srcRect.height * m_Scale;

	if (m_Left)
	{
		glPushMatrix();
		glScalef(-1, 1, 1);
		destRect.left = -pos.x-destRect.width;
		m_pTexture->Draw(destRect, srcRect);
		glPopMatrix();
	}
	else
	{
		m_pTexture->Draw(destRect, srcRect);
	}
}

float Sprite::GetFrameWith()
{
	return m_pTexture->GetWidth() / m_Cols;
}

float Sprite::GetFrameHeight()
{
	return m_pTexture->GetHeight() / m_Rows;
}

void Sprite::SetLeft(bool isLeft)
{
	m_Left = isLeft;
}

void Sprite::SetCurrentRow(int newRow)
{
	m_CurrentRow = newRow;
}

void Sprite::ToggleOff()
{
	m_ActFrame = 0;
}
