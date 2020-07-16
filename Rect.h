#pragma once
#include "CShape.h"
class Rect: public CShape
{
	POINT rectP[4];
public:
	Rect(int, int, double, RECT&);
	~Rect() {}
	void update(int);
	//void collision();
	void show(HDC);
};

