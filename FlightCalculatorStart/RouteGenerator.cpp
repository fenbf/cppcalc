#include "RouteGenerator.h"
#include <vector>
#include "RoutePoint.h"


std::vector<RoutePoint> TestingRouteGenerator::GetRoute(std::string startWaypointName, std::string endWaypointName)
{
	if (startWaypointName == "EPGD" && endWaypointName == "LEMD")
	{
		return
		{
			{ "EPGDR29", "EPGD", 0, RoutePoint::Type::Cruise },
			{ "DEXIR3G", "DEXIR", 50, RoutePoint::Type::Cruise }, 
			{ "T671", "VEKON", 100, RoutePoint::Type::Cruise },
			{ "L730", "LUXAL", 150, RoutePoint::Type::Cruise },
			{ "P31", "XERBI", 317, RoutePoint::Type::Cruise },
			{ "P31", "GOVEN", 983, RoutePoint::Type::Cruise },
			{ "DCT", "AMOSA", 100, RoutePoint::Type::Cruise },
			{ "UN869", "ODEGU", 150, RoutePoint::Type::Cruise },
			{ "UN869", "DKB", 433, RoutePoint::Type::Cruise },
			{ "UN869", "TEDGO", 183, RoutePoint::Type::Cruise },
			{ "UN869", "NATOR", 700, RoutePoint::Type::Cruise },
			{ "UQ209", "ULMES", 550, RoutePoint::Type::Cruise },
			{ "UQ227", "ABEVA", 067, RoutePoint::Type::Cruise },
			{ "UQ227", "NINTU", 467, RoutePoint::Type::Cruise },
			{ "UN869", "MEBAK", 883, RoutePoint::Type::Cruise },
			{ "UN869", "REPSI", 233, RoutePoint::Type::Cruise },
			{ "UN869", "LERGA", 567, RoutePoint::Type::Cruise },
			{ "UN869", "MOKDI", 567, RoutePoint::Type::Cruise },
			{ "UN869", "OLRAK", 850, RoutePoint::Type::Cruise },
			{ "UQ169", "TBO", 317, RoutePoint::Type::Cruise },
			{ "UN869", "OBUTO", 600, RoutePoint::Type::Cruise },
			{ "UN869", "SOVAR", 867, RoutePoint::Type::Cruise },
			{ "UN869", "SURCO", 283, RoutePoint::Type::Cruise },
			{ "UN869", "ZARKO", 050, RoutePoint::Type::Cruise },
			{ "UN869", "ZAR", 583, RoutePoint::Type::Cruise },
			{ "UZ245", "SEDIL", 233, RoutePoint::Type::Cruise },
			{ "UZ245", "KONKE", 333, RoutePoint::Type::Cruise },
			{ "UZ245", "TERSA", 250, RoutePoint::Type::Cruise },
			{ "TERSA3E", "D043K", 050, RoutePoint::Type::Cruise }, 
			{ "TERSA3E", "RBO38", 283, RoutePoint::Type::Cruise },
			{ "TERSA3E", "NOSKO", 567, RoutePoint::Type::Cruise },
			{ "TERSA3E", "RBO", 533, RoutePoint::Type::Cruise },
			{ "TERSA3E", "TAGOM", 833, RoutePoint::Type::Cruise },
			{ "TERSA3E", "BAN47", 367, RoutePoint::Type::Cruise },
			{ "TERSA3E", "MANCO", 867, RoutePoint::Type::Cruise },
			{ "TERSA3E", "149DM", 717, RoutePoint::Type::Cruise },
			{ "TERSA3E", "CI18R", 033, RoutePoint::Type::Cruise },
			{ "TERSA3E", "FI18R", 733, RoutePoint::Type::Cruise },
			{ "LEMDR18R", "LEMD", 717, RoutePoint::Type::Cruise }
		};
	}
	else
	{
		return
		{
			{ "XA29", startWaypointName, 0, RoutePoint::Type::Cruise },
			{ "XB29", endWaypointName, 0, RoutePoint::Type::Cruise }
		};
	}
}
