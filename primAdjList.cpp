#include "primAdjList.h"

void AdjacencyList::addingEdge(int source, int dest, int weight){
  Node *newNode = new Node(dest, weight); // creates a newNode
  newNode->next = adjList[source]; // indexes into the adjacencyList based on source node, then sets the newNode's next pointer to the Node pointer in the vector (that's the head of the LL at that index)
  adjList[source] = newNode; // makes the newNode pointer the new "head" which is what is stored in the vector
  
  //the reverse edge
  newNode = new Node(source, weight);
  newNode->next = adjList[dest];
  adjList[dest] = newNode;
}

/*
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
  */

AdjacencyList::AdjacencyList(int v){
  vertices = v;
  adjList.resize(vertices, nullptr);
}

AdjacencyList::~AdjacencyList(){
  for (int i = 0; i < vertices; i++){
    Node *curr = adjList[i];
    while (curr != nullptr){
      Node *temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
}
/*
  void PrimMST(vector<int>& MST, int source){
  
  for(int i = 0; i < vertices; i++){
  not_MST.push_back(i); //initalize set of all vertices
  }
  
  MST.clear();
  vector<bool> inMST(vertices, false);
  MST.push_back(source); //starting vertex is 0
  inMST[source] = true;//need to remove 0 from not_MST
  //    int capacity = not_MST.size();
  //not_MST[source] = not_MST[capacity - 1];
  //not_MST.erase(remove(not_MST.begin(), not_MST.end(), source), not_MST.end());
  //capacity--;
  while(MST.size() < vertices){
  lightEdge = nullptr;
  findEdge(MST);
  if(lightEdge != nullptr){
  int newVert = lightEdge->index;
  MST.push_back(newVert); //adds lightest edge to MST
  //need to remove vertices from not_MST
  }
  }
  }
*/

void AdjacencyList::PrimMST(vector<pair<int, int>>& MST, int source){
  //MST.clear();
  vector<int> key(vertices, INF);
  vector<int> parent(vertices, -1);
  vector<bool> inMST(vertices, false);
  //MST.push_back(source);
  //inMST[source] = true;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prioQueue;

  key[source] = 0;
  prioQueue.push({0, source});

  while (!prioQueue.empty()){
    int u = prioQueue.top().second;
    prioQueue.pop();

    if (inMST[u]){
      continue;
    }

    inMST[u] = true;

    if (parent[u] != -1){
      MST.push_back({parent[u], u});
    }

    Node *curr = adjList[u];
    while (curr != nullptr){
      int v = curr->index;
      int weight = curr->dist;
      if ((!inMST[v]) && (weight < key[v])){
	key[v] = weight;
	parent[v] = u;
	prioQueue.push({key[v], v});
      }
      curr = curr->next;
    }
  }

  /*
  while (MST.size() < vertices){
    int minWeight = INF;
    Node *lightEdge = nullptr;
    
    for (int i = 0; i < MST.size(); i++){
      int u = MST[i];
      Node *curr = adjList[u];
      while (curr != nullptr){
	int v = curr->index;
	if ((!inMST[v]) && (curr->dist < minWeight)){
	  minWeight = curr->dist;
	  lightEdge = curr;
	}
	curr = curr->next;
      }
    }
    
    if (lightEdge != nullptr){
      int nextVertex = lightEdge->index;
      MST.push_back(nextVertex);
      inMST[nextVertex] = true;
    } else {
      break;
    }
  }
  */
}
