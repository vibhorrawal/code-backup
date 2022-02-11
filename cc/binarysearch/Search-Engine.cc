// add-> O(N), exists -> depends on . O(26^N)
struct Trie {
    struct Trie *child[26];
    bool is_end;
    Trie(){
        for(int i = 0; i < 26; i++) child[i] = NULL;
        is_end = false;
    }
};

class SearchEngine {
    Trie *root;
    public:
    SearchEngine() {
        root = new Trie();
    }

    void add(string word) {
        Trie *ptr = root;
        for(char c : word){
            int id = c - 'a';
            if(ptr->child[id] == NULL) ptr->child[id] = new Trie();
            ptr = ptr->child[id];
        }
        ptr->is_end = true;
    }
    
    bool exists(Trie *root, const string &word, int pos){
        if(not root) return false;
        if(pos == word.size()-1){
            if(word[pos] == '.') {
                for(int i = 0; i < 26; i++) {
                    if(root->child[i] and root->child[i]->is_end){
                        return true;
                    }
                }
                return false;
            }
            char c = word[pos] - 'a';
            return root->child[c] ? root->child[c]->is_end : false;
        }
        char c = word[pos];
        if(c == '.'){
            for(int i = 0; i < 26; i++){
                if(exists(root->child[i], word, pos + 1))
                    return true;
            }
            return false;
        }
        int id = c - 'a';
        if(not root->child[id]) 
            return false;
        return exists(root->child[id], word, pos + 1);
    }
    
    bool exists(const string &word) {
        return exists(root, word, 0);
    }
};