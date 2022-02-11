// O(N) time and O(LogN) space
int ans;
int dfs(Tree *root){
    if(not root) return 0;
    int l = dfs(root->left), r = dfs(root->right);
    if((l % 2 and not (r % 2)) or (r % 2 and not (l % 2))){
        if(root->left and root->right) ans++;
    }
    return root->val + l + r;
}
int solve(Tree* root) {
    ans = 0;
    dfs(root);
    return ans;
}