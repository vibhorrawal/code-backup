// O(N^2) space time
bool check(Tree *t1, Tree *t2){
    if(not t1 and not t2)
        return true;
    if(not t1 or not t2)
        return false;
    
    return t1->val == t2->val and check(t1->left, t2->left) and check(t1->right, t2->right);
}
bool solve(Tree* root, Tree* target) {
    if(not root)
        return not target;
    if(check(root, target))
        return true;
    
    return solve(root->left, target) or solve(root->right, target);
}

// O(N) time; well string comparison can get O(N) but you can use hashing instead
bool possible;
string dfs(Tree *root, string &target) {
    if(!root) {
        return string(1, 255);
    }
    string l = dfs(root->left, target);
    string r = dfs(root->right, target);
    string s =  l + to_string(root->val) + r;
    if(l == target or r == target or s == target) possible = true;
    return s;
}

string tt(Tree *root) {
    if(!root) {
        return string(1, 255);
    }
    string l = tt(root->left);
    string r = tt(root->right);
    return l + to_string(root->val) + r;
}

bool solve(Tree* root, Tree* target) {
    possible = false;
    string t = tt(target);
    dfs(root, t);
    return possible;
}