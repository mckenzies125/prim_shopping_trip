#ifndef PRIM_ADJ_MATRIX_H
#define PRIM_ADJ_MATRIX_H

#include <vector>
#include <iostream>
#include <limits>

using namespace std;
#define INF numeric_limits<int>::max()

class AdjacencyMatrix{
public:

  void addingEdge(int source, int dest, int weight);
  void PrimMST(vector<pair<int, int>>& MST, int source);
  AdjacencyMatrix(int vertexes);
  
private:
  int vertices;
  vector<vector<int>> adjMatrix;
  
  int minKeyVertex(const vector<int>& key, const vector<bool>& inMST) { //vector of keys (current light edge on path to source) and bool vector of whether or not a node is in MST 
    int minVal = INF; 
    int minIndex = -1;
    for (int v = 0; v < vertices; v++){
      if ((!inMST[v]) && (key[v] < minVal)){ //if v is not in MST and v's current light edge is less than our minVal
        minVal = key[v]; //set this light edge to minVal
        minIndex = v; //node v becomes our minIndex
      }
    }
    return minIndex; //this function identifies the lightest edge in whole graph! a skinny legend where is her waist?
  }
};

#endif
