// O(n) time | O(n) space
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct amount{
        int selfLoot;
        int childLoot;
    };
    
    amount utilDfs(TreeNode *root){
        if(root == NULL)
            return {0,0};
        
        amount l = utilDfs(root->left);
        amount r = utilDfs(root->right);
        amount me = {0,0};
        me.selfLoot = max(l.childLoot + r.childLoot + root->val, l.selfLoot + r.selfLoot);
        me.childLoot = max(l.selfLoot + r.selfLoot, l.childLoot + r.childLoot);
        return me;
    }
public:
    int rob(TreeNode* root) {
        amount it = utilDfs(root);
        return max(it.selfLoot, it.childLoot);
    }
};
