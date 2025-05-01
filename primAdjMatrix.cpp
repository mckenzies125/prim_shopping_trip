#include "primAdjMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(int vertexes){
  vertices = vertexes;
  adjMatrix.resize(vertexes, vector<int>(vertexes, INF));
}

void AdjacencyMatrix::addingEdge(int source, int dest, int weight){
  adjMatrix[source][dest] = weight; //initialize entries in matrix with weights of edges
  adjMatrix[dest][source] = weight; //reverse 
}

void AdjacencyMatrix::PrimMST(vector<pair<int, int>>& MST, int source){
  vector<bool> inMST(vertices, false); //initializing bool vector for inMST
  vector<int> key(vertices, INF); //weights of each edge is inf
  vector<int> parent(vertices, -1); // for printing purposes! Allows us to compare to adjList
  
  key[source] = 0; //set source to 0
  
  for (int count = 0; count < vertices; count++){
    int u = minKeyVertex(key, inMST);
    if (u == -1){
      break;
    }
    
    inMST[u] = true; //now in MST so true
    
    for (int v = 0; v < vertices; v++){
      if ((adjMatrix[u][v] != INF) && (!inMST[v]) && (adjMatrix[u][v] < key[v])){ //if there is an edge between specified nodes AND node v is not already in the MST AND the weight of the edge connecting these nodes is less than the v's currently identified light edge
	key[v] = adjMatrix[u][v]; //make this edge v's light edge 
	parent[v] = u; //make v's parent u, as u is now on v's path to source
      }
    }
  }
  
  MST.clear(); //performed bc we've stored all relevant edges in parent vector
  for (int v = 0; v < vertices; v++){
    if (parent[v] != -1){ //check if connected/won't be on path and will break
      MST.push_back({parent[v], v}); //add v and its parent to MST!
    }
  }
}
