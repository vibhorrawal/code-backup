// O(n) time | O(logn) space
int countr;
int dfs(Tree *root){
    if(root == NULL) return INT_MIN;
    int l = dfs(root->left);
    int r = dfs(root->right);
    if(root->val >= max(l,r)) countr++;
    return max(root->val, max(l,r));
}
int solve(Tree* root) {
    countr = 0;
    dfs(root);
    return countr;
}
