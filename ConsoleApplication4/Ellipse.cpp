#include "Ellipse.h"

Ellipse::Ellipse(Point center, double semiaxisX, double semiaxisY) : center(center), semiaxisX(semiaxisX), semiaxisY(semiaxisY){}

Ellipse::~Ellipse(){}

Point Ellipse::getPoint(double t)
{
	double x = center.getX() + semiaxisX * cos(t);
	double y = center.getY() + semiaxisY * sin(t);
	double z = 0;
	return Point(x, y, z);
}

Point Ellipse::getFirstDerivative(double t)
{
	double dx = -semiaxisX * sin(t);
	double dy = semiaxisY * cos(t);
	double dz = 0;
	return Point(dx, dy, dz);
}
