// implementing graph
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int d;
	struct Node* next;
};
struct List{
	struct Node* head;
};
struct Graph{
	int v;
	struct List* array;
};
struct Graph* create_graph(int v);
void add_edge(struct Graph* graph, int d, int src);
void remove_edge(struct Graph* graph, int src, int d);
void print_graph(struct Graph* graph);
int check_edge(struct Graph* graph, int src, int d);
//-----------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[]){
	int v;
	printf("Size of Graph: ");
	scanf("%d",&v);
	struct Graph* graph = create_graph(v);
	
	add_edge(graph,0,1);
	printf("%d\n",check_edge(graph,0,1));
	add_edge(graph,0,3);
	add_edge(graph,1,2);
	remove_edge(graph,0,1);
	printf("%d\n",check_edge(graph,0,1));

	print_graph(graph);
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
struct Graph* create_graph(int v){
	struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
	graph->v = v;
	graph->array = (struct List*) malloc( v * sizeof(struct List) );
	for (int i = 0; i < v; ++i)
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
	int v;
	for (v = 0; v < graph->v; v++)
	{
		struct Node* crawl = graph->array[v].head;
		printf("\n Adjacency list of vertex %d\n head", v); 
		while(crawl){
			printf(" -> %d", crawl->d);
			crawl = crawl->next;
		}
		printf("\n");
	}
}
int check_edge(struct Graph* graph, int src, int d){
	struct Node* node = graph->array[src].head;
	while(node){
		if(node->d == d)
			return 1;
		node = node->next;
	}
	return 0;
}