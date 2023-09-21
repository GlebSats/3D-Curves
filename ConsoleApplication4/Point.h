#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
	inline Point(double x, double y, double z) : x(x), y(y), z(z) {}
	inline ~Point() {}

	inline double getX() {
		return x;
	}

	inline double getY() {
		return y;
	}

	inline double getZ() {
		return z;
	}

	inline void printCoordinates() {
		std::cout << "x = " << x << " " << "y = " << y << " " << "z = " << z << std::endl;
	}
private:
	double x;
	double y;
	double z;
};


#endif