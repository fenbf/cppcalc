#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "Waypoint.h"
#include "FlightCalculator.h"
#include "DataAccessor.h"
#include "RouteGenerator.h"
#include "Plane.h"
#include "Flight.h"
#include "RoutePoint.h"

CalculatedFlightData FlightCalculator::Calculate(const Flight &flight, IDataAccessor *dataAccessor)
{
	double totalDistance = 0;

	for (std::vector<RoutePoint>::const_iterator it = flight.GetPoints().begin(); it != flight.GetPoints().end(); ++it)
	{
		auto waypoint = dataAccessor->GetWaypoint(it->_waypointName);
		if (waypoint == nullptr)
			break;

	}

	return{ totalDistance, 0.0, 0.0 };
}

std::ostream& operator <<(std::ostream &stream, const CalculatedFlightData &data)
{
	stream << "Total Distance:\t" << data._totalDistance << " km" << std::endl;
	stream << "Total Time:\t" << data._totalTime << " hours" << std::endl;
	stream << "Total Fuel:\t" << data._totalFuel << " kilograms" << std::endl;
	return stream;
}
