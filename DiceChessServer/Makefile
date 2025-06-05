CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = main.cpp server/server.cpp
OUT_DIR = build
TARGET = $(OUT_DIR)/main

all: $(TARGET)

$(TARGET): $(SRCS)
	@mkdir -p $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	@rm -rf $(OUT_DIR)

.PHONY: all clean
