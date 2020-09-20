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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int d = 1;
        while(q.size()){
            int qs = q.size();
            while(qs--){
                auto it = q.front();
                q.pop();
                if(!it->left && !it->right)
                    return d;
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            }
            d++;
        }
        return d;
    }
};