#pragma once
#include "CShape.h"
class Star: public CShape
{
	POINT starP[10];
public:
	Star(int, int, RECT&);
	~Star();
	void update(int f);
	//void collision();
	void show(HDC);

	POINT crammer(POINT&, POINT&, POINT&, POINT&);
};