#ifndef _prim_shopping_trip_
#define _prim_shopping_trip_

#include <vector>
#include "prim_shopping_trip.h"
#include <iostream>
#include <ctime>

using namespace std;
#define INF 1e308

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
public:
  int minWeight = INF;
  int vertices;
  vector<Node*> adjList;
  vector<int> MST;
  vector<int> not_MST;
  
  //Node* head; // We might not need this since the value stored in the vector are head pointers already so indexing into the vector will get us the head already
  Node* lightEdge;//use head and lightEdge in constructor

  void addingEdge(int source, int dest, int weight){
    Node *newNode = new Node(dest, weight); // creates a newNode
    newNode->next = adjList[source]; // indexes into the adjacencyList based on source node, then sets the newNode's next pointer to the Node pointer in the vector (that's the head of the LL at that index)
    adjList[source] = newNode; // makes the newNode pointer the new "head" which is what is stored in the vector

    //the reverse edge
    newNode = new Node(source, weight);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
  }

  void findEdge(vector<int> MST){
    for (int i = 0; i < MST.size(); i++){
      int linkedListIndex = MST[i];
      Node* head = adjList[linkedListIndex];
      traverseLinkedList(head);
    }
    
  }

  void traverseLinkedList(Node* head){
    Node* temp = head;
    while (temp!=nullptr){
      bool in_not_MST = false;
      for (int i = 0; i < not_MST.size(); i++){
	if (temp.index == not_MST[i]){
	  in_not_MST = true;
	}
      }
      if ((temp.dist < minWeight) && (in_not_MST)){ 
	lightEdge = temp;
	minWeight = temp.dist;
      }
      temp = temp->next;
    }
  }
  // My idea for how this would work is we pass in the set. Then we will parse each node in the set and use a helper function that takes in a single source node from the set that returns the light edge from that source node. When we get to this function, we will then compare the edge candidates and then choose the best option.

  AdjacencyList(int v){
    vertices = v;
    adjList.resize(vertices);
    for (int i = 0; i < vertices; i++){
      adjList[i] = nullptr;
    }
  }
  
  ~AdjacencyList(){
    for (int i = 0; i < vertices; i++){
      Node *curr = adjList[i];
      while (curr != nullptr){
	Node *temp = curr;
	curr = curr->next;
	delete temp;
      }
    }
  }

  void PrimMST(){
    for(int i = 0; i < vertices; i++){
      not_MST.push_back(i); //initalize set of all vertices 
    }
    MST.push_back(0); //starting vertex is 0
    //need to remove 0 from not_MST
    while(not_MST.size() > 0){
      lightEdge = nullptr;
      findEdge(MST);
      if(lightEdge != nullptr){
        int newVert = lightEdge->index;
        MST.push_back(newVert); //adds lightest edge to MST
        //need to remove vertices from not_MST
      }
    }
  }
};
//set will be a int vector and each val will be respective index in adjList

class AdjacencyMatrix{
  int vertices;
  vector<vector<int>> adjMatrix;
  vector<int> MST;
  vector<int> not_MST;
  int minWeight = INF;
  int matrixRow = 0;
  
  AdjacencyMatrix(int vertexes){
    vertices = vertexes;
    adjMatrix.resize(vertexes + 1, vector<int>(vertexes + 1, 0));
    for (int i = 0; i < vertexes + 1; i++){
      adjMatrix[i][0] = i;
      adjMatrix[0][i] = i;
    }
  }

  void addingEdge(int source, int dest, int weight){
    adjMatrix[source + 1][dest + 1] = weight;
    adjMatrix[dest + 1][source + 1] = weight;
  }

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
}


int prim_shopping_trip::bubbleUp(int minNode){
  int parent = (minNode - 1)/2;
  while (parent >= 0){
    swap(parent, minNode);
    minNode = parent; 
    parent = (minNode - 1)/2;
  }
}

void prim_shopping_trip::swap(int index, int minNode){
  int temp = Q[index];
  Q[index] = Q[minNode];
  Q[minNode] = temp; //update adjacency list later on
}

void prim_shopping_trip::extract(int minNode){
  bubbleUp(minNode);
  swap(0, size);
  size--; 
}

void prim_shopping_trip::selectMin(){
  min = INF;
  minNode = 0;
  for (int i = 0; i < set.size(); i++){ //change "set" to whatever we call it later
    adjList.findEdge(i);
    //finish later
  }
}

#endif
