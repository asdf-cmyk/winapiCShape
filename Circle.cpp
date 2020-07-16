#include "..\stdafx.h"
#include "Circle.h"


Circle::Circle(int mx, int my, RECT& rv)
{
	point[0] = mx;
	point[1] = my;
	rectV = rv;
	type = 2;
}

void Circle::update(int f)
{
	point[0] += speed[0] * vec[0];
	point[1] += speed[1] * vec[1];

	radius *= sizeFactor;
	sizeFactor = 1;
}

void Circle::show(HDC hdc)
{
	Ellipse(hdc,
		point[0] - radius,
		point[1] - radius,
		point[0] + radius,
		point[1] + radius);
}