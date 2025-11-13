CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Iprojects/basics/include
PROJECT_NAME = basics
LIB_SRC = projects/$(PROJECT_NAME)/src/contact.cpp \
			 projects/$(PROJECT_NAME)/src/manager.cpp
LIB_OBJS = $(LIB_SRC:.cpp=.o)

APP_TARGET = app_basics
APP_SRC = src/main.cpp

TEST_TARGET = run_tests
TEST_SRC = tests/$(PROJECT_NAME)/test_manager.cpp

all: $(APP_TARGET) $(TEST_TARGET)

$(APP_TARGET): $(APP_SRC) $(LIB_OBJS)
	@echo "Linking $(APP_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(APP_TARGET) $(APP_SRC) $(LIB_OBJS)

$(TEST_TARGET): $(TEST_SRC) $(LIB_OBJS)
	@echo "Linking $(TEST_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC) $(LIB_OBJS)

%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -rf projects/$(PROJECT_NAME)/src/*.o
	rm -rf $(APP_TARGET)
	rm -rf $(TEST_TARGET)
	rm -rf *.csv

.PHONY: all clean