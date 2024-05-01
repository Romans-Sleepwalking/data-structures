# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source file
SRC = main.cpp

# Executable name
TARGET = main

# I/O test filenames
TEST_INPUT_FILENAME = dancing_men.txt
TEST_OUTPUT_FILENAME = dancing_men_char_frequency.tsv

all: $(TARGET) run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean run

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) -l -i $(TEST_INPUT_FILENAME) -o $(TEST_OUTPUT_FILENAME)
