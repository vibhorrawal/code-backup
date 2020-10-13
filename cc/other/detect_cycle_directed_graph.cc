#include <bits/stdc++.h>
using namespace std;
enum Color {WHITE, GREY, BLACK};
class Graph
{
	int V;
	list <int> *adj;
	bool DFSUtil(int u, int color[]);

public:
	Graph(int V);
	void addEdge(int v, int w);
	bool isCyclic();
};

int main(int argc, char const *argv[])
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    if (g.isCyclic()) 
        cout << "Graph contains cycle"; 
    else
        cout << "Graph doesn't contain cycle"; 
  
	return 0;
}
Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}
bool Graph::isCyclic(){
	int color[V] = {0};
	for (int i = 0; i < V; ++i)
		if(color[i] == WHITE)
			if(DFSUtil(i,color))
				return true;
	return false;
}
bool Graph::DFSUtil(int u, int color[]){
	color[u] = GREY;

	list <int> :: iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i) 
    {
    	if(color[*i] == GREY) return true;
    	// if(color[*i] == WHITE && DFSUtil(*i,color)) return true;
    }
    color[u] = BLACK;
    return false;
}