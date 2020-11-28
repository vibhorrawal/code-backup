#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

class Trie {
private:
    static const char const_a = 'a';
    static const int SIZE = 26;
    Trie *child[SIZE];
    int is_leaf;
    bool is_empty(Trie *root);
    Trie *remove_helper(Trie *root, string &s, int depth);
    int size_helper(Trie *root);
    void insert_helper(const string &s, int pos);
public:
    Trie() {
        this->is_leaf = 0;
        for(int i = 0; i < SIZE; i++)
            this->child[i] = NULL;
    }
    int exists(const string &word);
    bool startswith(const string &p);
    void add_suffixes(const string &s);
    void traverse_helper(vector<string> &v, Trie *root, string s, bool prefix);
    vector<string> prefixes();
    vector<string> traverse();
    void remove(string s);
    int size(){ return size_helper(this); }
    void insert(string s){ insert_helper(s, 0); }
};

bool Trie::is_empty(Trie *root){
    for (int i = 0; i < SIZE; i++) {
        if(root->child[i])
            return false;
    }
    return true;
}

Trie* Trie:: remove_helper(Trie *root, string &s, int depth){
    if(not root) return NULL;
    if(depth == s.size()){
        if(root->is_leaf > 0)
          root->is_leaf--;
        if(is_empty(root) and root->is_leaf == 0){
            delete(root);
            root = NULL;
        }
        return root;
    }

    int idx = s[depth] - const_a;
    root->child[idx] = remove_helper(root->child[idx], s, depth + 1);

    if(is_empty(root) and root->is_leaf == 0){
        delete(root);
        root = NULL;
    }
    return root;
}

int Trie::size_helper(Trie *root){
    if(not root) return 0;
    int ans = root->is_leaf;
    for(int i = 0; i < SIZE; i++){
      ans += size_helper(root->child[i]);
    }
    return ans;
}

void Trie::insert_helper(const string &s, int pos) {
    Trie *ptr = this;
    for(int i = pos; i < s.size(); i++) {
        char c = s[i];
        if(ptr->child[c- const_a] == NULL)
            ptr->child[c- const_a] = new Trie();
        ptr = ptr->child[c- const_a];
    }
    ptr->is_leaf++;
}

int Trie::exists(const string &word) {
    Trie *ptr = this;
    for(char c : word){
        if(ptr->child[c- const_a] == NULL)
            return false;
        ptr = ptr->child[c- const_a];
    }
    return ptr->is_leaf;
}

bool Trie::startswith(const string &p) {
    Trie *ptr = this;
    for(char c : p){
        if(ptr->child[c- const_a] == NULL)
            return false;
        ptr = ptr->child[c- const_a];
    }
    return true;
}

void Trie::add_suffixes(const string &s){
    for(int pos = 0; pos <= (int) s.size(); pos++) {
        insert_helper(s, pos);
    }
}

void Trie::traverse_helper(vector<string> &v, Trie *root, string s, bool prefix){
    if(root == NULL)
        return;
    if(prefix or root->is_leaf)
        v.push_back(s);
    for(int i = 0; i < SIZE; i++){
        traverse_helper(v, root->child[i], s + string(1, 'a' + i), prefix);
    }
}

vector<string> Trie::prefixes(){
    vector<string> v;
    traverse_helper(v, this, "", true);
    return v;
}

vector<string> Trie::traverse(){
    vector<string> v;
    traverse_helper(v, this, "", false);
    return v;
}

void Trie::remove(string s){
    if(not exists(s))
        return;
    remove_helper(this, s, 0);
}


int main(int argc, char const *argv[]) {
    Trie trie;
    string s = "hello";
    trie.insert(s);
    trie.insert(s);
    string p = "hello";
    trie.add_suffixes(p);
    trie.remove(s);
    trie.remove("o");
    vector<string> t = trie.traverse();
    for(string tt : t) cout<<tt<<endl;
    cout << trie.size() << endl;
    return 0;
}
