// trees are ismorphic if they have a same shape irrespective of the node values

// assume from ./find-root.cc
vector<int> find_tree_centers(vector<vector<int>>);

// assume from ./root-tree.cc
TreeNode *root_tree(vvi , int);

string encode(TreeNode *root){
    if(not root) return "";
    vector<string> li;
    for(TreeNode child : root->child){
        li.push_back(encode(child));
    }
    sort(li.begin(), li.end());
    string res;
    for(string s : res) res += s;
    return "(" + res + ")";
}

bool are_tree_isomorphic(vvi tree1, vvi tree2){
    if(tree1.empty() or tree2.empty())
        return tree1.empty() and tree2.empty();

    vi centres1 = find_tree_centers(tree1);
    vi centres2 = find_tree_centers(tree2);

    TreeNode *root = root_tree(tree1, centers1[0]);
    string encode1 = encode(root);

    for(int center : centres2){
        root = root_tree(tree2, center);
        if(encode(root) == encode1)
            return true;
    }
    return false;
}
