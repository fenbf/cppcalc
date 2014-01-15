// FlightCalculator_step2.cpp : Defines the entry point for the console application.
//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Test
{
	double v1;
	double v2;
};

Test t{ 0.0, 0.0 };

class Plane
{
public:
	struct PerformanceParams
	{
		double fuelPerHour;
		double velicityKmPerHour;
	};

	enum class PerformanceIndex
	{
		Minimum,
		Maximum
	};

	std::string name;
	PerformanceParams minParam;
	PerformanceParams maxParam;
	PerformanceIndex perfIndex;
};

//std::vector<Plane> planes = {
//	{ "Airbus", { 0.0, 0.0 }, { 1.0, 1.0 } },
//	{ "Beoing", { 0.0, 0.0 }, { 1.0, 1.0 } }
//};

void initTest()
{
	int tab[10] = { 0, 1 };
	for (const auto &i : tab)
		std::cout << i << std::endl;

	int tab2[10];
	for (const auto &i : tab2)
		std::cout << i << std::endl;
}

enum class WaypointType
{
	None = 0,
	Climbing,
	Cruise,
	Descent
};

//std::vector<MyType> vec;
//for (std::vector<MyType>::iterator it = vec.begin(); it != vec.end(); ++it)
//doSomething(*it);
//
//std::vector<MyType> vec;
//for (auto &elem : vec)
//doSomething(elem);




int main(int argc, char* argv[])
{
	Plane p{ "Airbus", { 0.0, 0.0 }, { 1.0, 1.0 }, Plane::PerformanceIndex::Minimum };

	//for (const auto &p : planes)
	//	std::cout << p.name << std::endl;

	//WaypointType wt = WaypointType::Cruise;
	//if (wt != WaypointType::None)
	//	Fly();

	initTest();

	std::vector<int> nums = { 1, 2, 3, 4, 5, 6 };

	int counter = 0;

	std::sort(std::begin(nums), std::end(nums),
		[&counter](const int &a, const int &b) -> bool
	{
		counter++;
		return b < a;
	});

	std::cout << counter << std::endl;
}

//auto i; // error: 'i': a symbol whose type contains 'auto' must have an initializer
//auto i = 0; // ok... Type = ?
//auto i = superFunction(); // ok.
//auto p = createObj();  // Obj* CreateObj() { return new Obj(); }
//auto r = obj.getX();  // int& getX() { return _x; }
//auto i = { 0, 1, 2 }; // type ?
//
//
//vector<int> nums;
//
//int sum = 0;
//std::sort(begin(names), end(names),
//	[&sum](const int &a, const int &b) -> bool
//{
//	sum += a + b;
//	return b < a;
//}
//);

//class Plane2 {
//private:
//	std::string _name;
//
//public:
//	Plane2(const std::string &n) : _name{ n } {}
//
//	Plane2(const Plane2 &) = delete;
//	Plane2& operator=(const Plane2&) = delete;
//
//	virtual ~Plane2() { }
//
//	virtual void Fly() { };
//};
//
//class CargoPlane final : public Plane2 {
//public:
//	CargoPlane(const std::string &n) : Plane2{ n } {}
//	void Fly() override { };
//};
//
//Parse("<b> Hello " + "<b>");


//class CargoSuperPlane : public CargoPlane
//{
//
//};
//
//void testplane()
//{
//	Plane2 p2{ "tt" };
//	Plane2 p3 = p2;
//}


//auto myFunc() { return int(40); }


#include <map>
std::map<std::string, std::pair<int, int >> points = { 
	{ "KRK", { 0, 0 } },
    { "WAW", { 0, 0 } }
	};


//struct Plane
//{
//	std::string name;
//	double perf;
//	Plane(std::string n) : name{ n }, perf{ 0.0 } { }
//	Plane(std::string n, double p) : name{ n }, perf{ p } { }
//};
//
//Plane pp{ "test" };
//Plane ppp{ "test", 0.1 };

//Buffer(Buffer&& other) 
//{
//	size = other.size;
//	buf = other.buf;
//	other.size = 0;
//	other.buf = nullptr;
//}

