# Compiler
CXX = clang++
# Compiler flags
CXXFLAGS = -Wall -Wextra -pedantic -std=c++23

# Source file
SOURCE = adivinhacao.cpp

# Executable name
EXECUTABLE = adivinhacao

# Default rule
all: $(EXECUTABLE)

# Rule to build the executable
$(EXECUTABLE): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(EXECUTABLE)

# Clean rule
clean:
	rm -f $(EXECUTABLE)
