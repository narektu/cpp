CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -Iprojects/basics/include -Iprojects/algorithms/include

# BASICS ==========================================
BASICS_SRC = projects/basics/src/contact.cpp projects/basics/src/manager.cpp
BASICS_OBJS = $(BASICS_SRC:.cpp=.o)

APP_BASICS_TARGET = app_basics
APP_BASICS_SRC = src/main_basics.cpp

TEST_BASICS_TARGET = run_tests_basics
TEST_BASICS_SRC = tests/basics/test_manager.cpp
# ==========================================
# ALGORITHMS ==========================================
ALGO_SRC = projects/algorithms/src/graph.cpp
ALGO_OBJS = $(ALGO_SRC:.cpp=.o)

APP_ALGO_TARGET = app_algo
APP_ALGO_SRC = src/main_algo.cpp

TEST_ALGO_TARGET = run_tests_algo
TEST_ALGO_SRC = tests/algorithms/test_graph.cpp
# ==========================================

all: $(APP_BASICS_TARGET) $(TEST_BASICS_TARGET) $(APP_ALGO_TARGET) $(TEST_ALGO_TARGET)

# BASICS
$(APP_BASICS_TARGET): $(APP_BASICS_SRC) $(BASICS_OBJS)
	@echo "Linking $(APP_BASICS_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(APP_BASICS_TARGET) $(APP_BASICS_SRC) $(BASICS_OBJS)

$(TEST_BASICS_TARGET): $(TEST_BASICS_SRC) $(BASICS_OBJS)
	@echo "Linking $(TEST_BASICS_TARGET)..."
	$(CXX) $(CXXFLAGS) -o $(TEST_BASICS_TARGET) $(TEST_BASICS_SRC) $(BASICS_OBJS)

# ALGORITHMS
$(APP_ALGO_TARGET): $(APP_ALGO_SRC) $(ALGO_OBJS)
	@echo "Linking Algo App..."
	$(CXX) $(CXXFLAGS) -o $(APP_ALGO_TARGET) $(APP_ALGO_SRC) $(ALGO_OBJS)

$(TEST_ALGO_TARGET): $(TEST_ALGO_SRC) $(ALGO_OBJS)
	@echo "Linking Algo Tests..."
	$(CXX) $(CXXFLAGS) -o $(TEST_ALGO_TARGET) $(TEST_ALGO_SRC) $(ALGO_OBJS)

%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	rm -f projects/basics/src/*.o projects/algorithms/src/*.o
	rm -f $(APP_BASICS_TARGET) $(TEST_BASICS_TARGET) $(APP_ALGO_TARGET) $(TEST_ALGO_TARGET)
	rm -rf *.csv

.PHONY: all clean