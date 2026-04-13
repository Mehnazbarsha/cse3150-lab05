CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude

SRC_DIR   = src
TEST_DIR  = tests
BUILD_DIR = build

SRCS     = $(SRC_DIR)/Vector.cpp $(SRC_DIR)/CosineDistance.cpp $(SRC_DIR)/VectorIO.cpp
MAIN_SRC = $(SRC_DIR)/main.cpp
TEST_SRC = $(TEST_DIR)/test_main.cpp

TARGET   = $(BUILD_DIR)/cos_distance
TEST_BIN = $(BUILD_DIR)/run_tests

.PHONY: all clean test run_3d run_5d

all: $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(SRCS) $(MAIN_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lm

$(TEST_BIN): $(SRCS) $(TEST_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ -lm

test: $(TEST_BIN)
	./$(TEST_BIN)

run_3d: $(TARGET)
	./$(TARGET) data/input_3d.txt

run_5d: $(TARGET)
	./$(TARGET) data/input_5d.txt

clean:
	rm -rf $(BUILD_DIR)
