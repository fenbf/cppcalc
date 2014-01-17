#ifndef FLIGHT_H
	#define FLIGHT_H

#include <vector>
#include <string>

#include "Plane.h"
#include "RoutePoint.h"

class Flight
{
private:
	const Plane* const _plane;
	Plane::PerformanceIndex _performanceIndex;
	const std::vector<RoutePoint> * const _route;	
	const std::string _depTime;
public:
	Flight(const Plane *plane, Plane::PerformanceIndex index, const std::vector<RoutePoint> *route, const std::string &depTime) :
		_plane(plane),
		_performanceIndex(index),
		_route(route),
		_depTime(depTime)
	{
		
	}

	Plane::PerformanceParams GetPerformanceParams(RoutePoint::Type pointType) const
	{
		// todo: implement
		return{ 0.0, 0.0 };
	}

	const std::vector<RoutePoint> &GetPoints() const { return *_route;  }

	friend std::ostream &operator <<(std::ostream &stream, const Flight &data)
	{
		stream << "Plane:\t\t" << data._plane->GetName() << std::endl;
		stream << "Departure time:\t" << data._depTime << std::endl;
		stream << "Departure airport:\t" << data._route->front()._waypointName << std::endl;
		stream << "Destination airport:\t" << data._route->back()._waypointName << std::endl;
		return stream;
	}
};

#endif // FLIGHT_H