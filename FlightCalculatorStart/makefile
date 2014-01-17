# Project: FlightCalculator
CPP      = g++
OBJ      = DataAccessor.o FlightCalculator.o main.o RouteGenerator.o
LINKOBJ  = DataAccessor.o FlightCalculator.o main.o RouteGenerator.o
BIN      = FlightCalculatorStarter
CXXFLAGS = -std=c++11 -O2
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN)

DataAccessor.o: DataAccessor.cpp
	$(CPP) -c DataAccessor.cpp -o DataAccessor.o $(CXXFLAGS)

FlightCalculator.o: FlightCalculator.cpp
	$(CPP) -c FlightCalculator.cpp -o FlightCalculator.o $(CXXFLAGS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

RouteGenerator.o: RouteGenerator.cpp
	$(CPP) -c RouteGenerator.cpp -o RouteGenerator.o $(CXXFLAGS)
