#ifndef WAYPOINT_H
	#define WAYPOINT_H

#include <string>

class Waypoint
{
public:
	std::string _airwayName;
	std::string _name;
	double _lat;
	double _lon;
	double _distance;

public:
	// http://stackoverflow.com/questions/19269345/initializing-map-of-maps-with-initializer-list-in-vs-2013
	// without this constructor VS2013 compiles it incorrectly! GCC is as always better :)
	Waypoint(std::string airway, std::string name, double lat, double lon, double dist) :
		_airwayName(airway),
		_name(name),
		_lat(lat),
		_lon(lon),
		_distance(dist)
	{

	}
};

#endif // WAYPOINT_H