#ifndef FLIGHT_CALCULATOR_H
	#define FLIGHT_CALCULATOR_H

#include "Flight.h"
#include <tuple>

class CalculatedFlightData
{
private:
	double _totalDistance;
	double _totalTime;
	double _totalFuel;

public:
	CalculatedFlightData(double totalDist, double totalTime, double totalFuel) :
		_totalDistance(totalDist),
		_totalTime(totalTime),
		_totalFuel(totalFuel)
	{

	};

	double GetTotalDistance() const { return _totalDistance; }
	double GetTotalTime() const { return _totalTime; }
	double GetTotalFuel() const { return _totalFuel; }

	friend std::ostream &operator <<(std::ostream &stream, const CalculatedFlightData &data);
};

// base class for flight calculators
class FlightCalculatorBase
{
public:
	virtual ~FlightCalculatorBase() { }
	virtual CalculatedFlightData Calculate(const Flight &flight, class IDataAccessor *dataAccessor) = 0;
};

// first task - simple route with average plane speed
class FlightCalculator : public FlightCalculatorBase
{
public:
	virtual CalculatedFlightData Calculate(const Flight &flight, class IDataAccessor *dataAccessor);
};

#endif // FLIGHT_CALCULATOR_H