# Compiler
CXX = clang++
# Compiler flags
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

# Source file
SOURCE = forca.cpp

# Executable name
EXECUTABLE = forca

# Default rule
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(EXECUTABLE)

# Clean rule
clean:
	rm -f $(EXECUTABLE)
