// O(N) time and space
Tree* solve(Tree* root) {
    if(not root)
        return NULL;
    swap(root->left, root->right);
    solve(root->left);
    solve(root->right);
    return root;
}

// same way, but the above is mentaly clearer
Tree* solve(Tree* root) {
    if(!root) return root;
    Tree *l = root->left;
    root->left = solve(root->right);
    root->right = solve(l);
    return root;
}

// iterative
Tree* solve(Tree* root) {
    queue<Tree*> q;
    q.push(root);
    while(q.size()) {
        auto node = q.front(); q.pop();
        if(!node) continue;
        swap(node->left, node->right);
        q.push(node->left);
        q.push(node->right);
    }
    return root;
}