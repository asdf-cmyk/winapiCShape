#include "..\stdafx.h"
#include "Circle.h"


Circle::Circle(int mx, int my)
{
	point[0] = mx;
	point[1] = my;
	type = 2;
}

Circle::~Circle()
{
}

void Circle::show(HDC hdc)
{
	Ellipse(hdc,
		point[0] - radius,
		point[1] - radius,
		point[0] + radius,
		point[1] + radius);
}