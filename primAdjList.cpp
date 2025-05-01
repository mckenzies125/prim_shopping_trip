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

AdjacencyList::AdjacencyList(int v){
  vertices = v; 
  adjList.resize(vertices, nullptr); //initializing the size of the adjList with the number of vertices & their pointers
}

AdjacencyList::~AdjacencyList(){ //destructor bc of nodes/pointers/linked list
  for (int i = 0; i < vertices; i++){
    Node *curr = adjList[i];
    while (curr != nullptr){
      Node *temp = curr;
      curr = curr->next;
      delete temp;
    }
  }
}

void AdjacencyList::PrimMST(vector<pair<int, int>>& MST, int source){ //pair = two nodes connecting specified edge. MST is made up of edges (but edges are defined by the nodes that connect them, hence we input a pair of nodes)
  vector<int> key(vertices, INF); //how to identify vertices. Defined by distance from source--initializing as inf
  vector<int> parent(vertices, -1); // vertex that comes before specified vertex in MST--initialize to -1
  vector<bool> inMST(vertices, false); //initialize bool vector inMST--nothing is in "inMST," hence all is false

  //pair = 2 nodes connecting edge, vector = how we store the pair of nodes, greater = compares edges to maintain min heap properties
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prioQueue; 

  key[source] = 0; //find source vertex--setting source to 0
  prioQueue.push({0, source});//add source and distance from source (0) to the priority queue

  while (!prioQueue.empty()){ //while there is a "graph"
    int u = prioQueue.top().second; //look at min dist (source node in this case) then look at second int val (node that is 1 edge away from source)
    prioQueue.pop(); //remove that node

    if (inMST[u]){ //check if removed node is already in the min spanning tree (in this case, just 0) 
      continue;
    }

    inMST[u] = true; //set bool vector val to true, as the node is now in MST

    if (parent[u] != -1){ //if a parent exists (if the node before u exists)
      MST.push_back({parent[u], u}); //add the parent to the MST
    }
    
    Node *curr = adjList[u]; //set curr to the a node adjacent to u in adjacency list (in this case, the head of linkedlist associated with u)
    while (curr != nullptr){ //traverse u's adjacency list
      int v = curr->index; //set v to the index (how to identify v)
      int weight = curr->dist; //set weight to adjacent node's distance from u
      if ((!inMST[v]) && (weight < key[v])){ // check if v is already in MST and if the weight of v the "shortest" path to MST (aka if weight is shorter than the currently stored path to MST--key[v])
	key[v] = weight; //then set shortest path from v to MST to be weight
	parent[v] = u; //let v's parent be u (u is on the path to source)
	prioQueue.push({key[v], v}); //add v and it's weight to MST to the priority queue
      }
      curr = curr->next; //go to next node in u's adjacency list & continue to traverse list
    }
  }
  
  //original idea, however resulted in time complexity O(V*E)...we needed a better time complexity to prove the benefits of an adjacency list:
  
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
