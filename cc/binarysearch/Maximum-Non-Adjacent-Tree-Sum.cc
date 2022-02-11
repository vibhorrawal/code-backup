// O(N) space time
// like knapsack, take curr node or leave it
class Sum {
    public: int included = 0, excluded = 0;
    Sum(int i, int e){included = i, excluded = e;}
};

Sum dfs(Tree *root) {
    if(!root) return Sum(0,0);
    Sum left = dfs(root->left), right = dfs(root->right);
    int incl = root->val + left.excluded + right.excluded;
    int excl = max(left.included, left.excluded) + max(right.included, right.excluded);
    return Sum(incl, excl);
}
int solve(Tree* root) {
    Sum ans = dfs(root);
    return max(ans.included, ans.excluded);
}