// O(N) space time using queue
vector<int> solve(Tree* root) {
    vector<int> res;
    queue<Tree *> q;
    q.push(root);
    bool revert = false;
    while(q.size()){
        vector<int> t;
        int qs = q.size();
        while(qs--){
            root = q.front(); q.pop();
            if(not root) continue;
            t.push_back(root->val);
            q.push(root->left);
            q.push(root->right);
        }
        if(revert) reverse(t.begin(), t.end());
        revert = not revert;
        for(int x : t) res.push_back(x);
    }
    return res;
}

// using stack
// nice trick but not useful anywhere else
vector<int> solve(Tree* root) {
    stack<Tree *> s1, s2;
    s1.push(root);
    vector<int> res;
    while(s1.size() or s2.size()) {
        while(s1.size()) {
            root = s1.top(); s1.pop();
            if(!root) continue;
            res.push_back(root->val);
            s2.push(root->left);
            s2.push(root->right);
        }
        while(s2.size()) {
            root = s2.top(); s2.pop();
            if(!root) continue;
            res.push_back(root->val);
            s1.push(root->right);
            s1.push(root->left);
        }
    }
    return res;
}