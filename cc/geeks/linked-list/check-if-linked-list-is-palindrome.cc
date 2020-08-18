// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */
Node *reverse(Node* head){
  Node *prev,*curr,*next;
  curr = head;
  while(curr){
    next = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}
int count(Node *head){
  int count = 0;
  while(head){
    count++;
    head = head -> next;
  }
  return count;
}
bool isPalindrome(Node *head)
{
    int n = count(head),k;
    if(n%2){
       k = n/2+1;
    }
    else{
       k = n/2;
    }
    Node *curr=head;
    cout << k << endl;
    while(k--) curr = curr -> next;
    curr -> next = reverse(curr);
    curr = curr -> next;
    Node *first = head;
    while(curr){
      cout << first->data<<" "<<curr->data << endl;
      if(first->data != curr-> data) return false;
      first = first -> next;
      curr = curr -> next;
    }
    return true;
}
