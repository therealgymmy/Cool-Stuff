CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
OBJ=typeid.o
EXEC=typeid.exe

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(GLFLAGS) $(LDFLAGS) -o $(EXEC)

.phony:
clean:
	rm $(EXEC) $(OBJ)
