#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){

  new AdjacencyList = primAdjList;

  string inputfile = argv[1];
  //string outputfile = argv[2];
  ifstream file(inputfile);
  
  string line;
  int index = 0;
  int dist = 0;
  getline(file, line);
  int line = stoi(line);
  
  while(file >> line){
    file >> source;
    int source = stoi(source);
    file >> dest;
    int dest = stoi(dest);
    file >> weight;
    int weight = stoi(weight);
    primAdjList.addingEdge(source, dest, weight);
  }
}
