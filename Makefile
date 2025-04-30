CXX = g++
CXXFLAGS = -Wall -Wextra

OBJS = main.o primAdjList.o primAdjMatrix.o

EXE = program

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp primAdjList.h primAdjMatrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

primAdjList.o: primAdjList.cpp primAdjList.h
	$(CXX) $(CXXFLAGS) -c primAdjList.cpp

primAdjMatrix.o: primAdjMatrix.cpp primAdjMatrix.h

	$(CXX) $(CXXFLAGS) -c primAdjMatrix.cpp
clean:
	rm -f $(OBJS) $(EXE) *~
