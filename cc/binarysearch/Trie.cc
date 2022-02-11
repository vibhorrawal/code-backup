// O(LEN_OF_STRING) time for all functions, O(SUM_OF_LEN) space
class Trie {
    Trie *child[26];
    bool is_leaf;
    // Trie *root;
    
    public:
    Trie() {
        this->is_leaf = false;
        for(int i = 0; i < 26; i++) this->child[i] = NULL;
        // root = NULL;
    }

    void add(string s) {
        Trie *ptr = this;
        for(char c : s){
            if(ptr->child[c-'a'] == NULL)
                ptr->child[c-'a'] = new Trie();
            ptr = ptr->child[c-'a'];
        }
        ptr->is_leaf = true;
    }

    bool exists(string word) {
        Trie *ptr = this;
        for(char c : word){
            if(ptr->child[c-'a'] == NULL)
                return false;
            ptr = ptr->child[c-'a'];
        }
        return ptr->is_leaf;
    }

    bool startswith(string p) {
        Trie *ptr = this;
        for(char c : p){
            if(ptr->child[c-'a'] == NULL)
                return false;
            ptr = ptr->child[c-'a'];
        }
        return true;
    }
};

// cleaner
class Trie {
    class TrieNode {
        public:
        TrieNode* child[256];
        int leaf = 0;
        TrieNode() {
            for(int i = 0; i < 256; i++) child[i] = NULL;
        }
    };

    TrieNode *root;
    public:
    Trie() {
        root = new TrieNode();
    }

    void add(string s) {
        TrieNode *ptr = root;
        for(char c : s) {
            if(!ptr->child[c]) ptr->child[c] = new TrieNode();
            ptr = ptr->child[c];
        }
        ptr->leaf++;
    }

    bool exists(string s) {
        TrieNode *ptr = root;
        for(char c : s) {
            if(!ptr->child[c]) return false;
            ptr = ptr->child[c];
        }
        return ptr->leaf;
    }

    bool startswith(string s) {
        TrieNode *ptr = root;
        for(char c : s) {
            if(!ptr->child[c]) return false;
            ptr = ptr->child[c];
        }
        return true;
    }
};
