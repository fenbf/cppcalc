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
	// initially the code will do nothing...

	double totalDistance = 0;

	for (const auto& pt : flight.GetPoints())
	{
		auto p = dataAccessor->GetWaypoint(pt._waypointName);
		if (p == nullptr)
			break;

		totalDistance += p->_distance;
	}

	auto perfParams = flight.GetPerformanceParams(RoutePoint::Type::Cruise);
	double speed = perfParams._velocityKmPerHour;
	double totalTime = totalDistance / speed;
	double totalFuel = totalTime * perfParams._fuelKgPerHour;

	return { totalDistance, totalTime, totalFuel };
}

CalculatedFlightData FlightCalculator2::Calculate(const Flight &flight, IDataAccessor *dataAccessor)
{
	double totalDistance = 0;
	double totalTime = 0.0;
	double totalFuel = 0.0;

	for (const auto& pt : flight.GetPoints())
	{
		auto waypoint = dataAccessor->GetWaypoint(pt._waypointName);
		if (waypoint == nullptr)
			break;

		totalDistance += waypoint->_distance;

		auto perfParams = flight.GetPerformanceParams(pt._pointType);

		double localDist = waypoint->_distance;
		double speed = perfParams._velocityKmPerHour;
		double localTime = localDist / speed;
		double localFuel = localTime * perfParams._fuelKgPerHour;

		totalTime += localTime;
		totalFuel += localFuel;
	}

	return{ totalDistance, totalTime, totalFuel };
}

CalculatedFlightData FlightCalculator3::Calculate(const Flight &flight, IDataAccessor *dataAccessor)
{
	double totalDistance = 0;
	double totalTime = 0.0;
	double totalFuel = 0.0;

	for (const auto& pt : flight.GetPoints())
	{
		auto waypoint = dataAccessor->GetWaypoint(pt._waypointName);
		if (waypoint == nullptr)
			break;

		totalDistance += waypoint->_distance;

		auto perfParams = flight.GetPerformanceParams(pt._pointType);
		auto windComponent = dataAccessor->GetWindComponentForWaypoint(*waypoint);

		double localDist = waypoint->_distance;
		double speed = perfParams._velocityKmPerHour;
		speed += windComponent._directionFactor * windComponent._speedFactor * speed;
		double localTime = localDist / speed;
		double localFuel = localTime * perfParams._fuelKgPerHour;

		totalTime += localTime;
		totalFuel += localFuel;
	}

	return{ totalDistance, totalTime, totalFuel };
}

std::ostream& operator <<(std::ostream &stream, const CalculatedFlightData &data)
{
	stream << "Total Distance:\t" << data._totalDistance << " km" << std::endl;
	stream << "Total Time:\t" << data._totalTime << " hours" << std::endl;
	stream << "Total Fuel:\t" << data._totalFuel << " kilograms" << std::endl;
	// todo: add departure and arrival time points
	return stream;
}
