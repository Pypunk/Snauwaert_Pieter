#pragma once
#include "DaeShape.h"
#include "Vector2f.h"

class DaeEllipse  : public DaeShape
{
public:
	DaeEllipse( const Point2f& center, float width, float height, const Color4f& color, bool isFilled );
	virtual ~DaeEllipse();
	virtual void Draw( ) const override;
	virtual std::string ToString() const;
protected: 
	bool m_IsFilled;
};

 
