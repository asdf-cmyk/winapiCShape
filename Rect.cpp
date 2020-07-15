#include "..\stdafx.h"
#include "Rect.h"


Rect::Rect(int mx, int my)
{
	point[0] = mx;
	point[1] = my;
	type = 1;
}

void Rect::show(HDC hdc)
{
	rectP[0] = { point[0] - radius, point[1] - radius };
	rectP[1] = { point[0] + radius, point[1] - radius };
	rectP[2] = { point[0] + radius, point[1] + radius };
	rectP[3] = { point[0] - radius, point[1] + radius };
	Polygon(hdc, rectP, 4);
}