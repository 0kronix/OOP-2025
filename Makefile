CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = structs
SOURCES = main.cpp func.cpp
HEADERS = structs.h func.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean