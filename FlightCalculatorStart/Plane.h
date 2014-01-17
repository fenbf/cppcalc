#ifndef PLANE_H
	#define PLANE_H

#include <string>
#include "RoutePoint.h"

// POD:
class Plane
{
public:
	struct PerformanceParams
	{
		double _fuelKgPerHour;
		double _velocityKmPerHour;
	};

	enum PerformanceIndex
	{
		Invalid,
		Minimum,
		Average,
		Maximum
	};

private:
	std::string _name;
	PerformanceParams _minimum;
	PerformanceParams _average;
	PerformanceParams _maximum;
	PerformanceParams _onClimbing;
	PerformanceParams _onDescent;

public:
	Plane(std::string name) : _name(name) { }
	Plane(std::string name, PerformanceParams min, PerformanceParams avg, PerformanceParams max, PerformanceParams onClb, PerformanceParams onDsc) :
		_name(name),
		_minimum(min),
		_average(avg),
		_maximum(max),
		_onClimbing(onClb),
		_onDescent(onDsc)
	{

	}

	const std::string &GetName() const{ return _name; }
	PerformanceParams GetPerfParamsMinimum() const { return _minimum; }
	PerformanceParams GetPerfParamsAverage() const { return _average; }
	PerformanceParams GetPerfParamsMaximum() const { return _maximum; }
	PerformanceParams GetPerfParamsOnClimbing() const { return _onClimbing; }
	PerformanceParams GetPerfParamsOnDescent() const { return _onDescent; }
};

#endif // PLANE_H