CXX := g++
CXXFLAGS := -Wall -Wextra -O2 -std=c++17

# Source files
SRCS := main.cpp server/server.cpp

# Output binary
TARGET := server

# Object files (replace .cpp with .o)
OBJS := $(SRCS:.cpp=.o)
# Default target
all: $(TARGET)
# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
