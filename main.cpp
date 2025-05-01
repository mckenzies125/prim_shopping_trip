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
    
  string inputfile = argv[1];
  ifstream file(inputfile);
  if (!file.is_open()){
    cerr << "Error opening file: " << argv[1] << "\n";
    return 1;
  }
  
  int numVertices;
  int source;
  file >> numVertices;
  file >> source;

  //constructing an adjacency list and an adjacency matrix
  AdjacencyList primAdjList(numVertices);
  AdjacencyMatrix primAdjMatrix(numVertices);

  int u, v, weight;

  //reading in values from filesssss
  while(file >> u >> v >> weight){
    //creating "graph" by storing source, destination and weight in adjList and adjMatrix
    primAdjList.addingEdge(u, v, weight);
    primAdjMatrix.addingEdge(u, v, weight);
  }

  //creating vectors that hold MST
  vector<pair<int, int>> listMST;
  vector<pair<int, int>> matrixMST;

  //calling prim's algorithm on our adjacency list and tracking time 
  clock_t startList = clock();
  primAdjList.PrimMST(listMST, source);
  clock_t endList = clock();
  double durationList = double(endList - startList) / CLOCKS_PER_SEC;

  //calling prim's algorithm on our adjacency matrix and tracking time 
  clock_t startMatrix = clock();
  primAdjMatrix.PrimMST(matrixMST, source);
  clock_t endMatrix = clock();
  double durationMatrix = double(endMatrix - startMatrix) / CLOCKS_PER_SEC;

  //printing out the MST from adjacency list
  cout << "Edges in the listMST: \n";
  for (const auto& edge : listMST){
	  cout << (edge.first + 1) << " -> " << (edge.second +1) << "\n";\
  }

  cout << "\n";

  //printing out the MST from adjacency matrix
  cout << "Edges in the matrixMST: \n";
  for (const auto& edge : matrixMST){
    cout << (edge.first + 1) << " -> " << (edge.second + 1) << "\n";
  }

  //printing out time taken to perform prim's algorithm
  cout << "Time taken for Prim's Algorithm with Adjacency List: " << durationList << " seconds\n";
  cout << "Time taken for Prim's Algorithm with Adjacency Matrix: " << durationMatrix << " seconds\n";
}
