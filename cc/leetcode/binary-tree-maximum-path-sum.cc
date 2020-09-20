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
    int maxPathWithin;
    int maxPathUtil(TreeNode* root){
        if(root == NULL)
            return 0;
        int leftMax = maxPathUtil(root->left);
        int rightMax = maxPathUtil(root->right);
        maxPathWithin = max(maxPathWithin, leftMax + rightMax + root->val);
        return max(0, max(leftMax, rightMax) + root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPathWithin = INT_MIN;
        maxPathUtil(root);
        return maxPathWithin;
    }
};
