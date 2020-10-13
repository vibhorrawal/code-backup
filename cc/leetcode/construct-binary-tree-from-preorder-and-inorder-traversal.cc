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

// O(n ^ 2) time | O(logn) space
class Solution {
    int it;
    vector<int> inorder;
    int findIdx(int val, int start, int end){
        return distance(inorder.begin(),
                        find(inorder.begin() + start, inorder.begin() + end, val));
    }
    TreeNode *build(vector<int> &preorder, int start, int end){
        if(start > end) return NULL;
        int val = preorder[it++];
        TreeNode *root = new TreeNode(val);
        int ind = findIdx(val, start, end);
        root->left = build(preorder, start, ind-1);
        root->right = build(preorder, ind+1, end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder1) {
        it = 0;
        inorder = inorder1;
        return build(preorder, 0, inorder.size()-1);
    }
};

// as duplicates dont exist, use a map to find index
// O(nlogn) time | O(n) space
class Solution {
    int it;
    map<int,int> idx;
    TreeNode *build(vector<int> &preorder, int start, int end){
        if(start > end) return NULL;
        int val = preorder[it++];
        TreeNode *root = new TreeNode(val);
        int ind = idx[val];
        root->left = build(preorder, start, ind-1);
        root->right = build(preorder, ind+1, end);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        idx.clear(); it = 0;
        for(int i = 0; i < inorder.size(); i++)
            idx[inorder[i]] = i;
        return build(preorder, 0, inorder.size()-1);
    }
};


// iterative
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        stack<TreeNode *> st;
        TreeNode *node = new TreeNode(preorder[0]);
        TreeNode *head = node;
        st.push(head);
        map<int,int> ind;
        for(int i = 0; i < inorder.size(); i++)
            ind[inorder[i]] = i;
        for(int i = 1; i < preorder.size(); i++){
            int val = preorder[i];
            node = new TreeNode(val);
            if(ind[val] < ind[st.top()->val]) st.top()->left = node;
            else{
                TreeNode *parent;
                while(!st.empty() && ind[st.top()->val] < ind[val]){
                    parent = st.top();
                    st.pop();
                }
                parent->right = node;
            }
            st.push(node);
        }
        return head;
    }
};
