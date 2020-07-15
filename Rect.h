#pragma once
#include "CShape.h"
class Rect: public CShape
{
	POINT rectP[4];
public:
	Rect(int, int);
	~Rect() {}
	void show(HDC);
};

