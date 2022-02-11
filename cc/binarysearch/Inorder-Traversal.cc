// O(N) space time 
// recursive
void dfs(Tree* root, vector<int> &v){
    if(not root) return;
    dfs(root->left, v);
    v.push_back(root->val);
    dfs(root->right, v);
}
vector<int> solve(Tree* root) {
    vector<int> v;
    dfs(root, v);
    return v;
}

// iterative
vector<int> solve(Tree* root) {
    vector<int> v;
    stack<Tree*> st;
    while(root or not st.empty()){
        while(root){
            st.push(root);
            root = root->left;
        }
        root = st.top(); st.pop();
        v.push_back(root->val);
        root = root->right;
    }
    return v;
}