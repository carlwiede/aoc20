CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

BIN_DIR = bin
INCLUDE_DIR = include
OBJ_DIR = obj
SRC_DIR = src
EXECUTABLE = $(BIN_DIR)/aoc

MAIN_SRC = $(SRC_DIR)/main.cpp
SRC_HEADERS = $(wildcard $(SRC_DIR)/*.hpp)
INCLUDE_HEADERS = $(wildcard $(INCLUDE_DIR)/*.hpp)
MAIN_OBJ = $(OBJ_DIR)/main.o

.PHONY: all clean run

all: $(EXECUTABLE)

$(EXECUTABLE): $(MAIN_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJ)

$(MAIN_OBJ): $(MAIN_SRC) $(SRC_HEADERS) $(INCLUDE_HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	@./$(EXECUTABLE) $(day)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
