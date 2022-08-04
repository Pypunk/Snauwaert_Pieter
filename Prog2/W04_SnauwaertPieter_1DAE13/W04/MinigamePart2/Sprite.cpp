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
	, m_CurrentRow{1}
	,m_IsFlipped{false}
{
	m_pTexture = new Texture{ filename };
}

Sprite::~Sprite()
{
	delete m_pTexture;
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
	srcRect.bottom = srcRect.height * m_CurrentRow;

	Rectf destRect{};
	destRect.bottom = pos.y;
	destRect.left = pos.x;
	destRect.width = srcRect.width * m_Scale;
	destRect.height = srcRect.height * m_Scale;

	m_pTexture->Draw(destRect, srcRect);
}

void Sprite::Draw(const Rectf& dstRect)
{
	Rectf srcRect{};
	srcRect.width = GetFrameWith();
	srcRect.height = GetFrameHeight();

	srcRect.left = m_ActFrame * srcRect.width;
	srcRect.bottom = srcRect.height * m_CurrentRow;

	if (m_IsFlipped)
	{
		const Point2f newPos{ -dstRect.left-dstRect.width,dstRect.bottom };
		glPushMatrix();
		glScalef(-1, 1, 1);
		m_pTexture->Draw(newPos, srcRect);
		glPopMatrix();
	}
	else
	{
		m_pTexture->Draw(dstRect, srcRect);
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

void Sprite::SetRow(int newRow)
{
	m_CurrentRow = newRow;
}

void Sprite::Flip(bool isFlipped)
{
	m_IsFlipped = isFlipped;
}
