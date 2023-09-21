#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Curve.h"

class Ellipse : public Curve {
public:
	Ellipse(Point center, double semiaxisX, double semiaxisY);

	~Ellipse();

	Point getPoint(double t) override;

	Point getFirstDerivative(double t) override;

private:
	Point center;
	double semiaxisX;
	double semiaxisY;
};

#endif