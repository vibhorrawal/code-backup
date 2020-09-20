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
    struct ans{
        TreeNode *parent;
        int height;
        bool found;
    };
    
    ans find(TreeNode *root, int val, int height, TreeNode *parent){
        if(root == 0){
            return {NULL,height+1,false};
        }
        if(root->val == val)
            return {parent, height, true};
        ans l = find(root->left, val, height+1, root);
        ans r = find(root->right, val, height+1, root);
        if(l.found)
            return l;
        
        if(r.found)
            return r;
        return {NULL, height, false};
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        ans xx = find(root, x, 0, NULL);
        ans yy = find(root, y, 0, NULL);
        return xx.height == yy.height && xx.parent != yy.parent;
    }
};
