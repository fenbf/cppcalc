#ifndef WEATHER_H
	#define WEATHER_H

class WindComponent
{
public:
	double _directionFactor;
	double _speedFactor;

public:
	WindComponent(double df, double sf) : _directionFactor(df), _speedFactor(sf)
	{

	}

};

#endif // WEATHER_H
