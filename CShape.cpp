#include "CShape.h"
#include <random>

CShape::CShape()
	:radius(50)
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