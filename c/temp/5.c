#include <stdio.h>


struct node{
	int data;
	struct node * next = NULL;
};
struct list{
	struct node Node;
};

void addNode(struct node * item, int data){
	if(item->next == Null)
	{
		struct list * temp = (struct list *) malloc(sizeof(struct node));
		temp -> data = data;
	}
	else
		addNode(item -> next, int data);

}

int main()
{
	cout<<"Enter number of elements: ";
	int size, x;
	cin>>size;
	struct list List[size];

	cout<<"Enter elements: "
	for (int i = 0; i < size; ++i)
	 {
		cin>>x;
		List[i].Node.data = x;
	 }

	for (int i = 0; i < size; ++i)
	  {
	  	cout<<"For "+str(List[i].Node.data)+" enter next data(-1) to stop:\n";
	  	while(x!= -1)
	  	{
	  		cin>>x;
	  		addNode(&List[i],x);
	  	}
	  }
	  return 0;  
}