// O(N) time and recursive stack space
bool isBST(Tree *root, int min, int max){
    if(not root) return true;
    if(not (min < root->val && root->val < max))
        return false;
    
    return isBST(root->left, min, root->val) and 
    isBST(root->right, root->val, max);
}

bool solve(Tree* root) {
    return isBST(root, INT_MIN, INT_MAX);
}