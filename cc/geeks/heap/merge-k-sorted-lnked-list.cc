// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}

   		Node *res = mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
	int data;
	Node* next;

	Node(int x){
	    data = x;
	    next = NULL;
	}

};
*/

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */
#define pr pair<int, Node *>
Node * mergeKLists(Node *arr[], int n)
{
       // Your code here
			 priority_queue<pr, vector<pr>, greater<pr> > pq;
			 for (int i = 0; i < n; i++) {
			   pq.push({arr[i]->data, arr[i]});
			 }
			 Node *head, *curr;
			 head = pq.top().second;
			 curr = head;
			 pq.pop();
			 if(head->next) pq.push({head->next->data, head->next});
			 while(pq.size()){
				 auto it = pq.top();
				 curr -> next = it.second;
				 pq.pop();
				 curr = curr -> next;
				 if(curr -> next != NULL) pq.push({curr-> next -> data, curr->next});
			 }
			 curr -> next = NULL;
			 return head;
}
