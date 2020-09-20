// O(n) time | O(1) space
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
public:
    void flatten(TreeNode* root) {
        TreeNode *leftMostRight, *toReplace;
        while(root){
            toReplace = root->right;
            root->right = root->left;
            root->left = NULL;
            leftMostRight = root;
            while(leftMostRight->right)
                leftMostRight = leftMostRight->right;
            
            leftMostRight->right = toReplace;
            root = root->right;
        }
    }
};
