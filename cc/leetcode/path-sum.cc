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
    bool util(TreeNode* root, int sum){
        if(!root->left && !root->right)
            return sum  - root -> val == 0;

        return (root->left? util(root->left, sum - (root->val)): false) || 
            (root->right? util(root->right, sum - (root->val)): false);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root)
            return util(root, sum);
        else
            return false;
        
    }
};