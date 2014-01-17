#ifndef FLIGHT_H
	#define FLIGHT_H

#include <vector>

#include "Plane.h"
#include "RoutePoint.h"

class Flight
{
private:
	const Plane* const _plane = nullptr;	// if we have such pointer then maybe "move" ctor/assignment should be provided? or maybe use value here?
	Plane::PerformanceIndex _performanceIndex = Plane::PerformanceIndex::Invalid;
	const std::vector<RoutePoint> * const _route = nullptr;	

public:
	Flight(const Plane *plane, Plane::PerformanceIndex index, const std::vector<RoutePoint> *route) :
		_plane { plane },
		_performanceIndex{ index },
		_route { route }
	{
		
	}

	Plane::PerformanceParams GetPerformanceParams(RoutePoint::Type pointType) const
	{
		// task: implement this method
		if (pointType == RoutePoint::Type::Climbing)
			return _plane->GetPerfParamsOnClimbing();
		else if (pointType == RoutePoint::Type::Descent)
			return _plane->GetPerfParamsOnDescent();
		else
		{
			switch (_performanceIndex)
			{
			case Plane::PerformanceIndex::Minimum:
				return _plane->GetPerfParamsMinimum();
			case Plane::PerformanceIndex::Average:
				return _plane->GetPerfParamsAverage();
			case Plane::PerformanceIndex::Maximum:
				return _plane->GetPerfParamsMaximum();
			}
		}
		return{ 0.0, 0.0 };
	}

	const std::vector<RoutePoint> &GetPoints() const { return *_route;  }
};

#endif // FLIGHT_H