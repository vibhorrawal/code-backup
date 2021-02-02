// O(N) time and space BFS
int solve(Tree* root) {
    queue<pair<Tree *, int>> q;
    q.push({root, 0});
    set<int> level;
    while(q.size()){
        auto it = q.front(); q.pop();
        if(it.first == nullptr) continue;
        level.insert(it.second);
        q.push({it.first->left, it.second - 1});
        q.push({it.first->right, it.second + 1});
    }
    return level.size();
}

// O(N) time | O(logN) space DFS
int L, R;

void dfs(Tree *root, int level){
    if(not root) return;
    L = min(L, level);
    R = max(R, level);
    dfs(root->left, level-1);
    dfs(root->right, level+1);
}
int solve(Tree* root) {
    L = INT_MAX;
    R = INT_MIN;
    dfs(root, 0);
    return R - L + 1;
}
