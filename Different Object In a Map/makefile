CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
OBJ=diffobj.o
EXEC=diffobj.exe

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(GLFLAGS) $(LDFLAGS) -o $(EXEC)

.phony:
clean:
	rm $(EXEC) $(OBJ)
