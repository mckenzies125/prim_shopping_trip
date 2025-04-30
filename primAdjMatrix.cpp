#include "primAdjMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int vertexes){
  vertices = vertexes;
  adjMatrix.resize(vertexes, vector<int>(vertexes, INF));
}

void AdjacencyMatrix::addingEdge(int source, int dest, int weight){
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

void AdjacencyMatrix::PrimMST(vector<pair<int, int>>& MST, int source){
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
      if ((adjMatrix[u][v] != INF) && (!inMST[v]) && adjMatrix[u][v] < key[v]){
	key[v] = adjMatrix[u][v];
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
