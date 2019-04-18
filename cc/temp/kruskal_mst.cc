#include <bits/stdc++.h>
using namespace std;
struct edge
{
	int w;
	int weight;
};
class Graph
{
public:
	int V;
	list <edge> *adj;
	int *parent;


	Graph(int V);
	void addEdge(int v, int w, int weight);
	void Union(int x,int y);
	int find(int i);
	bool isCyclic();
	void kruskal();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<edge>[V];

	parent = new int[V];

	for (int i = 0; i < V; ++i)
		parent[i] = -1;
}
void Graph::addEdge(int v, int w, int weight){
	edge e;
	e.w = w;
	e.weight = weight; 
	adj[v].push_back(e);
}
int Graph::find(int i){
	if(parent[i] == -1)
		return i;
	return find(parent[i]);
}
void Graph::Union(int x, int y){
	int xset = find(x);
	int yset = find(y);

	parent[yset] = xset;
}
bool Graph::isCyclic(){
	list<edge>::iterator i;
	for(int u = 0; u < V; u++){
		int x,y;
		x = find(u);
		for(i = adj[u].begin(); i != adj[u].end(); i++){
			y = find(i->w);
			if(x == y)
				return true;
			Union(x,y);
		}
	}
	return false;
}
void Graph::kruskal(){
	Graph result(V);
	
}
int main(int argc, char const *argv[])
{
	Graph g(4); 
    g.addEdge(0, 1,10); 
    g.addEdge(0, 2,6); 
    g.addEdge(0,3,5);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);
    g.kruskal();
	return 0;
}