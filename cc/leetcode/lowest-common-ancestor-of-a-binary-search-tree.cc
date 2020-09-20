/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* dfs(TreeNode* root, int l, int r){
        if(root == NULL)
            return NULL;
        if(l <= root->val && root-> val <= r)
            return root;
        if(root-> val > r)
            return dfs(root->left, l, r);
        else
            return dfs(root->right, l, r);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q-> val)
            return dfs(root, p->val, q->val);
        else
            return dfs(root, q->val, p->val);
    }
};
