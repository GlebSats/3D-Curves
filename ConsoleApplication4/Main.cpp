#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include "Curve.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

bool cmp(Circle* a, Circle* b) {
	return (a->getRadius() < b->getRadius());
}

int main()
{
	srand(time(NULL));
	std::mt19937 rd(std::time(NULL));
	std::uniform_real_distribution<double> randReal(-10000, 10000);
	std::uniform_real_distribution<double> randPositive(0.01, 10000);

	//Fill first vector
	std::vector <std::unique_ptr<Curve>> curves;
	
	for (int i = 0; i < 10; i++) {
		int randomCurve = rand() % 3;

		if (randomCurve == 0) {
			auto circle = std::make_unique<Circle>(Point(randReal(rd), randReal(rd), 0), randPositive(rd));
			curves.push_back(std::move(circle));
		}
		else if (randomCurve == 1) {
			auto ellipse = std::make_unique<Ellipse>(Point(randReal(rd), randReal(rd), 0), randPositive(rd), randPositive(rd));
			curves.push_back(std::move(ellipse));
		}
		else {
			auto helix = std::make_unique<Helix>(Point(randReal(rd), randReal(rd), randReal(rd)), randPositive(rd), randPositive(rd));
			curves.push_back(std::move(helix));
		}
	}

	//Print first vector
	double t = PI / 4;
	int number = 0;

	for (const auto& curve : curves) {
		std::cout << "Point N." << number << ": ";
		curve->getPoint(t).printCoordinates();
		std::cout << "First Derivative N." << number << ": ";
		curve->getFirstDerivative(t).printCoordinates();
		number++;
	}

	//Fill second vector 
	std::vector <Circle*> circles;

	for (const auto& curve : curves) {
		auto circle = dynamic_cast<Circle*>(curve.get());
		if (circle != nullptr) {
			circles.push_back(circle);
		}
	}

	//Sort second vector
	std::sort(circles.begin(), circles.end(), cmp);

	//Total sum of radii
	double sum = 0;
	for (const auto& circle : circles) {
		sum += circle->getRadius();
	}
	std::cout << "Total sum of radii: " << sum << std::endl;
}
