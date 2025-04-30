#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
  if (arc != 2){
    cerr << "Usage: " << argv[0] << " input.txt\n";
    return 1;
  }
  
  //new AdjacencyList = primAdjList;
  
  string inputfile = argv[1];
  //string outputfile = argv[2];
  ifstream file(inputfile);
  if (!file.is_open()){
    cerr << "Error opening file: " << arg[1] << "\n";
    return 1;
  }

  /*
  string line;
  int numVertices = 0;
  getline(file, line);
  numVertices = stoi(line); // can't do this, line is a string value declared above
  //AdjacencyList primAdjList = new AdjacencyList(line);  // reads in the first line's value which is how many vertices are in the file
  int source, dest, weight;
  */

  int numVertices;
  int source;
  file >> numVertices;
  file >> source;

  AdjacencyList primAdjList(numVertices);
  AdjacencyMatrix primAdjMatrix(numVertices);

  int u, v, weight;
  
  while(file >> u >> v >> w){
    primAdjList.addingEdge(u, v, w);
    primAdjMatrix.addingEdge(u, v, w);
  }

  vector<int> listMST;
  vector<pair<int, int>> matrixMST;
  primAdjList.PrimMST(listMST, source);
  primAdjMatrix.PrimMST(matrixMST, source);

  cout << "Edges in the matrixMST:\n";
  for (const auto& edge : mstEdges){
    cout << (edge.first + 1) << " - " << (edge.second + 1) << "\n";
  }
}
