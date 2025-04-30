#ifndef PRIM_ADJ_LIST_H
#define PRIM_ADJ_LIST_H

#include <vector>
//#include "prim_shopping_trip.h"
#include <iostream>
//#include <ctime>
#include <limits>
#include <queue>

using namespace std;
#define INF numeric_limits<int>::max()

struct Node{
  int index;
  int dist;
  Node* next;

  Node(int i, int d){
    index = i;
    dist = d;
    next = nullptr;
  }
};

class AdjacencyList{
private:
  int vertices;
  vector<Node *> adjList;
  int minWeight = INF;
  
public:
  AdjacencyList(int v);
  ~AdjacencyList();

  void addingEdge(int source, int dest, int weight);
  void PrimMST(vector<pair<int, int>>& MST, int source);
};

#endif
