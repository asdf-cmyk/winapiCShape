#include "CShape.h"
#include <random>

CShape::CShape()
	:radius(40), sizeFactor(1)
{
	speed[0] = mkRand(3);
	speed[1] = mkRand(3);
	vec[0] = mkRand(2) % 2 ? mkRand(5) : -1 * mkRand(5);
	vec[1] = mkRand(2) % 2 ? mkRand(5) : -1 * mkRand(5);
}

int CShape::mkRand(int range)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(1, range);

	return dist(mt);
}

void CShape::collision(bool isColl)
{
	if (point[0] + radius > rectV.right)
		vec[0] = -1;
	else if (point[0] - radius < rectV.left)
		vec[0] = 1;

	if (point[1] + radius > rectV.bottom)
		vec[1] = -1;
	else if (point[1] - radius < rectV.top)
		vec[1] = 1;

	else if (isColl)
	{
		vec[0] *= -1;
		vec[1] *= -1;
		//colliState = 1;
	}
}