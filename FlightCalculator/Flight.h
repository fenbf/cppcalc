#ifndef FLIGHT_H
	#define FLIGHT_H

#include <vector>

#include "Plane.h"
#include "RoutePoint.h"

class Flight
{
public:
	enum class PerformanceIndex
	{
		Invalid,
		Minimum,
		Average,
		Maximum
	};

private:
	const Plane* _plane = nullptr;
	PerformanceIndex _performanceIndex = PerformanceIndex::Invalid;
	std::vector<RoutePoint> _route;	

public:
	Flight(const Plane *plane, PerformanceIndex index, std::vector<RoutePoint> route) :
		_plane { plane },
		_performanceIndex{ index },
		_route { route }
	{
		
	}
};

#endif // FLIGHT_H