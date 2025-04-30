#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "primAdjList.h"
#include "primAdjMatrix.h"

using namespace std;

int main(int argc, char* argv[]){
  if (argc != 2){
    cerr << "Usage: " << argv[0] << " input.txt\n";
    return 1;
  }
  
  //new AdjacencyList = primAdjList;
  
  string inputfile = argv[1];
  //string outputfile = argv[2];
  ifstream file(inputfile);
  if (!file.is_open()){
    cerr << "Error opening file: " << argv[1] << "\n";
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
  
  while(file >> u >> v >> weight){
    primAdjList.addingEdge(u, v, weight);
    primAdjMatrix.addingEdge(u, v, weight);
  }

  vector<int> listMST;
  vector<pair<int, int>> matrixMST;

  clock_t startList = clock();
  primAdjList.PrimMST(listMST, source);
  clock_t endList = clock();
  double durationList = double(endList - startList) / CLOCKS_PER_SEC;

  clock_t startMatrix = clock();
  primAdjMatrix.PrimMST(matrixMST, source);
  clock_t endMatrix = clock();
  double durationMatrix = double(endMatrix - startMatrix) / CLOCKS_PER_SEC;
	
  
  cout << "Edges in the matrixMST: \n";
  for (const auto& edge : matrixMST){
    cout << (edge.first + 1) << " - " << (edge.second + 1) << "\n";
  }

  cout << "Time taken for Prim's Algorithm with Adjacency List: " << durationList << " seconds\n";
  cout << "Time taken for Prim's Algorithm with Adjacency Matrix: " << durationMatrix << " seconds\n";
}
