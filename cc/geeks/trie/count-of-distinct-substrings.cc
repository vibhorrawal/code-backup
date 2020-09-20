// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}

// } Driver Code Ends
const int SIZE = 26;
struct TrieNode {
  struct TrieNode *child[SIZE];
  bool isEndNode;

  TrieNode(){
    for (int i = 0; i < SIZE; i++) {
      child[i] = NULL;
    }
    isEndNode = false;
  }
};

void insert(TrieNode *root, string s, int l, int r){
  TrieNode *crawl = root;
  for (int i = l; i <= r; i++) {
    int ind = s[i] - 'a';
    if(crawl->child[ind] == NULL)
      crawl->child[ind] = new TrieNode();
    crawl = crawl->child[ind];
  }
  crawl->isEndNode = true;
}
void suffixTrie(TrieNode *root, string s){
  for (int i = 0; i < s.size(); i++) {
    insert(root, s, i, s.size()-1);
  }
}

int countNodes(TrieNode *root){
  if(root == NULL)
    return 0;
  int count = 1;
  for (int i = 0; i < SIZE; i++) {
    count += countNodes(root->child[i]);
  }
  return count;
}
/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    //Your code here
    TrieNode *root = new TrieNode();
    suffixTrie(root, s);
    return countNodes(root);
}
