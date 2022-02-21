#include "pch.h"
#include "Card.h"
#include "Texture.h"

Card::Card(Suit suit, int rank)
	:m_Suit{suit}
	,m_Rank{rank}
	,m_MinRank{1}
	,m_MaxRank{13}
{
	m_pTexture = new Texture{ GetImagePath(m_Suit,m_Rank) };
	m_Width = m_pTexture->GetWidth();
	m_Height = m_pTexture->GetHeight();
}

Card::Card(const Card& card)
	:m_Suit{card.m_Suit}
	,m_Rank{card.m_Rank}
	,m_MinRank{card.m_MinRank}
	,m_MaxRank{card.m_MaxRank}
	,m_Width{card.m_Width}
	,m_Height{card.m_Height}
{
	m_pTexture = new Texture{ GetImagePath(m_Suit,m_Rank) };
}

Card::~Card()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}

void Card::Draw(const Rectf& destRect) const
{
	m_pTexture->Draw(destRect);
}

float Card::GetWidth() const
{
	return m_Width;
}

float Card::GetHeight() const
{
	return m_Height;
}

std::string Card::GetImagePath(Suit suit, int rank) const
{
	std::string cardString{ "Resources/Cards/" };
	cardString += std::to_string(int(m_Suit) * 100 + m_Rank) + ".png";
	return cardString;
}
