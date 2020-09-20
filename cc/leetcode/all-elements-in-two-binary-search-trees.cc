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
    void inorder(TreeNode* root, vector<int> &res){
        if(root == NULL)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> getSorted(TreeNode* root){
        vector<int> res;
        inorder(root, res);
        return res;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> r1 = getSorted(root1);
        vector<int> r2 = getSorted(root2);
        r1.push_back(INT_MAX);
        r2.push_back(INT_MAX);
        vector<int> res;
        
        int i = 0, j = 0;
        while(i < r1.size() && j < r2.size()){
            if(r1[i] < r2[j])
                res.push_back(r1[i++]);
            else
                res.push_back(r2[j++]);
        }
        res.erase(res.begin() + res.size()-1);
        return res;
    }
};
