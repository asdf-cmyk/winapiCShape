#pragma once
#include "..\stdafx.h"
class CShape
{
protected:
	int point[2], speed[2], type, radius, vec[2];
public:
	CShape();
	//CShape(int, int);
	virtual ~CShape() {}
	int mkRand(int);
	/*virtual void update();
	virtual bool collision();*/
	virtual void show(HDC hdc) {
		Rectangle(hdc, 100, 100, 1000, 500);
	};

	int* getPoint() { return point; }
	int* getSpeed() { return speed; }
	int* getVector() { return vec; }
	int getType() { return type; }
	int getRadius() { return radius; }
};