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
// O(n) time | O(n) space
// iterative
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        q.push(root);
            int sz = q.size();
            vector<int> level;
            while(sz--){
                auto node = q.front(); q.pop();
                if(node == NULL)
                    continue;
                level.push_back(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if(level.size()) res.push_back(level);
        }
        return res;
    }
};

// O(n) time | O(log(n)) space
// recursive
class Solution {
    vector<vector<int>> res;
    void dfs(TreeNode *root, int level){
        if(root == NULL)
            return;
        auto it = res.begin() + level;
        if(it == res.end()){
            vector<int> temp;
            temp.push_back(root->val);
            res.push_back(temp);
        }
        else{
            res[level].push_back(root->val);
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};
