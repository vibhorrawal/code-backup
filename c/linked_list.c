#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//triple reference pointer
//https://www.youtube.com/watch?v=1s0w_p5HEuY
typedef struct _node
{
	int data;
	struct _node* next;
} Node;

void insert_node(Node** head, int data){
	Node** tracer = head;
	while((*tracer) && ((*tracer) -> data < data))
		tracer = & (*tracer)->next; // address of next
	//creation of new node
	Node* new = (Node*) malloc(sizeof(Node));
	new->data = data;
	new->next = *tracer;
	*tracer = new;
}

void remove_node(Node** head, int data){
	Node** tracer = head;
	Node* old;
	bool present = false;
	while((*tracer) && !(present = (data == (*tracer)->data)))
		tracer = & (*tracer)->next; 

	if(present)
	{
		old = *tracer;
		*tracer = (*tracer)->next;
		free(old);
	}

}
void print_list(Node **head)
{
	Node **tracer = head;
	while (*tracer) {
		printf(" -> %d",(*tracer)->data);
		tracer = &(*tracer)->next;
	}
}

int main(int argc, char const *argv[])
{
	Node *start = NULL;
	insert_node(&start, 5);
	insert_node(&start, 4);
	insert_node(&start, 6);
	remove_node(&start, 5);
	print_list(&start);
	printf("\n");
	return 0;
}