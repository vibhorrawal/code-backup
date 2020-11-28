#include<iostream>
using namespace std;

const int SIZE = 26;
struct Trie {
  struct Trie *child[SIZE];
  bool is_end;
  Trie(){
    for(int i = 0; i < SIZE; i++) child[i] = NULL;
    is_end = false;
  }
};

void insert(Trie *root, const string &s){
  for(char c : s){
    if(root->child[c-'a'] == NULL)
      root->child[c-'a'] = new Trie();
    root = root->child[c-'a'];
  }
  root->is_end = true;
}

bool is_present(Trie *root, const string &s){
  for(char c : s){
    if(root->child[c-'a'] == NULL)
      return false;
    root = root->child[c-'a'];
  }
  return root->is_end;
}

void insert(Trie *root, const string &s, int pos){
  for(int i = pos; i < s.size(); i++) {
    char c = s[i];
    if(root->child[c-'a'] == NULL)
      root->child[c-'a'] = new Trie();
    root = root->child[c-'a'];
  }
  root->is_end = true;
}
int main(int argc, char const *argv[]) {
  Trie *root;
  Trie *suffix_tree;
  string s;
  for(int i = 0; i < s.size(); i++){
    insert(suffix_tree, s, i);
  }
  return 0;
}
