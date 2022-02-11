// O(MN) space time
struct Trie {
    struct Trie *child[26];
    char val;
    int leaf;
    Trie(){
        for(int i = 0; i < 26; i++) child[i] = NULL;
        leaf = 0;
    }
};

int ans;

void insert(Trie *root, string &s){
    for(char c : s){
        int id = c - 'a';
        if(!root->child[id]) root->child[id] = new Trie();
        root = root->child[id];
    }
    root->leaf++;
}

void dfs(Trie *root, int v){
    if(not root) return;
    v += root->leaf;
    ans = max(v, ans);
    for(int i = 0; i < 26; i++){
        dfs(root->child[i], v);
    }
}

int solve(vector<string>& words) {
    Trie *root = new Trie();
    for(string &s : words){
        insert(root, s);
    }
    ans = 0;
    dfs(root, 0);
    return ans;
}