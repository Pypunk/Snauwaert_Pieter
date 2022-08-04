#include "pch.h"
#include "Diamond.h"
#include "Matrix2x3.h"
#include "utils.h"
#include "Texture.h"

Diamond::Diamond(float windowWidth, float windowHeight)
	:m_Angle{}
	, m_Scale{1}
	, m_Position{utils::GetRand(0.f,windowWidth),utils::GetRand(0.f,windowHeight)}
	,m_Selected{false}
	,m_pTexture{new Texture{"Resources/Images/Diamond.png"}}
{
	const float size{ 48.f };
	m_Vertices.push_back(Point2f{ size / 2.f,0.f });
	m_Vertices.push_back(Point2f{ size,size / 2.f });
	m_Vertices.push_back(Point2f{ size / 2.f,size });
	m_Vertices.push_back(Point2f{ 0,size / 2.f });
	m_TransVertices = m_Vertices;
	m_ResetPosition = m_Position;
}

Diamond::~Diamond()
{
	delete m_pTexture;
}

void Diamond::Update(float elapsedSec)
{
	if (m_Selected)
	{
		const Uint8* pStates = SDL_GetKeyboardState(nullptr);
		if (pStates[SDL_SCANCODE_A])
		{
			m_Angle -= 60.f * elapsedSec;
		}
		if (pStates[SDL_SCANCODE_D])
		{
			m_Angle += 60.f * elapsedSec;
		}
		if (pStates[SDL_SCANCODE_W])
		{
			m_Scale *= 1 + 3.f * elapsedSec;
		}
		if (pStates[SDL_SCANCODE_S])
		{
			m_Scale /= 1 + 3.f * elapsedSec;
		}
		if (pStates[SDL_SCANCODE_UP])
		{
			m_Position.y += 120.f * elapsedSec;
		}
		if (pStates[SDL_SCANCODE_DOWN])
		{
			m_Position.y -= 120.f * elapsedSec;
		}
		if (pStates[SDL_SCANCODE_LEFT])
		{
			m_Position.x -= 120.f * elapsedSec;
		}
		if (pStates[SDL_SCANCODE_RIGHT])
		{
			m_Position.x += 120.f * elapsedSec;
		}
	}
	const float size{ 48.f };
	Matrix2x3 TranslateMat{};
	TranslateMat.SetAsTranslate(m_Position.x, m_Position.y);
	Matrix2x3 RotMat{};
	RotMat.SetAsRotate(m_Angle);
	Matrix2x3 ScaleMat{};
	ScaleMat.SetAsScale(m_Scale);
	Matrix2x3 originMat{};
	originMat.SetAsTranslate(-size / 2.f, -size / 2.f);
	Matrix2x3 TRSMat{ originMat.Inverse() * TranslateMat * RotMat * ScaleMat * originMat };
	for (int i{}; i < m_Vertices.size(); ++i)
	{
		m_TransVertices[i] = TRSMat.Transform(m_Vertices)[i];
	}
}

void Diamond::Draw() const
{
	const float size{ 48.f };
	if (m_Selected)
	{
		utils::SetColor(Color4f{ 1,0,0,1 });
	}
	else
	{
		utils::SetColor(Color4f{ 0,0,1,1 });
	}
	glPushMatrix();
	glTranslatef(size / 2.f, size / 2.f, 1.f);
	glTranslatef(m_Position.x, m_Position.y, 0.f);
	glRotatef(m_Angle, 0.f, 0.f, 1.f);
	glScalef(m_Scale, m_Scale, 1.f);
	glTranslatef(-size / 2.f, -size / 2.f, 0.f);
	m_pTexture->Draw();
	glPopMatrix();
	utils::DrawPolygon(m_TransVertices, true, 3.f);
}

void Diamond::Select(const Point2f& mousePos)
{
	if (utils::IsPointInPolygon(mousePos, m_TransVertices))
	{
		m_Selected = !m_Selected;
	}
}

void Diamond::Reset()
{
	if (m_Selected)
	{
		m_Position = m_ResetPosition;
		m_Angle = 0.f;
		m_Scale = 1.f;
	}
}
