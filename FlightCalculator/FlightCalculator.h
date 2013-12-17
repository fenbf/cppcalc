#ifndef FLIGHT_CALCULATOR_H
	#define FLIGHT_CALCULATOR_H

#include "Flight.h"

class CalculatedFlightData
{
public:
	CalculatedFlightData(){};

private:
	double totalDistance;
	double totalTime; // w godzinach
	double totalFuel;
};

class FlightCalculatorBase
{
public:
	virtual CalculatedFlightData Calculate(Flight flight) = 0;
};

class FlightCalculator : FlightCalculatorBase
{
public:
	virtual CalculatedFlightData Calculate(Flight flight) override;
};

#endif // FLIGHT_CALCULATOR_H