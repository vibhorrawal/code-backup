// O(N) time and space
int solve(Tree* root) {
    if (not root) return 0;
    long ans = 0;
    queue<pair<Tree*, long>> q;
    q.push({root, 0});
    while (q.size()) {
        long smallest_id = LONG_MAX, largest_id = LONG_MIN;
        int qs = q.size();
        while (qs--) {
            auto it = q.front();
            q.pop();
            root = it.first;
            long id = it.second;
            smallest_id = min(smallest_id, id);
            largest_id = max(largest_id, id);
            if (root->left) q.push({root->left, 2 * id + 1});
            if (root->right) q.push({root->right, 2 * id + 2});
        }
        ans = max(ans, largest_id - smallest_id + 1);
    }
    return ans;
}