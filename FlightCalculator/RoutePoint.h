#ifndef ROUTE_POINT_H
	#define ROUTE_POINT_H

#include <string>

class RoutePoint
{
public:
	enum class Type	// note: initially enum will be in "old" style
	{
		None = 0,
		Climbing,
		Cruise,
		Descent
	};

	std::string _airwayName;
	std::string _waypointName;
	unsigned int  _flightLevel;
	Type _pointType;
};

#endif // ROUTE_POINT_H