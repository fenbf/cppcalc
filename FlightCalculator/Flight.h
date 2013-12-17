#ifndef FLIGHT_H
	#define FLIGHT_H

#include <vector>

#include "Plane.h"
#include "RoutePoint.h"

class Flight
{
private:
	const Plane* _plane = nullptr;	// if we have such pointer then maybe "move" ctor/assignment should be provided? or maybe use value here?
	Plane::PerformanceIndex _performanceIndex = Plane::PerformanceIndex::Invalid;
	std::vector<RoutePoint> _route;	

public:
	Flight(const Plane *plane, Plane::PerformanceIndex index, std::vector<RoutePoint> route) :
		_plane { plane },
		_performanceIndex{ index },
		_route { route }
	{
		
	}

	// add friend class "FlightCalculator" or provide getters?
};

#endif // FLIGHT_H