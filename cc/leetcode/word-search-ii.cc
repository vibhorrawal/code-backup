// O(m * n * longest_string * sizeOfDict) time | O(sizeOfDict * longest_string) space
const int DEL = 96;
const int SIZE = 'z' - DEL + 1; // ` --> 96 (will be using to mark visited)
struct TrieNode {
    TrieNode *child[SIZE];
    int isEndNode;
    
    TrieNode(){
        for(int i = 0; i < SIZE; i++)
            child[i] = NULL;
        isEndNode = -1;
    }
};
class Solution {
    vector<vector<char>> mat;
    vector<int> res;
    TrieNode *root;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    
    void insert(TrieNode *root, string s, int pos){
        for(int i = 0; i < s.size(); i++){
            int ind = s[i] - DEL;
            if(!root->child[ind])
                root->child[ind] = new TrieNode();
            root = root->child[ind];
        }
        root->isEndNode = pos;
    }

    void dfs(int x, int y, TrieNode *node){
        if(node->isEndNode != -1){
            res.push_back(node->isEndNode);
            node->isEndNode = -1;
        }
        
        for(int i = 0; i < 4; i++){
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi < 0 || xi >= mat.size() || yi < 0 || yi >= mat[0].size())
                continue;
            int ind = mat[xi][yi] - DEL;
            if(node->child[ind] != NULL){
                char temp = mat[xi][yi];
                mat[xi][yi] = DEL;
                dfs(xi,yi,node->child[ind]);
                mat[xi][yi] = temp;
                // cout<<temp<<' ';
            }
        }
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        mat = board;
        root = new TrieNode();
        int l = 0;
        for(string word: words)
            insert(root, word, l++);
        
        for(int xi = 0; xi < mat.size(); xi++){
            for(int yi = 0; yi < mat[0].size(); yi++){
                int ind = mat[xi][yi] - DEL;
                if(root->child[ind] != NULL){
                    char temp = mat[xi][yi];
                    mat[xi][yi] = DEL;
                    dfs(xi,yi,root->child[ind]);
                    mat[xi][yi] = temp;
                    // cout<<endl<<temp<< ' ';
                }
            }
        }
        vector<string> ans;
        for(int i: res)
            ans.push_back(words[i]);
        return ans;
    }
};