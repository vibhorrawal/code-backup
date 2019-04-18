#include <bits/stdc++.h>
using namespace std;
#define V 5

int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; ++i)
		if(mstSet[i] == false && key[i] < min)
			min = key[i], min_index = i;
	
	return min_index;
}
void printMST(int parent[V]){
	printf("Edges \n"); 
	for (int i = 1; i < V; i++) 
    	printf("%d - %d \n", parent[i], i); 

}
void prim(int graph[V][V]){
	int parent[V];
	int key[V];
	bool mstSet[V] = {false};
	for (int i = 0; i < V; ++i)
		key[i] = INT_MAX;
	key[0] = 0;
	parent[0] = -1;

	for(int count = 0; count < V-1; count++){
		int u = minKey(key,mstSet);
		mstSet[u] = true;

		for(int v = 0; v < V; v++){
			if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
		}
	}
	printMST(parent);
}
int main(int argc, char const *argv[])
{
	/* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | /     \ | 
    (3)-------(4) 
            9         */
int graph[V][V] = {{0, 2, 0, 6, 0}, 
                    {2, 0, 3, 8, 5}, 
                    {0, 3, 0, 0, 7}, 
                    {6, 8, 0, 0, 9}, 
                    {0, 5, 7, 9, 0}}; 
    prim(graph);                
	return 0;
}