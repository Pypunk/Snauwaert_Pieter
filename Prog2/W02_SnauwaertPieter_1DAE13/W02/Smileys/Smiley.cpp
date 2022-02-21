// -- Smiley.cpp file --
// Decide yourself about the necessary include directives
// #include .....
// ....
#include "pch.h"
#include "Texture.h"
#include "Smiley.h"
#include "utils.h"
// Static Texture data
Texture* Smiley::m_pSmileyTexture{ nullptr };
int Smiley::m_InstanceCounter{ 0 };

// Constructor
// Initializes the object, among others:
//	- Initializes the data members, the velocity gets a random value within the inclusive range[60, 180] and [-180, -60]
//	- Creates a texture object to load the image, only if it hasn’t been created before( !)
//  - Adapts the instance counter
Smiley::Smiley( const Point2f& position )
	:m_Position{position}
	,m_IsHighest{false}
	,m_IsInSafeArea{false}
	,m_IsSleeping{false}
	,m_Velocity{utils::GetRand(60.f,180.f),-utils::GetRand(60.f,180.f)}
{
	++m_InstanceCounter;
	if (!m_pSmileyTexture)
	{
		m_pSmileyTexture = new Texture{ "Resources/Smileys.png" };
	}
}

// Destructor
// Deletes the Texture object when this is the last Smiley that is being destroyed.
Smiley::~Smiley( )
{
	--m_InstanceCounter;
	if (m_InstanceCounter <= 1)
	{
		delete m_pSmileyTexture;
		m_pSmileyTexture = nullptr;
	}
}

// Draw
// Draws a part of the image on the window, which part depends on the state of the smiley:
// - If the smiley is sleeping then the sleeping smiley is drawn.
// - If the smiley is at the highest position, then the happy smiley is drawn.
// - If the smiley is not in the safe area, the scary smiley is drawn.
// - If none of the above conditions is met, the neutral smiley should be drawn.
void Smiley::Draw( )
{
	float textPos{};

	if (m_IsHighest)
	{
		textPos = 0.f;
	}
	if (m_IsSleeping)
	{
		textPos = 3.f;
	}
	if (!m_IsSleeping && !m_IsHighest)
	{
		textPos = 1.f;
	}
	if (!m_IsInSafeArea && !m_IsHighest)
	{
		textPos = 2.f;
	}

	Rectf srcRect{};
	srcRect.left = m_pSmileyTexture->GetWidth() / 4.f * textPos;
	srcRect.bottom = m_pSmileyTexture->GetHeight();
	srcRect.width = m_pSmileyTexture->GetWidth() / 4.f;
	srcRect.height = m_pSmileyTexture->GetHeight();

	m_pSmileyTexture->Draw(m_Position, srcRect);
}

// Update
// - When the smiley is not sleeping, the new position - using the velocity and elapsed seconds - is calculated.
// - The velocity changes sign when at this new position the smiley is outside the bounding rectangle (boundingRect)
// - Checks whether at this new position, it is located in the safe area and updates m_IsInSafeArea accordingly.
void Smiley::Update(float elapsedSec, const Rectf& boundingRect, const Rectf& safeRect)
{
	if (!m_IsSleeping)
	{
		m_Position.x += m_Velocity.x * elapsedSec;
		m_Position.y += m_Velocity.y * elapsedSec;
	}
	if (m_Position.y + m_pSmileyTexture->GetHeight() / 2.f <= boundingRect.bottom)
	{
		m_Velocity.y = -m_Velocity.y;
	}
	if (m_Position.y + m_pSmileyTexture->GetHeight() / 2.f >= boundingRect.height)
	{
		m_Velocity.y = -m_Velocity.y;
	}
	if (m_Position.x + (m_pSmileyTexture->GetWidth()/4.f)/2.f >= boundingRect.width)
	{
		m_Velocity.x = -m_Velocity.x;
	}
	if (m_Position.x + (m_pSmileyTexture->GetWidth() / 4.f) / 2.f <= boundingRect.left)
	{
		m_Velocity.x = -m_Velocity.x;
	}
	m_IsInSafeArea = IsInSafeArea(safeRect);
}

// HitTest
// If the value of the parameter pos is within the boundaries of the smiley’s circle,
// then the sleeping state of the smiley changes.
void Smiley::HitTest( const Point2f& pos )
{
	const float radius{ 25.f };
	Circlef shape{ m_Position.x + (m_pSmileyTexture->GetWidth() / 4.f) / 2.f,m_Position.y + m_pSmileyTexture->GetHeight() / 2.f,radius };
	if (utils::IsPointInCircle(pos, shape))
	{
		m_IsSleeping = !m_IsSleeping;
	}
}

// IsSleeping
// Getter of the m_IsSleeping data member
bool Smiley::IsSleeping( )
{
	return m_IsSleeping; 
}

// GetPosition
// Getter of the m_Position data member
Point2f Smiley::GetPosition( )
{
	return m_Position;
}

// SetHighest
// Setter of the m_IsHighest data member
void Smiley::SetHighest( bool isHighest )
{
	if (!m_IsSleeping)
	{
		m_IsHighest = isHighest;
	}
}

// IncreaseSpeed
// Changes the speed 5% up
void Smiley::IncreaseSpeed( )
{
	m_Velocity.x += 0.05f*m_Velocity.x;
	m_Velocity.y += 0.05f*m_Velocity.y;
}

// DecreaseSpeed
// Changes the speed 5% down
void Smiley::DecreaseSpeed( )
{
	m_Velocity.x -= 0.05f * m_Velocity.x;
	m_Velocity.y -= 0.05f * m_Velocity.y;
}

// IsInSafeArea
// Returns true when the smiley is completely inside the safe area as indicated by safeRect
bool Smiley::IsInSafeArea( const Rectf& safeRect )
{
	const float radius{ 25.f };
	Circlef shape{ m_Position.x + (m_pSmileyTexture->GetWidth() / 4.f) / 2.f,m_Position.y + m_pSmileyTexture->GetHeight() / 2.f,radius };
	return utils::IsOverlapping(safeRect, shape); // change this later
}



