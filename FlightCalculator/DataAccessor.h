#ifndef DATA_ACCESSOR_H
	#define DATA_ACCESSOR_H

#include <string>
#include "Weather.h"

class Plane;
class Waypoint;

class IDataAccessor
{
public:
	virtual ~IDataAccessor() { }

	virtual const Plane* GetPlane(std::string nameOfPlane) = 0;
	virtual const Waypoint* GetWaypoint(std::string nameOfWaypoint) = 0;
	virtual WindComponent GetWindComponentForWaypoint(const Waypoint &) = 0;
};

class TestingDataAccessor : public IDataAccessor
{
public:
	const Plane* GetPlane(std::string nameOfPlane) override;
	const Waypoint* GetWaypoint(std::string nameOfWaypoint) override;
	WindComponent GetWindComponentForWaypoint(const Waypoint &) override;
};

#endif // DATA_ACCESSOR_H