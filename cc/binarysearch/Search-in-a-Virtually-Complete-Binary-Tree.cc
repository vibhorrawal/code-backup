// O(N) time and O(logN) space
bool dfs(Tree *root, int val){
    if(not root) return false;
    if(root->val == val) return true;
    return dfs(root->left, val) or dfs(root->right, val);
}
bool solve(Tree* root, int target) {
    return dfs(root, target);
}

// h -> height of tree

// O(h) time | O(h) recursion stack space
bool solve(Tree *root, int target, int bitpos) {
    if(root == nullptr) return false;
    if(root->val == target) return true;
    if(target & (1<<(bitpos))) return solve(root->right, target, bitpos - 1);
    return solve(root->left, target, bitpos - 1);
}
bool solve(Tree* root, int target) {
    if(root == nullptr) return false;
    int bitpos = 0;
    while(target >= (1<<bitpos)) bitpos++;
    bitpos--;
    return solve(root, target, bitpos-1);
}

// cleaner O(h) time || O(h) space
const int LEFT = 0, RIGHT = 1;
vector<int> getPathFromTargetToSource(int node) {
    vector<int> res;
    while(node > 1) {
        if(node & 1) res.push_back(RIGHT);
        else res.push_back(LEFT);
        node /= 2;
    }
    return res;
}
bool solve(Tree* root, int target) {
    // from target to source, if target -> even (go left) if target -> odd (go right)
    if(target < 1) return false;
    vector<int> path = getPathFromTargetToSource(target);
    reverse(path.begin(), path.end());
    for(int dir : path) {
        if(!root) return false;
        if(dir == LEFT) root = root->left;
        else root = root->right;
    }
    return root != nullptr;
}