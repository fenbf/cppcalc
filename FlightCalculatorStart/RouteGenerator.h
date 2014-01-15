#ifndef ROUTE_GENERATOR_H
	#define ROUTE_GENERATOR_H

#include <vector>
#include <string>

class RoutePoint;

class IRouteGenerator
{
public:
	virtual std::vector<RoutePoint> GetRoute(std::string startWaypointName, std::string endWaypointName) = 0;
};

class TestingRouteGenerator : public IRouteGenerator
{
public:
	std::vector<RoutePoint> GetRoute(std::string startWaypointName, std::string endWaypointName);
};

#endif // ROUTE_GENERATOR_H