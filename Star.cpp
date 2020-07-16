#include "..\stdafx.h"
#include "Star.h"


Star::Star(int mx, int my, RECT& rv)
{
	point[0] = mx;
	point[1] = my;
	rectV = rv;
	type = 3;
	/*for (int i = 0; i < 5; i++)
		starP[0 + 2 * i] =
		{ long(double(point[0]) + radius*cos(2 * acos(0.0) / 180 * (90 - 72 * i))),
		long(double(point[1]) - radius*sin(2 * acos(0.0) / 180 * (90 - 72 * i))) };

	for (int i = 0; i < 5; i++)
		starP[1 + 2 * i] =
		crammer(starP[(0 + 2 * i) % 10], starP[(4 + 2 * i) % 10],
			starP[(2 + 2 * i) % 10], starP[(8 + 2 * i) % 10]);*/
}


Star::~Star()
{
}

void Star::update(int f)
{
	point[0] += speed[0] * vec[0];
	point[1] += speed[1] * vec[1];

	radius *= sizeFactor;
	sizeFactor = 1;

	for (int i = 0; i < 5; i++)
		starP[0 + 2 * i] =
	{ long(double(point[0]) + radius*cos(2 * acos(0.0) / 180 * (90 - 72 * i - f*speed[0]))),
		long(double(point[1]) - radius*sin(2 * acos(0.0) / 180 * (90 - 72 * i - f*speed[0]))) };

	for (int i = 0; i < 5; i++)
		starP[1 + 2 * i] =
		crammer(starP[(0 + 2 * i) % 10], starP[(4 + 2 * i) % 10],
			starP[(2 + 2 * i) % 10], starP[(8 + 2 * i) % 10]);
}

void Star::show(HDC hdc)
{
	
	Polygon(hdc, starP, 10);
}

POINT Star::crammer(POINT& p1, POINT& p2, POINT& p3, POINT& p4)
{
	long a, b, c, d, e, f;

	a = p1.y - p2.y;
	b = -(p1.x - p2.x);
	c = p3.y - p4.y;
	d = -(p3.x - p4.x);
	e = a*p1.x + b*p1.y;
	f = c*p3.x + d*p3.y;
	/*e = a*p4.x + b*p4.y;
	f = c*p3.x + d*p3.y;*/

	return{ (e*d - b*f) / (a*d - b*c),
		(a*f - e*c) / (a*d - b*c) };
}