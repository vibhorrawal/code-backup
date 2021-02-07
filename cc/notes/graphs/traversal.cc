// BFS
// O(V + E) time | O(V) space
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode *> q;
    vector<vector<int>> res;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        vector<int> level;
        while(sz--){
            auto node = q.front(); q.pop();
            if(node == NULL)
                continue;
            level.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        if(level.size()) res.push_back(level);
    }
    return res;
}


// DFS
// O(V + E) time | O(depth) stack space
void dfs(TreeNode *root, int val){
    if(root == NULL){
        return;
    }
    dfs(root->left, val+1);
    dfs(root->right, val+1);
}
