#ifndef FLIGHT_CALCULATOR_H
	#define FLIGHT_CALCULATOR_H

#include "Flight.h"
#include <tuple>
#include <vector>
#include <future>
#include <thread>
#include <chrono>

class CalculatedFlightData
{
private:
	double _totalDistance{ 0 };
	double _totalTime{ 0 };
	double _totalFuel{ 0 };

public:
	CalculatedFlightData() { }
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
	virtual CalculatedFlightData Calculate(const Flight &flight, class IDataAccessor *dataAccessor) override;
};

// second task - route with SID and STAR
class FlightCalculator2 : public FlightCalculatorBase
{
public:
	virtual CalculatedFlightData Calculate(const Flight &flight, class IDataAccessor *dataAccessor) override;
};

// third task - wind component
class FlightCalculator3 : public FlightCalculatorBase
{
public:
	virtual CalculatedFlightData Calculate(const Flight &flight, class IDataAccessor *dataAccessor) override;
};

class CalculatorCollection
{
private:
	typedef std::pair<const Flight *, FlightCalculatorBase *> CalcPair;
	std::vector<CalcPair> _collection;
	std::vector<CalculatedFlightData> _results;

public:
	CalculatorCollection(std::initializer_list<CalcPair> list) : _collection{ list }
	{

	}

	void RunAll(class IDataAccessor *dataAccessor)
	{
		// todo: add threads here, statistics - ie: get minimum fuel...
		for(auto &element : _collection)
		{
			_results.emplace_back(element.second->Calculate(*element.first, dataAccessor));
		}

		for (auto &element : _results)
		{
			std::cout << "\n--\n" << element;
		}
	}

	void RunAllThreads(class IDataAccessor *dataAccessor)
	{
		std::vector<std::future<CalculatedFlightData>> futures;
		for (int i = 0; i < _collection.size(); ++i)
		{
			futures.emplace_back(std::async([this, i, dataAccessor](){
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
				std::cout << "running..." << i << std::endl;
				return _collection[i].second->Calculate(*_collection[i].first, dataAccessor);
			}));
		}

		for (auto &element : futures)
		{
			_results.emplace_back(element.get());
			std::cout << "\n--\n" << _results.back();
		}
	}
};

#endif // FLIGHT_CALCULATOR_H