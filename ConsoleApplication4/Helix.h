#ifndef HELIX_H
#define HELIX_H

#include "Curve.h"

class Helix: public Curve {
public:
	Helix(Point center, double radius, double step);
	~Helix();

	Point getPoint(double t) override;

	Point getFirstDerivative(double t) override;

private:
	Point center;
	double radius;
	double step;
};

#endif
