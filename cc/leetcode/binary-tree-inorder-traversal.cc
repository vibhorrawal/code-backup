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

//O(n) time | O(logn) space
// recursive solution
class Solution {
    vector<int> res;
    void util(TreeNode *root){
        if(root == NULL)
            return;
        util(root->left);
        res.push_back(root->val);
        util(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        res.clear();
        util(root);
        return res;
    }
};

// O(n) time | O(n) space
// iterative solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        while(root != NULL || !st.empty()){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

// O(n) time | O(1) space iterative
// morris traversal (tree will be modified)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *prev = NULL, *curr = root, *temp;
        while(curr != NULL){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                prev = curr -> left;
                while(prev->right != NULL)
                    prev = prev->right;
                prev->right = curr;
                temp = curr;
                curr = curr ->left;
                temp->left = NULL;
            }
        }
        return res;
    }
};

// another morris traversal without modifying tree
class Solution {
public:
    // morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *prev = NULL, *curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                res.push_back(curr->val);
                curr = curr->right;
            }
            else{
                prev = curr -> left;
                while(prev->right != NULL && prev->right != curr)
                    prev = prev->right;
                
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr ->left;
                }
                else{
                    prev->right = NULL;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};