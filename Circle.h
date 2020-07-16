#pragma once
#include "CShape.h"
class Circle: public CShape
{
public:
	Circle(int, int, RECT&);
	~Circle() {}
	void update(int);
	//void collision();
	void show(HDC);
	//POINT* getRectP() {POINT* p; return p;};
};

