// O(n) time | O(n) space
class Solution {
    struct Trie{
        struct Trie *child[2];
        Trie(){
            child[0] = child[1] = NULL;
        }
    };
    void insert(Trie *root, int num){
        for(int i = 31; i >= 0; i--){
            int ind = (num>>i) & 1;
            if(root->child[ind] == NULL)
                root->child[ind] = new Trie();
            root = root->child[ind];
        }
    }
    int xor_find(Trie *root, int num){
        int val = 0;
        for(int i = 31; i >= 0; i--){
            int ind = ((num>>i) ^ 1) & 1;
            if(root->child[ind]){
                val |= (1<<i);
                root = root->child[ind];
            }
            else{
                root = root->child[(ind ^ 1) & 1];
            }
        }
        return val;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        for(int num: nums)
            insert(root, num);
        int ans = 0;
        for(int num: nums){
            ans = max(ans, xor_find(root, num));
        }
        return ans;
    }
};
