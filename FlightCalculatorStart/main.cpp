#include <iostream>
#include <string>

#include <thread>
#include <future>
#include <regex>

#include "Waypoint.h"
#include "FlightCalculator.h"
#include "DataAccessor.h"
#include "RouteGenerator.h"
#include "Plane.h"
#include "Flight.h"
#include "RoutePoint.h"

int main()
{
	std::cout << "\n\nHello in Flight Calculator\n" << std::endl;

	TestingDataAccessor dataAccessor;
	TestingRouteGenerator routeGenerator;

	// auto route = routeGenerator.GetRoute("EPGD", "LEMD");
	// Flight flight{ dataAccessor.GetPlane("Airbus 320"), Plane::PerformanceIndex::Average, &route };

	// FlightCalculatorBase flCalc();
	// auto calcData1 = flCalc.Calculate(flight, &dataAccessor);

	std::getchar();

	return 0;
}