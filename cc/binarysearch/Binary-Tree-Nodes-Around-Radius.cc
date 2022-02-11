// O(N) time | O(N) recursive stack space

void dfs(Tree *root, int radius, vector<int> &res){
    if(root == nullptr) return;
    if(radius == 0) {
        res.push_back(root->val);
        return;
    }
    dfs(root->left, radius-1, res);
    dfs(root->right, radius-1, res);
}
int ancestor(Tree *root, int target, int radius, vector<int> &res){
    if(root == nullptr) return -1;
    if(root->val == target){
        dfs(root, radius, res);
        return 0;
    }

    int l = 1 + ancestor(root->left, target, radius, res);
    int r = 1 + ancestor(root->right, target, radius, res);

    if(l){
        if(l == radius) res.push_back(root->val);
        dfs(root->right, radius - l - 1, res);
        return l;
    }

    if(r){
        if(r == radius) res.push_back(root->val);
        dfs(root->left, radius - r - 1, res);
        return r;
    }
    return -1;
}
vector<int> solve(Tree* root, int target, int radius) {
    vector<int> res;
    ancestor(root, target, radius, res);
    sort(res.begin(), res.end());
    return res;
}