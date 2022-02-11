// O(N) time and space
vector<int> solve(Tree* root) {
    vector<int> v;
    queue<Tree *> q;
    q.push(root);
    while(not q.empty()){
        root = q.front(); q.pop();
        if(not root) continue;
        v.push_back(root->val);
        q.push(root->left);
        q.push(root->right);
    }
    return v;
}