CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
OBJ=uninit.o
EXEC=uninit.exe

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(GLFLAGS) $(LDFLAGS) -o $(EXEC)

.phony:
clean:
	rm $(EXEC) $(OBJ)
