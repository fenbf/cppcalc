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

	enum class PerformanceIndex
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
	Plane(std::string name) : _name{ name } { }
	Plane(std::string name, PerformanceParams min, PerformanceParams max, PerformanceParams avg, PerformanceParams onClb, PerformanceParams onDsc) :
		_name(name),
		_minimum(min),
		_average(avg),
		_maximum(max),
		_onClimbing(onClb),
		_onDescent(onDsc)
	{

	}

	PerformanceParams GetParams(PerformanceIndex index, RoutePoint::Type pointType)
	{
		if (pointType == RoutePoint::Type::Climbing)
			return _onClimbing;
		else if (pointType == RoutePoint::Type::Descent)
			return _onDescent;
		else
		{
			switch (index)
			{
			case PerformanceIndex::Minimum:
				return _minimum;
			case PerformanceIndex::Average:
				return _average;
			case PerformanceIndex::Maximum:
				return _maximum;
			}
		}
		return { 0.0, 0.0 };
	}
};

#endif // PLANE_H