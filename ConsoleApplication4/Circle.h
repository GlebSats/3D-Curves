#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"

class Circle : public Curve {
public:
	Circle(Point center, double radius);
	~Circle();

	Point getPoint(double t) override;

	Point getFirstDerivative(double t) override;

	inline const double getRadius() {
		return radius;
	}

private:
	Point center;
	double radius;
};

#endif