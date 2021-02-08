// O(N * SIZE_OF_STRING * ALPHABET) time and time
const char SP = 'z' + 1;

struct Trie {
    struct Trie *child[27];
    int isleaf;
    Trie(){
        for(int i = 0; i < 27; i++) child[i] = NULL;
        isleaf = 0;
    }
};

bool insert(Trie *root, string s){
    for(char c : s){
        c -= 'a';
        if(not root->child[c]) root->child[c] = new Trie();
        root = root->child[c];
    }
    return root->isleaf++;
}
bool solve(vector<string>& words) {
    Trie *root = new Trie();
    for(string s : words){
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            s[i] = SP;
            if(insert(root, s))
                return true;
            s[i] = c;
        }
    }
    return false;
}

//------------------------------------------------------------------------------
// same as above but uses unordered_set
bool solve(vector<string>& w) {
    unordered_set<string> us;
    for(string &s : w){
        for(int i = 0; i < s.size(); i++){
            char t = s[i];
            s[i] = '*';
            if(not us.insert(s).second) // second is false if already in set
                return true;
            s[i] = t;
        }
    }
    return false;
}

//------------------------------------------------------------------------------
// O(N * SIZE_OF_STRING * ALPHABET) time | O(N * SIZE_OF_STRING) space
bool solve(vector<string>& w) {
    unordered_set<string> seen;
    for(string s : w){
        for(int i = 0; i < s.size(); i++){
            char x = s[i];
            for(char c = 'a'; c <= 'z'; c++){
                if(x == c) continue;
                s[i] = c;
                if(seen.count(s)) return true;
            }
            s[i] = x;
        }
        seen.insert(s);
    }
    return false;
}
