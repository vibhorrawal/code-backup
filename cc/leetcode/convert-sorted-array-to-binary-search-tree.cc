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
    vector<int> v;
    TreeNode* util(int l, int r){
        if(l > r)
            return NULL;
        int m = (l+r)/2;
        TreeNode *mid = new TreeNode(v[m]);
        mid->left = util(l, m-1);
        mid->right = util(m+1, r);
        return mid;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        v = nums;
        return util(0, nums.size()-1);
    }
};
