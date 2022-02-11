// O(N) time and space
// Iterative Inorder traversal
int solve(Tree* root, int t) {
    stack<Tree *> st;
    bool successor = false;
    // st.push(root);
    while(root or st.size()){
        while(root){
            st.push(root);
            root = root->left;
        }
        root = st.top(); st.pop();
        if(successor) 
            return root->val;
        if(root->val == t){
            successor = true;
        }
        root = root->right;
    }
    return -1;
}

// O(logN) time
Tree* successor;
void dfs(Tree *root, int t){
    if(not root) return;
    
    if(root->val > t) {
        successor = root;
        dfs(root->left, t); // if there's more possible answers under as BST
    }
    else {
        dfs(root->right, t); // left side not possible for root->val < t
    }
}

int solve(Tree* root, int t) {
    dfs(root, t);
    return successor->val;
}