#ifndef PLANE_H
	#define PLANE_H

#include <string>

class PerformanceParams
{
public:
	double _fuelKgPerHour;
	double _velocityKmPerHour;
};

class Plane
{
public:
	std::string _name;
	PerformanceParams _minimum;
	PerformanceParams _average;
	PerformanceParams _maximum;
	PerformanceParams _onClimbing;
	PerformanceParams _onDescent;
};

#endif // PLANE_H