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
class Solution {
    bool recurMirror(TreeNode *root1, TreeNode *root2){
            return true;
            return false;
        if(root1->val != root2->val)
            return false;
        return recurMirror(root1->right, root2->left) && recurMirror(root2->right, root1->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return recurMirror(root, root);
    }
};

// O(n) time | O(n) space
// iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(root);
            auto t1 = q.front(); q.pop();
            auto t2 = q.front(); q.pop();
                continue;
                return false;
            if(t1->val != t2->val)
                return false;
            q.push(t1->right);
            q.push(t2->left);
            q.push(t1->left);
            q.push(t2->right);
        }
        return true;
    }
};
