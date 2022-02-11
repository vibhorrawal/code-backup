// O(N) space time
Tree* solve(Tree* root, int target) {
    queue<Tree *> q;
    q.push(root);
    while(q.size()){
        int qs = q.size();
        while(qs--){
            root = q.front(); q.pop();
            if(root->val == target){
                if(not qs) return NULL;
                return q.front();
            }
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
    }
    return NULL;
}