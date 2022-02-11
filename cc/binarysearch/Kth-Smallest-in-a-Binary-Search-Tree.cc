// O(N) time | O(logN) recursion space (Morris traversal can move it to O(1))
int counter;
int ans;
void dfs(Tree *root, int k){
    if(root == NULL)
        return;
        
    dfs(root->left,k);
    if(counter++ == k) 
        ans = root->val;
    dfs(root->right,k);
}
int solve(Tree* root, int k) {
    counter = 0;
    ans = root->val;
    dfs(root, k);
    return ans;
}