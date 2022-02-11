// O(N) space time
bool solve(Tree* root0, Tree* root1) {
    if(not root0 and not root1) return true;
    if(not root0 or not root1) return false;
    if(root0->val != root1->val)
        return false;
    
    return 
    (solve(root0->left, root1->left) 
    and solve(root0->right, root1->right))
    or 
    (solve(root0->left, root1->right) 
    and solve(root0->right, root1->left));
}