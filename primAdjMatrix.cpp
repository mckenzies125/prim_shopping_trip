#ifndef _prim_adjacency_matrix_
#define _prim_adjacency_matrix_

#include <vector>
//#include "prim_shopping_trip.h"
#include <iostream>
//#include <ctime>
#include <limits>

using namespace std;
#define INF numeric_limits<int>::max()

class AdjacencyMatrix{
  int vertices;
  vector<vector<int>> adjMatrix;
  //vector<int> MST;
  //vector<int> not_MST;
  //int minWeight = INF;
  //int matrixRow = 0;

  AdjacencyMatrix(int vertexes){
    vertices = vertexes;
    adjMatrix.resize(vertexes, vector<int>(vertexes, INF));
  }

  void addingEdge(int source, int dest, int weight){
    adjMatrix[source][dest] = weight;
    adjMatrix[dest][source] = weight;
  }

  /*
  int findEdge(vector<int> MST){ // returned int is the vertex # of the matrixColumn
    for (int i = 0; i < MST.size(); i++){
      tempMatrixRow = MST[i];
      for (int j = 1; j < adjMatrix.vertexes + 1; j++){
        bool in_not_MST = false;
        for (int k = 0; k < not_MST.size(); k++){
          if (j == not_MST[k]){
            in_not_MST = true;
          }
        }
        if ((adjMatrix[tempMatrixRow][j] < minWeight) && (in_not_MST)){
          minWeight = adjMatrix[tempMatrixRow][j];
          matrixRow = tempMatrixRow;
          return j;
        }
      }
    }
    return -1; //error handle this
  }
  */

  void PrimMST(vector<pair<int, int>>& MST, int source){
    //MST.clear();
    vector<bool> inMST(vertices, false);
    vector<int> key(vertices, INF);
    vector<int> parent(vertices, -1);

    key[source] = 0;

    for (int count = 0; count < vertices; count++){
      int u = minKeyVertex(key, inMST);
      if (u == -1){
	break;
      }

      inMST[u] = true;
      
      //MST.push_back(u);

      for (int v = 0; v < vertices; v++){
	if ((matrix[u][v] != INF) && (!inMST[v]) && matrix[u][v] < key[v]){
	  key[v] = matrix[u][v];
	  parent[v] = u;
	}
      }
    }

    MST.clear();
    for (int v = 0; v < vertices; v++){
      if (parent[v] != -1){
	MST.push_back({parent[v], v});
      }
    }
  }

private:
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
