// O(N ^ 2) time and space
int height(Tree *root){
    if(not root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(Tree *root){
    if(not root) return true;
    
    int l = height(root->left);
    int r = height(root->right);
    if(abs(r - l) <= 1) return isBalanced(root->left) and isBalanced(root->right);
    return false;
}
bool solve(Tree* root) {
    return isBalanced(root);
}

// doing the above work in one function call
// O(N) time
bool ans;

int dfs(Tree* root, int level){
    if(not root) return 0;
    
    int l = dfs(root->left, level+1);
    int r = dfs(root->right, level+1);
    
    if(abs(r-l) > 1){
        ans = false;
        return 0;
    }
    return 1+max(l,r); // height
}
bool solve(Tree* root) {
    ans = true;
    dfs(root,0); 
    return ans;
}

// cleaner
int dfs(Tree* root, bool &ans) {
    // return height of this node
    if(!root) return 0;
    int l = dfs(root->left, ans);
    int r = dfs(root->right, ans);
    if(!ans) return -1; // early return
    if(abs(l - r) > 1) {
        ans = false;
        return -1;
    }
    return max(l, r) + 1;
}

bool solve(Tree* root) {
    bool ans = true;
    dfs(root, ans);
    return ans;
}