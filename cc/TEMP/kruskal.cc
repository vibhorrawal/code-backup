#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define N 4
class Graph
{
public:	
	int V;
	list <int> *adj;
	int *parent;


	Graph(int V);
	void addEdge(int v, int w);
	void popEdge(int v);
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
void Graph::popEdge(int v){
	adj[v].pop_back();
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

void kruskal(int graph[N][N]){
	Graph result(N);
	
	int edges = 0, cost = 0;
	while( edges < N - 1){
		int min1 = 0,min2 = 0;
		int min = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if(graph[i][j] != INT_MAX && graph[i][j] < min){
					min1 = i, min2 = j, min = graph[i][j];
					// graph[i][j] = graph[j][i] = INT_MAX;
				}
			}
		}
		graph[min1][min2] = graph[min2][min1] = INT_MAX;
		cout<<"min1: "<<min1<<" min2: "<<min2<<endl;
		sleep(1);
		result.addEdge(min1,min2);
		edges++;
		cost += min;
		if(result.isCyclic()){
			result.popEdge(min1);
			edges--;
			cout<<"abc"<<endl;
			cost -= min;
		}
		cout<<edges<<endl;
	}
	cout<<endl<<cost<<endl;

}

int main(int argc, char const *argv[])
{
	int graph[N][N] = {
					INT_MAX,10,6,5,
					10,INT_MAX,INT_MAX,15,
					6,INT_MAX,INT_MAX,4,
					5,15,4,INT_MAX
					};

	Graph g(4); 
    g.addEdge(2, 3); 
    g.addEdge(0, 3);
    // g.addEdge(0,3); 
    
    // g.addEdge(1, 2);

    g.isCyclic()?cout<<"Cyclic":cout<<"Not Cyclic";

	kruskal(graph);				
	return 0;
}