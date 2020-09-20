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

// O(n) time | O(logn) avg space
// recursive
class Solution {
    vector<int> res;
    void post(TreeNode *root){
        if(root == NULL)
            return;
        post(root->left);
        post(root->right);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        post(root);
        return res;
    }
};

// O(n) time | O(n) space
// iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            root = st.top(); 
            st.pop();
            if(root == NULL)
                continue;
            res.push_back(root->val);
            st.push(root->left);
            st.push(root->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};