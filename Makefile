CXX = g++
CXXFLAGS = -std=c++17 -Wall
PROJECT ?= basics    # default project
SRC = $(wildcard projects/$(PROJECT)/src/*.cpp) src/main.cpp
INCLUDE = -Iprojects/$(PROJECT)/include -Iinclude
TARGET = build/$(PROJECT)

$(TARGET): $(SRC)
	mkdir -p build
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build