#ifndef PRIM_ADJ_MATRIX_H
#define PRIM_ADJ_MATRIX_H

#include <vector>
//#include "prim_shopping_trip.h"
#include <iostream>
//#include <ctime>
#include <limits>

using namespace std;
#define INF numeric_limits<int>::max()

class AdjacencyMatrix{
public:
  //int vertices;
  //vector<vector<int>> adjMatrix;
  //vector<int> MST;
  //vector<int> not_MST;
  //int minWeight = INF;
  //int matrixRow = 0;

  void addingEdge(int source, int dest, int weight);
  void PrimMST(vector<pair<int, int>>& MST, int source);
  AdjacencyMatrix(int vertexes);
  
private:
  int vertices;
  vector<vector<int>> adjMatrix;
  
  int minKeyVertex(const vector<int>& key, const vector<bool>& inMST) {
    int minVal = INF;
    int minIndex = -1;
    for (int v = 0; v < vertices; v++){
      if ((!inMST[v]) && (key[v] < minVal)){
        minVal = key[v];
        minIndex = v;
      }
    }
    return minIndex;
  }
};

#endif
