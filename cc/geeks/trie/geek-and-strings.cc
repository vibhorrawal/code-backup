#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

const int SIZE = 26;

struct TrieNode{
  struct TrieNode *child[SIZE];
  int isEndNode;
  TrieNode(){
    for (int i = 0; i < SIZE; i++) {
      child[i] = NULL;
    }
    isEndNode = 0;
  }
};
void insert(TrieNode *root, string &s){
  TrieNode *crawl = root;
  for(char c: s){
    int ind = c - 'a';
    if(!crawl->child[ind])
      crawl->child[ind] = new TrieNode();
    crawl = crawl->child[ind];
  }
  crawl->isEndNode++;
}
int countNodes(TrieNode *root){
  if(root == NULL)
    return 0;
  int count = root->isEndNode;
  for (int i = 0; i < SIZE; i++) {
    count += countNodes(root->child[i]);
  }
  return count;
}
int count_prefix(TrieNode *root, string &s){
  for(char c: s){
    int ind = c - 'a';
    if(!root->child[ind])
      return 0;
    root = root->child[ind];
  }
  return countNodes(root);
}
void check_trie(){
  int n;
  cin >>  n;
  string s;
  TrieNode *root = new TrieNode();
  REP(i,n){
    cin >> s;
    insert(root, s);
  }
  int q;
  cin >> q;
  REP(i,q){
    cin >> s;
    cout << count_prefix(root, s) << endl;
  }
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    check_trie();
  }
  return 0;
}
