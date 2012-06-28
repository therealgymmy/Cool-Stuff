CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
OBJ=fib.o
EXEC=fib.exe

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

.phony:
clean:
	rm $(EXEC) $(OBJ)
