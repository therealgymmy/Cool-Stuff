CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
OBJ=surrogate.o
EXEC=surrogate.exe

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(GLFLAGS) $(LDFLAGS) -o $(EXEC)

.phony:
clean:
	rm $(EXEC) $(OBJ)
