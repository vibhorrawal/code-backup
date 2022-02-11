// O(N) space time
string ans;

void dfs(Tree *root, string s){
    if(not root){
        return;
    }
    s = to_string(root->val) + "," + s;
    if(not root->left and not root->right){
        if(ans == "" or ans > s){
            ans = s;
        }
    }
    dfs(root->left, s);
    dfs(root->right, s);
}
vector<int> solve(Tree* root) {
    ans = ""; 
    dfs(root, "");
    vector<int> res;
    string t;
    stringstream ss(ans);
    while(getline(ss, t, ',')){
        if(t.size()) res.push_back(stoi(t));
    } 
    return res;
}