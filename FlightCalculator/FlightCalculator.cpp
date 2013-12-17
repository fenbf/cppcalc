#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include <thread>
#include <future>
#include <regex>

#include "Waypoint.h"
#include "FlightCalculator.h"
#include "DataAccessor.h"
#include "RouteGenerator.h"
#include "Plane.h"
#include "Flight.h"
#include "RoutePoint.h"




std::mutex data_mutex;

CalculatedFlightData FlightCalculator::Calculate(Flight flight)
{
	//std::shared_ptr<CalculatedFlightData> calcData = std::make_shared<CalculatedFlightData>();
	CalculatedFlightData calcData;


	//for (auto &v : vec)
	//{
	//	std::cout << v << std::endl;
	//}

	{
		std::lock_guard<std::mutex> lock(data_mutex);
		// access to data
	}


	return calcData;
}

void matcher(std::string &baseTxt, const std::string &regExp)
{
	std::regex regularExp(regExp);
	if (std::regex_match(baseTxt, regularExp))
		std::cout << "\n Matcher fucntion: Matched successful ! " << baseTxt << "\n\n";
	else
		std::cout << "\n Matcher fucntion: Unsuccessful ! " << baseTxt << "\n\n";
}

int main()
{
	std::cout << "\n\n Hello in Flight Calculator" << std::endl;

	const std::string dateRegExpr("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	std::string dateOfFlight;
	std::cout << "\n\n Please enter the date of flight, ex. 2014-01-20 => Departure date: ";
	std::getline(std::cin, dateOfFlight);
	matcher(dateOfFlight, dateRegExpr);

	const std::string timeRegExpr("[0-9]{2}:[0-9]{2}Z?");
	std::string timeOfFlight;
	std::cout << "\n\n Please enter the time of flight, ex. 10:15 => Departure time: ";
	std::getline(std::cin, timeOfFlight);
	matcher(timeOfFlight, timeRegExpr);

	TestingDataAccessor dataAccessor;
	TestingRouteGenerator routeGenerator;
	Flight flight{ dataAccessor.GetPlane("A"), Flight::PerformanceIndex::Average, routeGenerator.GetRoute("AA", "BB") };


	std::unique_ptr<FlightCalculator> flCalc = std::make_unique<FlightCalculator>();

	std::thread prepareData([]{ std::cout << " ... add/minus something ... :)"; });
	prepareData.join();


	//std::thread route1(flCalc->Calculate, flight);
	

	CalculatedFlightData calcData;
	std::thread route1([&] {calcData = flCalc->Calculate(flight); });
	route1.join();


	//std::future<CalculatedFlightData> ret = std::async(flCalc->Calculate(flight));
	//CalculatedFlightData calcData = ret.get();
	//auto future1 = std::async(flCalc->Calculate, flight);
	//auto calcData = future.get();

	//route1.join();

	auto calcData1 = flCalc->Calculate(flight);


	std::getchar();
	return 0;
//	std::cout<< calcData.
}








	// 1. Spalanie samolotu danego typu (kg/h)
	// 2. Dodanie CLB - DSC points : spalanie x 1.2 lub 0.9
	// 3. Suma odległości


	// 1. Lista waypointów
	// 2. CLB, DSC na liscie waypointów
	// 3. Dodanie wiatru dla poszczególnych waypointów
	// 4. Rzeczywisty czas lotu
	// 5. Czekamy na holding
	// 6. Lecimy szybciej (zwiekszamy predkosc) => wiecej spalamy

	// 1. Różna ilość typów samolotów - różne dane performansowe

	//===========================================================================

	// Step1
	// 1.1 Wczytanie punktow/waypointow z pliku do kontenera 
	// (awy, nazwa, lat, lon, kolejnoscNaAwy, odlegloscDoPoprzedniego, wysokosc, typPunktu, kierunekWiatru, predkoscWiatru)
	// 1.2 Punkty w aplikacji (bez wczytywania)

	// 2. Suma odległości wszystkich punktów od lotniska A do lotniska B
	// 3. Wczytanie danych konkretnego typu samolotu i wybranie sredniej prędkości przelotowej
	// 4. Wprowadzenie godziny lotu
	// 5. Policzenie czasu lotu bazując na odległości i prędkości samolotu
	// 6. Obliczenie potrzebnego paliwa bazując na czasie lotu i danych o samolocie (spalanie kg/h lotu)

	// Step2
	// 1. Uwzględnienie w wczesniejszym algorytmie typu waypointów:
	//    - pobranie danych z tabeli performance-owej


	// Step3
	// 1.

	// Dane wejsciowe:
	// 1. Tablica waypointów (Awy, Name, Lat, Lon, order/seq, dystansDoPoprzedniego) => hashMapa
	// 2. Tablica routingu (Awy, Name, FL (Wysokosc), TypPktNaRoute) => lista/vector
	// 3. Tablica pogody (Awy, Name, KierunekWiatru, PredkoscWiatru) => 
	// 4. Tablica SID, STAR (SidName/StarName, PktName, dystans) =>

	// 5. Tablica samolotow:

	//    - predkosc min 600km/h : (700kg/h) 
	//    - predkosc srednia 800km/h : (800kg/h)
	//    - predkosc maks 1000km/h : (900kg/h)

	//    - jesli jest to CLB to spalanie x 1.2 / 2000kg
	//    - jesli jest to CRZ to spalanie x 1
	//    - jesli jest to DSC to spalanie x 0.9 / 800kg
	
	// HashMapa 