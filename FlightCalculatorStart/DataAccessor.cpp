#include "DataAccessor.h"
#include "Plane.h"
#include "Waypoint.h"
#include <map>


const std::map<std::string, Plane> MapOfPlanes = {
	// name,          name,          min (fuel, speed)  avg           max           clb           desc
	{ "Airbus 330", { "Airbus 330", { 1.0, 1.0 }, { 1.5, 1.5 }, { 2.0, 2.0 }, { 2.5, 0.9 }, { 0.9, 0.5 } } },
	{ "Beoing 737", { "Beoing 737", { 1.0, 1.0 }, { 1.0, 1.0 }, { 1.0, 1.0 }, { 1.0, 1.0 }, { 1.0, 1.0 } } }
};

//                awy,    name,     lat,     lon,  dist
const static std::map<std::string, Waypoint> MapOfWaypoints = {
	{ "EPGD",  { "EPGDR29", "EPGD", 54.0981, 17.0181, 0.0 } },
	{ "DEXIR", { "DEXIR3G", "DEXIR", 54.0982, 17.0182, 0.5 } },
	{ "VEKON", { "T671"   , "VEKON", 54.0983, 17.0183, 1.0 } },
	{ "LUXAL", { "L730"   , "LUXAL", 53.9150, 16.5433, 1.2 } },
	{ "XERBI", { "P31"    , "XERBI", 53.0317, 15.6717, 1.4 } },
	{ "GOVEN", { "P31"    , "GOVEN", 54.0983, 14.7550, 1.3 } },
	{ "AMOSA", { "DCT"    , "AMOSA", 49.5100, 10.8117, 1.6 } },
	{ "ODEGU", { "UN869"  , "ODEGU", 49.4150, 10.6617, 1.5 } },
	{ "DKB"  , { "UN869"  , "DKB"  , 49.1433, 10.2383, 1.9 } },
	{ "TEDGO", { "UN869"  , "TEDGO", 48.6183,  9.2600, 1.7 } },
	{ "NATOR", { "UN869"  , "NATOR", 48.1700,  8.3217, 1.4 } },
	{ "ULMES", { "UQ209"  , "ULMES", 46.9550,  7.2933, 1.8 } },
	{ "ABEVA", { "UQ227"  , "ABEVA", 46.4067,  6.1000, 1.5 } },
	{ "NINTU", { "UQ227"  , "NINTU", 46.1467,  5.5533, 1.1 } },
	{ "MEBAK", { "UN869"  , "MEBAK", 45.7083,  4.6483, 1.8 } },
	{ "REPSI", { "UN869"  , "REPSI", 45.5233,  4.2750, 1.3 } },
	{ "LERGA", { "UN869"  , "LERGA", 45.2567,  3.7500, 1.7 } },
	{ "MOKDI", { "UN869"  , "MOKDI", 44.9567,  3.1667, 2.0 } },
	{ "OLRAK", { "UN869"  , "OLRAK", 44.7850,  2.8367, 1.4 } },
	{ "TBO"  , { "UQ169"  , "TBO"  , 43.3317,  0.1450, 1.9 } },
	{ "OBUTO", { "UN869"  , "OBUTO", 43.1600,  0.0217, 2.1 } },
	{ "SOVAR", { "UN869"  , "SOVAR", 42.7867, -0.2450, 2.3 } },
	{ "SURCO", { "UN869"  , "SURCO", 42.3283, -0.5683, 1.7 } },
	{ "ZARKO", { "UN869"  , "ZARKO", 42.0050, -0.7933, 1.0 } },
	{ "ZAR"  , { "UN869"  , "ZAR"  , 41.6583, -1.0317, 1.5 } },
	{ "SEDIL", { "UZ245"  , "SEDIL", 41.3233, -1.4333, 2.6 } },
	{ "KONKE", { "UZ245"  , "KONKE", 41.0333, -1.7767, 1.3 } },
	{ "TERSA", { "UZ245"  , "TERSA", 40.7250, -2.1383, 1.8 } },
	{ "D043K", { "TERSA3E", "D043K", 40.5050, -2.3917, 1.4 } },
	{ "RBO38", { "TERSA3E", "RBO38", 40.5283, -2.5367, 1.7 } },
	{ "NOSKO", { "TERSA3E", "NOSKO", 40.6567, -2.8167, 1.2 } },
	{ "RBO"  , { "TERSA3E", "RBO"  , 40.8533, -3.2467, 1.6 } },
	{ "TAGOM", { "TERSA3E", "TAGOM", 40.9833, -3.4317, 1.8 } },
	{ "BAN47", { "TERSA3E", "BAN47", 40.9367, -3.5433, 1.3 } },
	{ "MANCO", { "TERSA3E", "MANCO", 40.8867, -3.5767, 1.9 } },
	{ "149DM", { "TERSA3E", "149DM", 40.7717, -3.5767, 1.1 } },
	{ "CI18R", { "TERSA3E", "CI18R", 40.7033, -3.5767, 1.4 } },
	{ "FI18R", { "TERSA3E", "FI18R", 40.6733, -3.5767, 1.7 } },
	{ "LEMD" , { "TERSA3E", "LEMD" , 40.4717, -3.5617, 1.2 } }
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
	// todo: implement
	return nullptr;
}

WindComponent TestingDataAccessor::GetWindComponentForWaypoint(const Waypoint &waypoint)
{
	// todo: implement...
	return WindComponent(0, 0);
}