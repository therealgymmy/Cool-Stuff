CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra
OBJ=file1.o file2.o
EXEC=file.exe

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) $(GLFLAGS) $(LDFLAGS) -o $(EXEC)

.phony:
clean:
	rm $(EXEC) $(OBJ)
