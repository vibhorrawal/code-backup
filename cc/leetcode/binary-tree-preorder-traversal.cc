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
// recursive
class Solution {
    vector<int> res;
    void pre(TreeNode *root){
        if(root == NULL)
            return;
        res.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        pre(root);
        return res;
    }
};

// O(n) time | O(n) space
// iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            root = st.top(); st.pop();
            if(root == NULL)
                continue;
            res.push_back(root->val);
            st.push(root->right);
            st.push(root->left);
        }
        return res;
    }
};