#include "DataAccessor.h"
#include "Plane.h"
#include "Waypoint.h"
#include <map>


const std::map<std::string, Plane> MapOfPlanes = {
	// name,          name,          min (fuel, speed)  avg           max           clb           desc
	{ "Airbus 330", { "Airbus 330", { 4000, 700 }, { 5000, 833 }, { 6000, 950 }, { 11844, 600 }, { 10099, 685 } } },
	{ "Beoing 737", { "Beoing 737", { 2000, 650 }, { 2526, 828 }, { 3000, 900 }, { 5830,  780 }, { 5226, 820 } } }
};

//                awy,    name,     lat,     lon,  dist (in Nautical Miles)
const static std::map<std::string, Waypoint> MapOfWaypoints = {
	{ "EPGD",  { "EPGDR29", "EPGD", 54.0981, 17.0181, 0.0 } },
	{ "DEXIR", { "DEXIR3G", "DEXIR", 54.0982, 17.0182, 41.0 } },
	{ "VEKON", { "T671"   , "VEKON", 54.0983, 17.0183, 17.0 } },
	{ "LUXAL", { "L730"   , "LUXAL", 53.9150, 16.5433, 20.0 } },
	{ "XERBI", { "P31"    , "XERBI", 53.0317, 15.6717, 62.0 } },
	{ "GOVEN", { "P31"    , "GOVEN", 54.0983, 14.7550, 67.0 } },
	{ "AMOSA", { "DCT"    , "AMOSA", 49.5100, 10.8117, 215 } },
	{ "ODEGU", { "UN869"  , "ODEGU", 49.4150, 10.6617, 8 } },
	{ "DKB"  , { "UN869"  , "DKB"  , 49.1433, 10.2383, 23 } },
	{ "TEDGO", { "UN869"  , "TEDGO", 48.6183,  9.2600, 50 } },
	{ "NATOR", { "UN869"  , "NATOR", 48.1700,  8.3217, 46 } },
	{ "ULMES", { "UQ209"  , "ULMES", 46.9550,  7.2933, 84 } },
	{ "ABEVA", { "UQ227"  , "ABEVA", 46.4067,  6.1000, 59 } },
	{ "NINTU", { "UQ227"  , "NINTU", 46.1467,  5.5533, 28 } },
	{ "MEBAK", { "UN869"  , "MEBAK", 45.7083,  4.6483, 46 } },
	{ "REPSI", { "UN869"  , "REPSI", 45.5233,  4.2750, 19 } },
	{ "LERGA", { "UN869"  , "LERGA", 45.2567,  3.7500, 27 } },
	{ "MOKDI", { "UN869"  , "MOKDI", 44.9567,  3.1667, 31 } },
	{ "OLRAK", { "UN869"  , "OLRAK", 44.7850,  2.8367, 18 } },
	{ "TBO"  , { "UQ169"  , "TBO"  , 43.3317,  0.1450, 145 } },
	{ "OBUTO", { "UN869"  , "OBUTO", 43.1600,  0.0217, 12 } },
	{ "SOVAR", { "UN869"  , "SOVAR", 42.7867, -0.2450, 25 } },
	{ "SURCO", { "UN869"  , "SURCO", 42.3283, -0.5683, 31 } },
	{ "ZARKO", { "UN869"  , "ZARKO", 42.0050, -0.7933, 22 } },
	{ "ZAR"  , { "UN869"  , "ZAR"  , 41.6583, -1.0317, 23 } },
	{ "SEDIL", { "UZ245"  , "SEDIL", 41.3233, -1.4333, 27 } },
	{ "KONKE", { "UZ245"  , "KONKE", 41.0333, -1.7767, 23 } },
	{ "TERSA", { "UZ245"  , "TERSA", 40.7250, -2.1383, 25 } },
	{ "D043K", { "TERSA3E", "D043K", 40.5050, -2.3917, 18 } },
	{ "RBO38", { "TERSA3E", "RBO38", 40.5283, -2.5367, 9 } },
	{ "NOSKO", { "TERSA3E", "NOSKO", 40.6567, -2.8167, 15 } },
	{ "RBO"  , { "TERSA3E", "RBO"  , 40.8533, -3.2467, 23 } },
	{ "TAGOM", { "TERSA3E", "TAGOM", 40.9833, -3.4317, 14 } },
	{ "BAN47", { "TERSA3E", "BAN47", 40.9367, -3.5433, 6 } },
	{ "MANCO", { "TERSA3E", "MANCO", 40.8867, -3.5767, 4 } },
	{ "149DM", { "TERSA3E", "149DM", 40.7717, -3.5767, 7 } },
	{ "CI18R", { "TERSA3E", "CI18R", 40.7033, -3.5767, 5 } },
	{ "FI18R", { "TERSA3E", "FI18R", 40.6733, -3.5767, 2 } },
	{ "LEMD" , { "TERSA3E", "LEMD" , 40.4717, -3.5617, 13 } }
};


const Plane* TestingDataAccessor::GetPlane(std::string nameOfPlane)
{
	auto it = MapOfPlanes.find(nameOfPlane);
	if (it != MapOfPlanes.end())
		return &(it->second);

	return nullptr;
}

const Waypoint* TestingDataAccessor::GetWaypoint(std::string nameOfWaypoint)
{
	auto it = MapOfWaypoints.find(nameOfWaypoint);
	if (it != MapOfWaypoints.end())
		return &(it->second);

	return nullptr;
}

WindComponent TestingDataAccessor::GetWindComponentForWaypoint(const Waypoint &waypoint)
{
	// todo: implement...
	return WindComponent(0, 0);
}