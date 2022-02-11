// O(N) space time
int ans;
void dfs(Tree *root){
    if(not root){
        return;
    }
    int v = root->val;
    dfs(root->left);
    dfs(root->right);
    int l = (root->left ? root->left->val : v);
    int r = (root->right ? root->right->val : v);
    if(v == l and v == r){
        ans++;
    }
    else{
        root->val = INT_MIN;
    }
}
int solve(Tree* root) {
    ans = 0;
    dfs(root);
    return ans;
}

// better (not changing I/P)
bool dfs(Tree* root, int &count) {
    if(!root) return true;
    bool left = dfs(root->left, count);
    bool right = dfs(root->right, count);

    int val = root->val;
    int l = root->left ? root->left->val : val;
    int r = root->right ? root->right->val : val;

    if(l == val and r == val and left and right) {
        count++;
        return true;
    }
    return false;
}

int solve(Tree* root) {
    int count = 0;
    dfs(root, count);
    return count;
}