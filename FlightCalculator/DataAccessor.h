#ifndef DATA_ACCESSOR_H
	#define DATA_ACCESSOR_H

#include <string>

class Plane;
class Waypoint;
class IDataAccessor
{
public:
	virtual const Plane* GetPlane(std::string nameOfPlane) = 0;
	virtual const Waypoint* GetWaypoint(std::string nameOfWaypoint) = 0;

	//virtual std::vector<RoutePoint> MapOfRoutes
};

class TestingDataAccessor : public IDataAccessor
{
public:
	const Plane* GetPlane(std::string nameOfPlane) override;
	const Waypoint* GetWaypoint(std::string nameOfWaypoint) override;
};

#endif // DATA_ACCESSOR_H