#include <bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	list <int> *adj;
	int *parent;

public:
	Graph(int V);
	void addEdge(int v, int w);
	void Union(int x,int y);
	int find(int i);
	bool isCyclic();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	parent = new int[V];

	for (int i = 0; i < V; ++i)
		parent[i] = -1;
}
void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
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
	list<int>::iterator i;
	for(int u = 0; u < V; u++){
		int x,y;
		x = find(u);
		for(i = adj[u].begin(); i != adj[u].end(); i++){
			y = find(*i);
			if(x == y)
				return true;
			Union(x,y);
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	Graph g(4); 
    g.addEdge(2, 3); 
    g.addEdge(0, 2);
    // g.addEdge(0,3); 
    
    // g.addEdge(1, 2);

    g.isCyclic()?cout<<"Cyclic":cout<<"Not Cyclic";
	return 0;
}