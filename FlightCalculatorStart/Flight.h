#ifndef FLIGHT_H
	#define FLIGHT_H

#include <vector>

#include "Plane.h"
#include "RoutePoint.h"

class Flight
{
private:
	const Plane* const _plane = nullptr;
	Plane::PerformanceIndex _performanceIndex = Plane::PerformanceIndex::Invalid;
	const std::vector<RoutePoint> * const _route = nullptr;	

public:
	Flight(const Plane *plane, Plane::PerformanceIndex index, const std::vector<RoutePoint> *route) :
		_plane(plane),
		_performanceIndex(index),
		_route(route)
	{
		
	}

	Plane::PerformanceParams GetPerformanceParams(RoutePoint::Type pointType) const
	{
		// todo: implement
		return{ 0.0, 0.0 };
	}

	const std::vector<RoutePoint> *GetPoints() const { return _route;  }

	// add friend class "FlightCalculator" or provide getters?
};

#endif // FLIGHT_H