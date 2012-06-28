CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
OBJ=prime.o
EXEC=prime.exe

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

.phony:
clean:
	rm $(EXEC) $(OBJ)
