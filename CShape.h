#pragma once
#include "..\stdafx.h"
class CShape
{
protected:
	int point[2], speed[2], type, radius, vec[2];
public:
	CShape();
	//CShape(int, int);
	virtual ~CShape() = 0;
	int mkRand(int);
	/*virtual void update() = 0;
	virtual bool collision() = 0;*/
	virtual void show(HDC) = 0;

	int* getPoint() { return point; }
	int* getSpeed() { return speed; }
	int* getVector() { return vec; }
	int getType() { return type; }
	int getRadius() { return radius; }
};