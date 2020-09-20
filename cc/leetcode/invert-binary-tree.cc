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
    void util(TreeNode* root){
        if(root == NULL)
            return;
        TreeNode* left = (root->left);
        TreeNode* right = (root->right);
        root->left = right;
        root->right = left;
        util(root->left);
        util(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        util(root);
        return root;
    }
};
