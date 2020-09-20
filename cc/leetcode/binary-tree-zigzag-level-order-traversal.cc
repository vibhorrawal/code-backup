// O(n) time and space
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        bool rvrse = true;
        while(q.size()){
            int sz = q.size();
            vector<int> temp;
            while(sz--){
                auto it = q.front();
                q.pop();
                if(it == NULL)
                    continue;
                temp.push_back(it->val);
                q.push(it->left);
                q.push(it->right);
            }
            rvrse = !rvrse;
            if(rvrse)
                reverse(temp.begin(), temp.end());
            if(temp.size())
                res.push_back(temp);
        }
        return res;
    }
};