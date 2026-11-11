CXX      = g++
CXXFLAGS = -std=c++17 -Wall

lab11: main.cpp
	$(CXX) $(CXXFLAGS) -o lab11 main.cpp

clean:
	rm -f lab11