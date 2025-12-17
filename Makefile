CXX = g++

CXXFLAGS = -Wall -g

TARGET = tictactoe

all: $(TARGET)

$(TARGET): tictactoe.cpp
	@
	@$(CXX) $(CXXFLAGS) tictactoe.cpp -o $(TARGET)
	@echo "Compilation successful! Run ./tictactoe to play."

clean:
	@rm -f $(TARGET)
	@echo "Cleaned up project files."
