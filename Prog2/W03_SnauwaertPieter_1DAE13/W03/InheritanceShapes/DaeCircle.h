#pragma once
#include "DaeEllipse.h"
#include "Vector2f.h"

class DaeCircle :public DaeEllipse
{
public:
	DaeCircle( const Point2f& center, float diameter, const Color4f& color, bool isFilled );
};

 
