#include "..\stdafx.h"
#include "Rect.h"

Rect::Rect(int mx, int my, double sf, RECT& rv)
{
	point[0] = mx;
	point[1] = my;
	sizeFactor = sf;
	rectV = rv;
	type = 1;
	/*rectP[0] = { point[0] - radius, point[1] - radius };
	rectP[1] = { point[0] + radius, point[1] - radius };
	rectP[2] = { point[0] + radius, point[1] + radius };
	rectP[3] = { point[0] - radius, point[1] + radius };*/
}

void Rect::update(int f)
{
	point[0] += speed[0] * vec[0];
	point[1] += speed[1] * vec[1];

	radius *= sizeFactor;
	sizeFactor = 1;

	//double circleRad = hypot(radius, radius);
	double circleRad = radius;
	//for (int i = 0; i < 4; i++)
	//{
		//rectP[i] =
		/*{ long(double(rectP[i].x) + circleRad*cos(2 * acos(0.0) / 180 * (90 - f))),
			long(double(rectP[i].y) - circleRad*sin(2 * acos(0.0) / 180 * (90 - f))) };*/
	//}
	rectP[0] =
		{ long(double(point[0]) + circleRad*cos(2 * acos(0.0) / 180 * (90 + 45 - f*speed[0]))),
			long(double(point[1]) - circleRad*sin(2 * acos(0.0) / 180 * (90 + 45 - f*speed[0]))) };
	rectP[1] =
	{ long(double(point[0]) + circleRad*cos(2 * acos(0.0) / 180 * (90 - 45 - f*speed[0]))),
		long(double(point[1]) - circleRad*sin(2 * acos(0.0) / 180 * (90 - 45 - f*speed[0]))) };
	rectP[2] =
	{ long(double(point[0]) + circleRad*cos(2 * acos(0.0) / 180 * (90 - 135 - f*speed[0]))),
		long(double(point[1]) - circleRad*sin(2 * acos(0.0) / 180 * (90 - 135 - f*speed[0]))) };
	rectP[3] =
	{ long(double(point[0]) + circleRad*cos(2 * acos(0.0) / 180 * (90 + 135 - f*speed[0]))),
		long(double(point[1]) - circleRad*sin(2 * acos(0.0) / 180 * (90 + 135 - f*speed[0]))) };
	
}

void Rect::show(HDC hdc)
{
	Polygon(hdc, rectP, 4);
}