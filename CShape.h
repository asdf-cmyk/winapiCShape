#pragma once
#include "..\stdafx.h"

class CShape
{
protected:
	int point[2], speed[2], vec[2], type;
	double radius, sizeFactor;
	//bool colliState;
	RECT rectV;
public:
	CShape();
	//CShape(int, int);
	virtual ~CShape() {}
	int mkRand(int);
	virtual void update(int) {}
	void collision(bool);
	virtual void show(HDC) {}

	int* getPoint() { return point; }
	int* getSpeed() { return speed; }
	int* getVector() { return vec; }
	int getType() { return type; }
	double getRadius() { return radius; }
	int getSizeFactor() { return sizeFactor; }
	
	void setSizeFactor(double n) { sizeFactor = n; }
	//void setRadius(double n) { radius = n; }
};