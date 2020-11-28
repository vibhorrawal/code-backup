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
// O(n) time | O(logn) space
class Solution {
    int ans;
    void inorder(TreeNode *root, int k, int &count){
        if(not root) return;
        inorder(root->left, k, count);
        if(++count == k) ans = root->val;
        inorder(root->right, k, count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        inorder(root, k, count);
        return ans;
    }
};
