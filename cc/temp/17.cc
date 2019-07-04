#include<bits/stdc++.h>
using namespace std;

typedef struct _node
{
	struct _node * next = NULL;
	long long int start,end;
	int index;
} Node;
Node *head;
int n;
Node* create_node(long long int x1, long long int x2, int index){
	Node* temp = new Node;
	temp->start = x1;
	temp->end = x2;
	temp->index = index;
	return temp;
}

void add_node(Node* temp, int pos){
	// Node* temp = create_node(x1,x2);

	Node* itr = head;
	if(pos == 1){
		temp->next = head;
		head = temp;
		return;
	}
	
	while(--pos-1)
		itr = itr->next;

	if(itr->next == NULL)
		temp->next = NULL;
	else
		temp->next = (itr->next);

	itr->next = temp;

}
void print_nodes(){
	Node* itr = head;
	do{
		cout<<itr->start<<' '<<itr->end<<endl;
		itr = itr->next;
	}while((itr) != NULL);
}
bool search(long long int x1, long long int x2){
	if(head == NULL)
		return 1;
	Node* itr = head;
	bool flag = true;
	int set = 1, i = 1;
	long long int starting,ending,st;
	while(itr != NULL){
		starting = itr->start;
		ending = itr->end;
		if(!(( (x1 < starting && x2 < starting) && (x1 < ending && x2 < ending) ) || ((x1 > starting && x2 > starting) && (x1 > ending && x2 > ending)))){
			flag = false;
			set = i;// break;
			st = starting;
		}
		itr = itr->next;
		i++;
	}
	return flag;
	/*if(flag){
		if(x1<st) return set;
		else return set+1;
	}
	return -1;
	i = 1;
	itr = head;
	while(itr != NULL){
		starting = itr->start;
		// itr->end = end;

		 if((x1 < starting && x2 < starting) && (x1 < ending && x2 < ending)){ //|| (x1 > start && x2 > start){
			flag = true;
			break;
		}
		itr = itr->next;
		i++;
	}
	if(flag)
		return i;
	return -1;
	*/
}
int main(int argc, char const *argv[])
{
	
	head = NULL;
	int x,y;
	n = 4;
	Node * temp = new Node;

	create_node(8,10,1);
	// cout<<":\n";
	add_node(3,5,2);
	// cout<<":\n";
	add_node(12,14,3);
	// add_node(-1,-1,2);
	// cout<<":\n";

	print_nodes();
	while(1){
		cin>>x>>y;
		cout<<':'<<search(x,y)<<endl;
	}
	return 0;
}