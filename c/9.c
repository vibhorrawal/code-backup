// checking if graph is cyclic
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
bool is_graph_cyclic(struct Graph* graph);
bool is_graph_cyclic_util(struct Graph* graph, int i, /*bool visited[],*/ bool recursive_stack[]);
bool is_graph_cyclic_undirected(struct Graph* graph);
bool is_graph_cyclic_util_undirected(struct Graph* graph, int i, bool visited[], /* bool recursive_stack[],*/ int parent);
//-----------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char const *argv[]){
	int V = 3;
	struct Graph* graph = create_graph(V);
    add_edge(graph,0,1); 
    add_edge(graph,1,0); 
    add_edge(graph,1,2); 
    add_edge(graph,2,1);
    // add_edge(graph,2,0);

    // add_edge(graph,3,0); 
    // add_edge(graph,0,2); 
    // add_edge(graph,3,2);
    print_graph(graph);
    printf(" Graph is %s.\n", is_graph_cyclic_undirected(graph)? "cyclic": "not cyclic");
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
bool is_graph_cyclic(struct Graph* graph){
	int V = graph->V;
	// bool* visited =  malloc(V * sizeof(bool));
	bool* recursive_stack =  malloc(V * sizeof(bool));

	for (int i = 0; i < V; ++i)
		if(is_graph_cyclic_util(graph,i,/*visited,*/recursive_stack))
			return true;
	return false;	
}
bool is_graph_cyclic_util(struct Graph* graph, int i,/* bool visited[],*/ bool recursive_stack[]){
	if(recursive_stack[i])
		return true;
	// if(visited[i])
	// 	return false;
	// visited[i] = true;
	recursive_stack[i] = true;
	struct Node* node = graph->array[i].head;
	while(node){
		if(is_graph_cyclic_util(graph,node->d,/*visited,*/recursive_stack))	
			return true;
		node = node->next;
	}
	recursive_stack[i] = false;
	return false;
}
bool is_graph_cyclic_undirected(struct Graph* graph){
	int V = graph->V;
	bool* visited =  malloc(V * sizeof(bool));

	for (int i = 0; i < V; ++i)
		// if(!visited[i])
			if(is_graph_cyclic_util_undirected(graph,i,visited,-1))
				return true;
	return false;	
}
bool is_graph_cyclic_util_undirected(struct Graph* graph, int v, bool visited[], int parent){
	visited[v] = true;
	struct Node* node = graph->array[v].head;
	// if(node != NULL && node->next != NULL )
	while(node){
		if(!visited[node->d]){
			if(is_graph_cyclic_util_undirected(graph,node->d,visited,v))
				return true;
		}
		else if(node->d != parent) 
			return true;
		node = node->next;
	}
	return false;
}
// bool is_graph_cyclic_util_undirected(struct Graph* graph, int v, bool visited[], int parent){
// 	visited[v] = true;
// 	struct Node* node = graph->array[v].head;
// 	// if(node != NULL && node->next != NULL )
// 		struct Node* i;
// 	while(node != NULL || node->next != NULL ){
// 		i = node -> next;
// 		if(!visited[i->d]){
// 			if(is_graph_cyclic_util_undirected(graph,i->d,visited,v))
// 				return true;
// 		}
// 		else if(i->d != parent) 
// 			return true;
// 		node = node->next;
// 	}
// 	return false;
// }
// bool is_graph_cyclic_util_undirected(struct Graph* graph, int i, bool visited[], bool recursive_stack[], int parent){
// 	if(recursive_stack[i])
// 		return true;
// 	if(visited[i])
// 		return false;
// 	visited[i] = true;
// 	recursive_stack[i] = true;
// 	struct Node* node = graph->array[i].head;
// 	while(node){
// 		if(is_graph_cyclic_util_undirected(graph,node->d,visited,recursive_stack,parent))	
// 			return true;
		
// 		else if(node->d != parent) 
// 			return true;
// 	node = node->next;
// 	}
// 	recursive_stack[i] = false;
// 	return false;
// }
// bool is_graph_cyclic_undirected(struct Graph* graph){
// 	int V = graph->V;
// 	 bool* visited =  malloc(V * sizeof(bool));
// 	bool* recursive_stack =  malloc(V * sizeof(bool));

// 	for (int i = 0; i < V; ++i)
// 		if(is_graph_cyclic_util_undirected(graph,i,visited,recursive_stack,-1))
// 			return true;
// 	return false;	
// }