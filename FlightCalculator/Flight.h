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

	Plane::PerformanceParams GetPerformanceParams(RoutePoint::Type pointType) const
	{
		// note: students will have to implement this method
		//       as a start this method will return only "average params"
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

	const std::vector<RoutePoint> &GetPoints() const { return _route;  }

	// add friend class "FlightCalculator" or provide getters?
};

#endif // FLIGHT_H