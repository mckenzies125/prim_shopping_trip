#ifndef _prim_shopping_trip_
#define _prim_shopping_trip_

#include <vector>
#inlcude "prim_shopping_trip.h"
#include <iostream>

using namespace std;
#define INF 1e308;


class AdjacencyList{
public:
  vector<Node*> adjList;
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
  Node* head;
  Node* lightEdge;//use head and lightEdge in constructor
  void addingEdge(); //finish later
  void findEdge();
  
}
//set will be a int vector and each val will be respective index in adjList




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
