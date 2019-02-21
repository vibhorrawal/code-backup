// DFS in graph
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node{
	int d;
	struct Node* next;
};
struct List{
	struct Node* head;
};
struct Graph{
	int V;
	struct List* array;
};
struct Graph* create_graph(int V);
void add_edge(struct Graph* graph, int d, int src);
void remove_edge(struct Graph* graph, int src, int d);
void print_graph(struct Graph* graph);
bool check_edge(struct Graph* graph, int src, int d);
void DFS(struct Graph* graph, int v);
void DFS_util(struct Graph* graph, int v, bool visited[]);
//-----------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[]){
	int V = 3;
	struct Graph* graph = create_graph(V);
    add_edge(graph,2,0); 
    add_edge(graph,2,0); 
    add_edge(graph,2,1); 
    add_edge(graph,1,0); 
    // add_edge(graph,3,2); 
    // add_edge(graph,3,3);
    print_graph(graph);
    DFS(graph,0); 
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
struct Graph* create_graph(int V){
	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
	graph->V = V;
	graph->array = (struct List*) malloc( V * sizeof(struct List) );
	for (int i = 0; i < V; ++i)
		graph->array[i].head = NULL;
	return graph;
}
void add_edge(struct Graph* graph, int src, int d){
	struct Node* new_node = (struct Node*) malloc( sizeof(struct Node) );
	new_node -> d = d;
	new_node -> next = graph->array[src].head;
	graph->array[src].head = new_node;
}
void remove_edge(struct Graph* graph, int src, int d){
	struct Node * new_node = graph->array[src].head;
	struct Node * new_node_next = new_node->next;
	if(new_node->d != d){
		while(new_node_next->d != d){
			new_node = new_node->next;
			new_node_next = new_node_next->next;
		}
	new_node->next = new_node->next->next;
	graph->array[src].head = new_node;
	}
	else graph->array[src].head = graph->array[src].head->next;
}
void print_graph(struct Graph* graph){
	int V;
	for (V = 0; V < graph->V; V++)
	{
		struct Node* crawl = graph->array[V].head;
		printf("\n Adjacency list of vertex %d\n head", V); 
		while(crawl){
			printf(" -> %d", crawl->d);
			crawl = crawl->next;
		}
		printf("\n");
	}
}
bool check_edge(struct Graph* graph, int src, int d){
	struct Node* node = graph->array[src].head;
	while(node){
		if(node->d == d)
			return true;
		node = node->next;
	}
	return false;
}
void DFS(struct Graph* graph, int v){
	bool* visited =  malloc(graph->V * sizeof(bool));
	for (int i = 0; i < graph->V; ++i)
		visited[i] = false;
	DFS_util(graph,v,visited);
}
void DFS_util(struct Graph* graph, int v, bool visited[]){
	visited[v] = true;
	printf(" ->%d", v);
	struct Node* node = graph->array[v].head;
	while(node){
		if(!visited[node->d])
			DFS_util(graph,node->d,visited);
		node = node->next;
	}
}