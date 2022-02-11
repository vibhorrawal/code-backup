// O(N) time | O(logN) space

bool is_symm(Tree* root1, Tree* root2){
    if(not root1 and not root2) return true;
    if(not root1 or not root2) return false;

    if(root1->val != root2->val) return false;
    
    return is_symm(root1->left, root2->right) and is_symm(root1->right, root2->left);
}

bool solve(Tree* root) {
    return is_symm(root, root);
}