#pragma once
#include <string>
#include "Fraction.h"

template<typename T>
T Max(const T& a, const T& b)
{
	return a < b ? b : a;
}