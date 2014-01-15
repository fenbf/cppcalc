#include <iostream>
#include <string>

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
	std::cout << "\n\nHello in Flight Calculator\n" << std::endl;

	//const std::string dateRegExpr("[0-9]{4}-[0-9]{2}-[0-9]{2}");
	//std::string dateOfFlight;
	//std::cout << "\n\n Please enter the date of flight, ex. 2014-01-20 => Departure date: ";
	//std::getline(std::cin, dateOfFlight);
	//matcher(dateOfFlight, dateRegExpr);

	//const std::string timeRegExpr("[0-9]{2}:[0-9]{2}Z?");
	//std::string timeOfFlight;
	//std::cout << "\n\n Please enter the time of flight, ex. 10:15 => Departure time: ";
	//std::getline(std::cin, timeOfFlight);
	//matcher(timeOfFlight, timeRegExpr);

	TestingDataAccessor dataAccessor;
	TestingRouteGenerator routeGenerator;
	auto route = routeGenerator.GetRoute("EPGD", "LEMD");
	Flight flight{ dataAccessor.GetPlane("Airbus 320"), Plane::PerformanceIndex::Average, &route};


	std::unique_ptr<FlightCalculatorBase> flCalc(new FlightCalculator);
	//auto calcData1 = flCalc->Calculate(flight, &dataAccessor);
	//std::cout << calcData1;

	std::cout << "--" << std::endl;

	std::unique_ptr<FlightCalculatorBase> flCalc2(new FlightCalculator2);
	//auto calcData2 = flCalc2->Calculate(flight, &dataAccessor);
	//std::cout << calcData2;

	std::cout << "--" << std::endl;

	std::unique_ptr<FlightCalculatorBase> flCalc3(new FlightCalculator3);
	//auto calcData3 = flCalc3->Calculate(flight, &dataAccessor);
	//std::cout << calcData3;

	CalculatorCollection collection{ { &flight, flCalc.get() }, { &flight, flCalc2.get() }, { &flight, flCalc2.get() } };
	collection.RunAllThreads(&dataAccessor);

	std::getchar();

	return 0;
}








// 1. Spalanie samolotu danego typu (kg/h)
// 2. Dodanie CLB - DSC points : spalanie x 1.2 lub 0.9
// 3. Suma odleg³oœci


// 1. Lista waypointów
// 2. CLB, DSC na liscie waypointów
// 3. Dodanie wiatru dla poszczególnych waypointów
// 4. Rzeczywisty czas lotu
// 5. Czekamy na holding
// 6. Lecimy szybciej (zwiekszamy predkosc) => wiecej spalamy

// 1. Ró¿na iloœæ typów samolotów - ró¿ne dane performansowe

//===========================================================================

// Step1
// 1.1 Wczytanie punktow/waypointow z pliku do kontenera 
// (awy, nazwa, lat, lon, kolejnoscNaAwy, odlegloscDoPoprzedniego, wysokosc, typPunktu, kierunekWiatru, predkoscWiatru)
// 1.2 Punkty w aplikacji (bez wczytywania)

// 2. Suma odleg³oœci wszystkich punktów od lotniska A do lotniska B
// 3. Wczytanie danych konkretnego typu samolotu i wybranie sredniej prêdkoœci przelotowej
// 4. Wprowadzenie godziny lotu
// 5. Policzenie czasu lotu bazuj¹c na odleg³oœci i prêdkoœci samolotu
// 6. Obliczenie potrzebnego paliwa bazuj¹c na czasie lotu i danych o samolocie (spalanie kg/h lotu)

// Step2
// 1. Uwzglêdnienie w wczesniejszym algorytmie typu waypointów:
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