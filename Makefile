GCC = g++-13 -std=c++2a
BUILD = bin/main
SOURCE = src/main.cpp src/include/*.cpp

$(BUILD): $(SOURCE)
	$(GCC) $(SOURCE) -o $(BUILD)

clean:
	rm ./$(BUILD)

run:
	./$(BUILD)