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

void matcher(std::string baseTxt, std::string regExp)
{
	
}

int main()
{
	std::cout << "\n\nHello in Flight Calculator\n" << std::endl;

	//const std::string timeRegExpr("???????");
	std::string timeOfFlight = "10:12";
	//std::cout << "\n\nPlease enter the time of flight, ex. 10:15 => Departure time: ";
	//std::getline(std::cin, timeOfFlight);
	//matcher(timeOfFlight, timeRegExpr);

	TestingDataAccessor dataAccessor;
	TestingRouteGenerator routeGenerator;

	const std::vector<RoutePoint> route = routeGenerator.GetRoute("EPGD", "LEMD");
	Flight flight(dataAccessor.GetPlane("Airbus 330"), Plane::PerformanceIndex::Average, &route, timeOfFlight);

	std::unique_ptr<FlightCalculatorBase> flCalc(new FlightCalculator());
	CalculatedFlightData calcData = flCalc->Calculate(flight, &dataAccessor);
	std::cout << flight << calcData << std::endl;

	std::getchar();

	return 0;
}