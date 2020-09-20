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
    vector<vector<int>> res;
    void pathUtil(TreeNode *root, vector<int> path, int sum){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            if(sum - root->val == 0){
                path.push_back(root->val);
                res.push_back(path);
            }
            return;
        }
        int val = root->val;
        path.push_back(val);
        pathUtil(root->left, path, sum - val);
        pathUtil(root->right, path, sum - val);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> temp;
        pathUtil(root, temp, sum);
        return res;
    }
};
