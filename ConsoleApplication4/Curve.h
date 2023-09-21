#ifndef CURVE_H
#define CURVE_H

#include "Point.h"
#include <cmath>
const double PI = 3.14159;

class Curve {
public:
	virtual ~Curve() = default;
	virtual Point getPoint(double t) = 0;
	virtual Point getFirstDerivative(double t) = 0;
};

#endif
