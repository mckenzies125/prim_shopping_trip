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
  int line = stoi(line); // can't do this, line is a string value declared above
  //AdjacencyList primAdjList = new AdjacencyList(line);  // reads in the first line's value which is how many vertices are in the file
  int source, dest, weight;
  
  while(file >> line){
    file >> source;
    source = stoi(source);
    file >> dest;
    dest = stoi(dest);
    file >> weight;
    weight = stoi(weight);
    primAdjList.addingEdge(source, dest, weight);
  }
}
