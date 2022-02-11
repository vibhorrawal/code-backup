// O(N) time | O(logN) space
Tree* solve(Tree* root, int lo, int hi) {
    if(not root) return root;
    if(root->val < lo) return solve(root->right,lo,hi);
    if(root->val > hi) return solve(root->left,lo,hi);
    
    root->left = solve(root->left, lo, hi);
    root->right = solve(root->right,lo,hi);
    return root;
}