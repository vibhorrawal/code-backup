// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* LCA(Node * root , int l , int h);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
        int l , h;
		getline(cin,s);
		scanf("%d ",&l);
		scanf("%d ",&h);
        Node* root = buildTree(s);
        cout<<LCA(root ,  l ,  h)->data<<endl;
    }
    return 1;
}// } Driver Code Ends


/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
void dfs(Node *node, int n1, set<int> & vis){
  if(node == NULL) return;
  vis.insert(node->data);
  if(node-> data == n1) return;
  dfs(node->left,n1,vis);
  dfs(node->right,n1,vis);
}
Node *ans;
void dfs_check(Node *node, int n2, set<int> &vis){
  if(node == NULL) return;
  int d = node->data;
  if(vis.find(d) != vis.end()) {
    ans = node;
    cout << "ans: "<<ans->data << endl;
  }
  if(d == n2) return;
  dfs(node->left,n2,vis);
  dfs(node->right,n2,vis);
}
Node * try1(Node *root, int n1, int n2){
  set<int> vis;
  // vis.insert(root);
  dfs(root,n1,vis);
  for(auto it: vis) cout << it << ' ';
  dfs_check(root,n2,vis);
  return ans;
}
Node *try2(Node *root, int n1, int n2){
  if(root == NULL) return NULL;
  int d = root-> data;
  if(d == n1 || d == n2) return root;

  auto lft = try2(root-> left, n1,n2);
  auto rt = try2(root->right, n1,n2);

  if(lft && rt) return root;
  if(lft == NULL){
    return rt;
  }
  else return lft;
}
// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root'
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   // return try1(root,n1,n2);

   //another solution for general binary Tree
   return try2(root,n1,n2);
   // online sol
   while(root != NULL){
     int d = root-> data;
     if(d < n1 && d < n2) root = root-> right;
     else if(d > n1 && d > n2) root = root -> left;
     else break;
   }
   return root;
}
