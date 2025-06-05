# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Source and output
SRC = main.cpp
OUT_DIR = build
TARGET = $(OUT_DIR)/main

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean rule
clean:
	@rm -rf $(OUT_DIR)

.PHONY: all clean