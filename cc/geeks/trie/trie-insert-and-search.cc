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

const int SIZE_OF_ALPHABETS = 26;

struct TrieNode {
  struct TrieNode *child[SIZE_OF_ALPHABETS];
  bool isEndNode;

  TrieNode(){
    for (int i = 0; i < SIZE_OF_ALPHABETS; i++) {
      child[i] = NULL;
    }
    isEndNode = false;
  };
};

void insert(TrieNode *root, string s){
  TrieNode *crawl = root;

  for(char c: s){
    int i = c - 'a';
    if(!crawl->child[i])
      crawl->child[i] = new TrieNode();
    crawl = crawl->child[i];
  }
  crawl->isEndNode = true;
}

bool search(TrieNode *root, string s){
  TrieNode *crawl = root;
  for(char c: s){
    int i = c - 'a';
    if(!crawl->child[i])
      return false;
    crawl = crawl->child[i];
  }
  return crawl && crawl->isEndNode;
}

void trie_insert_and_search(){
  int n;
  cin >> n;
  string s;
  TrieNode *root = new TrieNode();
  REP(i,n){
    cin >> s;
    insert(root,s);
  }
  cin >> s;
  cout << search(root,s) << endl;
}
int32_t main(int argc, char const *argv[]){
  fastIO;
  T(){
    trie_insert_and_search();
  }
  return 0;
}
