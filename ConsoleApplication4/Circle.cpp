#include "Circle.h"

Circle::Circle(Point center, double radius) : center(center), radius(radius) {}

Circle::~Circle(){}

Point Circle::getPoint(double t)
{
	double x = center.getX() + radius * cos(t);
	double y = center.getY() + radius * sin(t);
	double z = 0;
	return Point(x, y, z);
}

Point Circle::getFirstDerivative(double t)
{
	double dx = -radius * sin(t);
	double dy = radius * cos(t);
	double dz = 0;
	return Point(dx, dy, dz);
}

