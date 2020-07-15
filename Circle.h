#pragma once
#include "CShape.h"
class Circle: public CShape
{
public:
	Circle(int, int);
	~Circle();
	void show(HDC);
};

