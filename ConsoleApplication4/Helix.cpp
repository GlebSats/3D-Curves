#include "Helix.h"

Helix::Helix(Point center, double radius, double step) : center(center), radius(radius), step(step) {}

Helix::~Helix() {}

Point Helix::getPoint(double t)
{
	double x = center.getX() + radius * cos(t);
	double y = center.getY() + radius * sin(t);
	double z = step * t;
	return Point(x, y, z);
}

Point Helix::getFirstDerivative(double t)
{
	double dx = -radius * sin(t);
	double dy = radius * cos(t);
	double dz = step;
	return Point(dx, dy, dz);
}
