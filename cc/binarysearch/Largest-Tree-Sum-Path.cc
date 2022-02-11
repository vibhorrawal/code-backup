// O(N) space time
int sum;

int dfs(Tree *root){
    if(not root) return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    sum = max(sum, l + r + root->val);
    return max(0, max(l,r) + root->val);
}
int solve(Tree* root) {
    sum = 0;
    dfs(root);
    return sum;
}

// cleaner
struct Path {
    int terminating, non_terminating; // terminating at root, a path passing through root (downwards U)
};

Path dfs(Tree *root) {
    if(!root) return {0,0};
    Path l = dfs(root->left), r = dfs(root->right);
    int non_terminating = 
    max({l.non_terminating, r.non_terminating, l.terminating + root->val + r.terminating});
    int terminating = max(root->val, root->val + max(l.terminating, r.terminating));
    return {terminating, non_terminating};
}
int solve(Tree* root) {
    Path ans = dfs(root);
    return max(ans.terminating, ans.non_terminating);
}