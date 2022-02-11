// O(N) space time
int solve(Tree* root, int a, int b) {
    if(not root) return INT_MIN;
    if(root->val == a || root->val == b)
        return root->val;
    
    int l = solve(root->left, a, b);
    int r = solve(root->right, a, b);
    if(l != INT_MIN & r != INT_MIN) return root->val; // this will be && but kaam chal jaega
    if(l != INT_MIN) return l;
    return r;
}

 
int solve(Tree* root, int a, int b) {
    if(!root) return 0;
    if(root->val == a) return a;
    if(root->val == b) return b;
    int l = solve(root->left, a, b);
    int r = solve(root->right, a, b);
    if(l && r) {
        return root->val;
    }
    return l | r;
}