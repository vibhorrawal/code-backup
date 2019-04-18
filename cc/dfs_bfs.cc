#include <bits/stdc++.h>
using namespace std;  
// Graph class represents a directed graph 
// using adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<int> *adj; 
  
    // A recursive function used by DFS 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w); 
  
    // DFS traversal of the vertices 
    // reachable from v 
    void DFS(int v);
    void BFS(int v); 
}; 
 
 int main(int argc, char const *argv[])
 {
 	Graph g(5);
 	g.addEdge(0,2);
 	g.addEdge(0,4);
 	g.addEdge(2,3);
 	g.addEdge(2,1);
 	g.BFS(0);
 	return 0;
 } 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::DFS(int v) 
{ 
    bool visited[V] = {0};
    DFSUtil(v,visited);
} 

void Graph::DFSUtil(int v, bool visited[]){
	visited[v] = true;
	cout<<" -> "<<v;

	list <int> :: iterator i;
	for(i = adj[v].begin(); i != adj[v].end(); i++)
		if(!visited[*i])
			DFSUtil(*i,visited);
}

void Graph::BFS(int v){
	bool visited[V] = {0};

	list <int> queue;
	visited[v] = true;
	queue.push_back(v);
	list <int> :: iterator i;

	while(!queue.empty()){
		v = queue.front();
		cout<<" -> "<<v;
		queue.pop_front();

		for(i = adj[v].begin(); i != adj[v].end(); i++){
			if(!visited[*i])
			{
				visited[*i] =  true;
				queue.push_back(*i);
			}
		}
	}

}